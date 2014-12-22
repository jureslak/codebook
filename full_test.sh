#!/bin/bash

TESTDIR='./test'

# colors
BW='\x1b[37;1m'  # bold white
BR='\x1b[31;1m'  # bold red
BG='\x1b[32;1m'  # bold red
NC='\x1b[37;0m'  # no color

cwd=${PWD##*/}
if [ "$cwd" != "codebook" ]; then
    echo -e "${BR}Run from root directory of this project!${NC}"
    exit 1
fi

echo -e "${BW}Looking for tests ... ${NC}"
for filename in $(find -regex '\./implementacija/\([^/]+/\)+[^.][^/]+\.\(h\)')
do
    testname="$(dirname $filename)/$(basename $filename .h)_test.cpp"
    if [ ! -f $testname ]; then
        echo -e "${BR}Filename: ${NC}$filename${BR} does not have a test!"
        echo -e "Make sure file ${NC}$testname${BR} exists!${NC}"
        exit 2
    fi
done

cd $TESTDIR   # CWD CHANGES
if [ $? -ne 0 ]; then
    echo -e "${BR}Error: couldnt access ${TESTDIR}!${NC}"
    exit 3
fi

echo -e "${BW}Compiling tests ...${NC}"
make all -j8  # your number of processors
if [ $? -ne 0 ]; then
    echo -e "${BR}Error: compilation failed!.${NC}"
    exit 4
fi

filter=${1:-"*"} # default test filter

echo -e "${BW}Running tests ...${NC}"
./run_tests --gtest_filter="$filter"
if [ $? -ne 0 ]; then
    echo -e "${BR}Error: there are failed tests!${NC}"
    exit 5
fi

echo -e "${BW}Checking code style ...${NC}"
cd ..
ERRORCODE=0
for filename in $(find -regex '\./implementacija/\([^/]+/\)+[^.][^/]+\.\(cpp\|cc\|c\|h\)')
do
    python2 "test/cpplint.py" "--filter=-legal,-build/include,-runtime/reference" "--linelength=100" "$filename"
    ERRORCODE=$(($ERRORCODE+$?))
done
if [ $ERRORCODE -ne 0 ]; then
    echo -e "${BR}Error: there were sytle mistakes!${NC}"
    echo "(If you feel errors are unjust, edit this file and add exceptions.)"
    exit 6
fi

echo -e "${BG}Done! All looks great!${NC}"

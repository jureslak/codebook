#!/bin/bash

TESTDIR='./test'

# colors
BW='\x1b[37;1m'  # bold white
BR='\x1b[31;1m'  # bold red
BG='\x1b[32;1m'  # bold red
NC='\x1b[37;0m'  # no color

cd $TESTDIR
if [ $? -ne 0 ]; then
    echo -e "${BR}Error: couldnt access ${TESTDIR}!${NC}"
    exit
fi

echo -e "${BW}Compiling tests ...${NC}"
make all -j8  # your number of processors
if [ $? -ne 0 ]; then
    echo -e "${BR}Error: compilation failed! ${TESTDIR}.${NC}"
    exit
fi

echo -e "${BW}Running tests ...${NC}"
./run_tests
if [ $? -ne 0 ]; then
    echo -e "${BR}Error: there are failed tests!${NC}"
    exit
fi

echo -e "${BW}Checking code style ...${NC}"
cd ..
ERRORCODE=0
for filename in $(find -regex '\./implementacija/\([^/]+/\)+[^.][^/]+\.\(h\|cpp\|cc\|c\)')
do
    python2 "test/cpplint.py" "--filter=-legal,-build/include"  "$filename"
#     echo "exit: $?"
    ERRORCODE=$(($ERRORCODE+$?))
done
if [ $ERRORCODE -ne 0 ]; then
    echo -e "${BR}Error: there were sytle mistakes!${NC}"
    echo "(If you feel errors are unjust, edit this file and add exceptions.)"
    exit
fi

echo -e "${BG}Done! All looks great!${NC}"

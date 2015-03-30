#!/bin/bash

TESTDIR='./test'

# colors
BW='\x1b[37;1m'  # bold white
BR='\x1b[31;1m'  # bold red
BG='\x1b[32;1m'  # bold red
NC='\x1b[37;0m'  # no color

FILTER="*" # default test filter
STYLECHECK=true

while [[ $# > 0 ]]; do
key="$1"
case $key in
    -f|--filter)
    FILTER="$2"
    shift
    ;;
    -n|--nostylecheck)
    STYLECHECK=false
    ;;
    *)
            # unknown option
    ;;
esac
shift
done

cwd=${PWD##*/}
if [ "$cwd" != "codebook" ]; then
    echo -e "${BR}Run from root directory of this project!${NC}"
    exit 1
fi

echo -e "${BW}Looking for tests ... ${NC}"
for filename in $(find -regex '\./implementacija/\([^/]+/\)+[^.][^/]+\.\(h\)')
do
    if [[ "$filename" == *_util.h ]]; then continue; fi
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
make all -j8 > /dev/null # your number of processors in j8
if [ $? -ne 0 ]; then
    echo -e "${BR}Error: compilation failed!.${NC}"
    exit 4
fi


echo -e "${BW}Running tests ...${NC}"
./run_tests --gtest_filter="$FILTER"
if [ $? -ne 0 ]; then
    echo -e "${BR}Error: there are failed tests!${NC}"
    exit 5
fi

if [ "$STYLECHECK" = "true" ]; then
    echo -e "${BW}Checking code style ...${NC}"
    cd ..
    ERRORCODE=0
    for filename in $(find -regex '\./implementacija/\([^/]+/\)+[^.][^/]+\.\(cpp\|cc\|c\|h\)')
    do
        dir=`mktemp -d`
        python2 "test/cpplint.py" \
          "--filter=-legal,-build/include,-runtime/reference,-runtime/threadsafe_fn,-runtime/explicit,-readability/streams" \
          "--linelength=100" \
          "$filename" 2> "$dir/out"
        exit_code=$?
        if [ $exit_code -ne 0 ]; then
            cat "$dir/out"
        fi
        rm -r $dir
        ERRORCODE=$(($ERRORCODE+$exit_code))
    done
    if [ $ERRORCODE -ne 0 ]; then
        echo -e "${BR}Error: there were sytle mistakes!${NC}"
        echo "(If you feel errors are unjust, edit this file and add exceptions (ln. 78).)"
        exit 6
    fi
fi

echo -e "${BG}Done! All looks great!${NC}"

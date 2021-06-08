#!/bin/bash

set -u
# commands to run KLEE and validate
homeDir="/home/namrata/"
toolPath="/home/namrata/klee/tools/klee"
kleeLibPath="/home/namrata/klee/lib/Core"
kleeIncludePath="/home/namrata/klee/include/"
cppLibPath="/home/namrata/libc++-install-10/include/c++/v1/"

python3 $toolPath/run.py 2 $toolPath

if [ $? -eq 0 ]; then
    echo ""
else
    echo "Error while fetching results."
    printf "\n"
    echo "Process terminated."
    exit 1
fi

#chmod -R 777 $toolPath

#sleep 1
echo "Result:"
echo "$(<$toolPath/result_new.txt)"
if [ $? -eq 0 ]; then
    echo ""
else
    echo "Error in fetching results."
    exit 1
fi

echo "TestCases:"
printf "\n"

echo "$(<$toolPath/alltestcases.txt)"
if [ $? -eq 0 ]; then
    echo ""
else
    echo "Error in fetching testcases."
    exit 1
fi

rm -f test* alltest* result* *.bc *.ll *.sol contract.txt names.txt logFile.txt properties.txt
rm -f error*
#awk '/^KLEE:/ {print}' result.txt



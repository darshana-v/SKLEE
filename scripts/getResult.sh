#!/bin/bash

set -u
# commands to run KLEE and validate
homeDir="{PWD}"
toolPath="$homeDir/klee/tools/klee"
kleeLibPath="$homeDir/klee/lib/Core"
kleeIncludePath="$homeDir/klee/include/"
cppLibPath="$homeDir/libc++-install-10/include/c++/v1/"

# Translating test cases to human-readable format

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



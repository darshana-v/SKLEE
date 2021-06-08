#!/bin/bash
#set -e
set -u
input=$1
#convertedInput=${input::-4}
convertedInput="convertedFile"
cppInput="$convertedInput.cpp"
bcInput="$convertedInput.bc"
llInput="$convertedInput.ll"
# commands to run KLEE and validate
homeDir="/home/namrata/"
toolPath="/home/namrata/klee/tools/klee"
kleeLibPath="/home/namrata/klee/lib/Core"
kleeIncludePath="/home/namrata/klee/include/"
cppLibPath="/home/namrata/libc++-install-10/include/c++/v1/"
#cd ~/Desktop/project/verifTool/
#echo "Converting Contract code to LLVM bitcode..."

#flex -o $toolPath/lexer.c -l $toolPath/lexer.l &>logFile.txt
#bison -vd -o $toolPath/grammar.c $toolPath/grammar2Copy.y &> logFile.txt

#echo $input
#echo $convertedInput
#g++ -w -Wno-write-strings $kleeLibPath/defs.cpp $toolPath/lexer.c $toolPath/grammar.c -o $toolPath/verify -ll &> logFile.txt

$toolPath/verify < $toolPath/$input &> logFile.txt
if [ $? -eq 0 ]; then
    echo "Conversion to intermediate code complete."
else
    echo "Solidity syntax/version error: could not convert contract file."
    printf "\n"
    echo "Process terminated."
    exit 1
fi


/usr/lib/llvm-10/bin/clang++ -O0 -Wno-everything -std=c++11 -I $cppLibPath -nostdinc++ -fsanitize=signed-integer-overflow -fsanitize=unsigned-integer-overflow -I $kleeIncludePath -emit-llvm -c -g $toolPath/$cppInput &> logFile.txt

if [ $? -eq 0 ]; then
    echo "Conversion to LLVM Bitcode complete."
else
    echo "Error in bitcode file, needs refinement."
    printf "\n"
    echo "Process terminated."
    exit 1
fi

/usr/lib/llvm-10/bin/llvm-dis $toolPath/$bcInput

#chmod -R 777 $toolPath

$homeDir/build/bin/klee --libc=uclibc -libcxx -posix-runtime --max-instructions=2000000 --warnings-only-to-file $toolPath/$llInput


if [ $? -eq 0 ]; then
    echo "KLEE run complete."
else
    echo "Error while running KLEE: timeout or SIGSEV."
    printf "\n"
    echo "Process terminated."
    exit 1
fi

#chmod -R 777 $toolPath

#printf "\n"

#echo "Properties violated in result.txt"
#echo "Validating on private Ethereum Blockchain..."

#printf "\n"
#if [ $1 == "BPUseNet.sol" ]
#then
#	$homeDir/build/bin/ktest-tool $toolPath/klee-last/error-MultOverflow000001.ktest &> error-MultOverflow.txt
#	$homeDir/build/bin/ktest-tool $toolPath/klee-last/test000002.ktest &> testcase1.txt
#	$homeDir/build/bin/ktest-tool $toolPath/klee-last/test000003.ktest &> testcase2.txt
#else
#	$homeDir/build/bin/ktest-tool $toolPath/klee-last/test000001.ktest &> testcase1.txt
#	$homeDir/build/bin/ktest-tool $toolPath/klee-last/test000002.ktest &> testcase2.txt
#fi	

#../build/bin/ktest-tool klee-last/test000002.ktest &> testcase2.txt


python3 $toolPath/run.py 1 $toolPath

if [ $? -eq 0 ]; then
    echo ""
else
    echo "Error while generating testcases."
    printf "\n"
    echo "Process terminated."
    exit 1
fi



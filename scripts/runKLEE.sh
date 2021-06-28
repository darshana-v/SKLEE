#!/bin/bash
#set -e
set -u
input="Voting.sol" #hardcoded

#input=$1 #use with compile.php
#convertedInput=${input::-4}
convertedInput="convertedFile"
cppInput="$convertedInput.cpp"
bcInput="$convertedInput.bc"
llInput="$convertedInput.ll"


homeDir="../"
toolPath="../klee/tools/klee"
kleeLibPath="../klee/lib/Core"
kleeIncludePath="../klee/include/"
cppLibPath="../include/libc++-install-10/include/c++/v1/"
outpath="../output"
cpp_path="../output/convertedFile.cpp"

# Lexer and Grammar compilation

flex -o $toolPath/lexer.c -l $toolPath/lexer.l &>logFile.txt
echo "Lexer compilation finished."
bison -vd -o $toolPath/grammar.c $toolPath/grammar.y >> logFile.txt
echo "Grammar compilation finished."

# Conversion of Solidity to C++.

g++ -w -Wno-write-strings $kleeLibPath/defs.cpp $toolPath/lexer.c $toolPath/grammar.c -o $toolPath/verify -ll -std=c++11 #-ll &> logFile.txt
echo "Executable genration finished"

# If this does doesn't work, uncomment this 
# chmod +x $toolPath/verify

$toolPath/verify < $toolPath/$input >> logFile.txt

printf "\n"
if [ $? -eq 0 ]; then
    echo "Conversion to intermediate code complete."
else
    echo "Solidity syntax/version error: could not convert contract file."
    printf "\n"
    echo "Process terminated."
    exit 1
fi

echo "LLVM BitCode Generation"

# clang supposed to be in the path, if not then add in the corresponding path
#/usr/local/opt/llvm/bin/clang++ -O0 -Wno-everything -std=c++11 -I $cppLibPath -nostdinc++ -fsanitize=signed-integer-overflow -fsanitize=unsigned-integer-overflow -I $kleeIncludePath -emit-llvm -c -g $toolPath/$cppInput >> logFile.txt
clang++ -O0 -Wno-everything -std=c++11 -I $cppLibPath -nostdinc++ -fsanitize=signed-integer-overflow -fsanitize=unsigned-integer-overflow -I $kleeIncludePath -emit-llvm -c -g $cpp_path >> logFile.txt

if [ $? -eq 0 ]; then
    echo "Conversion to LLVM Bitcode complete."
else
    echo "Error in bitcode file, needs refinement."
    printf "\n"
    echo "Process terminated."
    exit 1
fi
mv convertedFile.bc ../output/

chmod +x ../include/llvm-10/bin/llvm-dis

../include/llvm-10/bin/llvm-dis $outpath/$bcInput -o $outpath/$llInput

#/usr/local/opt/llvm/bin/llvm-dis $outpath/$bcInput -o $outpath/$llInput

#chmod -R 777 $toolPath

chmod +x ../build/bin/klee

# TODO: Klee needs to be rebuild: URGENT

#/usr/local/opt/klee/bin/klee --libc=uclibc -libcxx -posix-runtime --max-instructions=2000000 --warnings-only-to-file $outpath/$llInput
../build/bin/klee --libc=uclibc -libcxx -posix-runtime --max-instructions=2000000 --warnings-only-to-file $outpath/$llInput


if [ $? -eq 0 ]; then
    echo "KLEE run complete.\nKLEE Test cases generated"
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



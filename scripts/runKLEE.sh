#!/bin/bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"

input=$1
convertedInput=${input::-4}
cppInput="$convertedInput.cpp"
bcInput="$convertedInput.bc"
llInput="$convertedInput.ll"

toolPath="$ROOT_DIR/klee/tools/klee"
kleeLibPath="$ROOT_DIR/klee/lib/Core"
kleeIncludePath="$ROOT_DIR/klee/include"
cppLibPath="$ROOT_DIR/libc++-install-10/include/c++/v1/"

echo "[1/5] Building transpiler..."
flex -o "$toolPath/lexer.c" -l "$toolPath/lexer.l" 2>>logFile.txt
bison -vd -o "$toolPath/grammar.c" "$toolPath/grammar.y" 2>>logFile.txt
g++ -w -Wno-write-strings "$kleeLibPath/defs.cpp" "$toolPath/lexer.c" "$toolPath/grammar.c" -o "$toolPath/verify" -ll >>logFile.txt 2>&1

echo "[2/5] Transpiling Solidity to C++..."
if ! "$toolPath/verify" < "$toolPath/$input" >>logFile.txt; then
    echo "ERROR: Solidity syntax/version error: could not convert contract file."
    exit 1
fi
echo "  -> $cppInput"

echo "[3/5] Compiling to LLVM bitcode..."
if ! clang++ -O0 -Wno-everything -std=c++11 -I "$cppLibPath" -nostdinc++ \
    -fsanitize=signed-integer-overflow -fsanitize=unsigned-integer-overflow \
    -I "$kleeIncludePath" -emit-llvm -c -g "$toolPath/$cppInput" 2>logFile.txt; then
    echo "ERROR: Bitcode compilation failed."
    exit 1
fi
llvm-dis "$bcInput"
echo "  -> $bcInput"

echo "[4/5] Running KLEE symbolic execution..."
if ! ./build/bin/klee --libc=uclibc -libcxx -posix-runtime \
    --max-instructions=2000000 --warnings-only-to-file "$llInput"; then
    echo "ERROR: KLEE execution failed (timeout or SIGSEGV)."
    exit 1
fi

echo "[5/5] Extracting results..."
python3 "$toolPath/run.py" 1 "$toolPath"

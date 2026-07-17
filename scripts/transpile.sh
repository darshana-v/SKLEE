#!/bin/bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"

if [ $# -lt 1 ]; then
    echo "Usage: $0 <contract.sol> [--analyze]"
    echo ""
    echo "  Transpiles a Solidity contract to C++ for KLEE analysis."
    echo "  With --analyze: also compiles to LLVM bitcode and runs KLEE."
    echo ""
    echo "  Requirements:"
    echo "    Transpile only: flex, bison, g++, boost"
    echo "    Full analysis:  + brew install klee"
    exit 1
fi

input="$1"
analyze=false
if [ "${2:-}" = "--analyze" ]; then
    analyze=true
fi

toolPath="$ROOT_DIR/klee/tools/klee"
outputDir="$ROOT_DIR/output"
mkdir -p "$outputDir"

basename=$(basename "$input" .sol)

# Build transpiler if needed
if [ ! -f "$toolPath/verify" ]; then
    echo "Transpiler not built. Building..."
    bash "$SCRIPT_DIR/build_transpiler.sh"
fi

# Copy contract to tool directory and transpile
cp "$input" "$toolPath/"
solFile=$(basename "$input")

echo "Transpiling $solFile -> ${basename}.cpp"
"$toolPath/verify" < "$toolPath/$solFile" > /dev/null 2>&1

if [ -f "$toolPath/convertedFile.cpp" ]; then
    cp "$toolPath/convertedFile.cpp" "$outputDir/${basename}.cpp"
    echo "Output: $outputDir/${basename}.cpp"
else
    echo "ERROR: Transpilation failed."
    exit 1
fi

if [ "$analyze" = true ]; then
    echo ""
    echo "Compiling to LLVM bitcode..."

    KLEE_INCLUDE=""
    if [ -d "/opt/homebrew/opt/klee/include" ]; then
        KLEE_INCLUDE="/opt/homebrew/opt/klee/include"
    elif [ -d "/usr/local/opt/klee/include" ]; then
        KLEE_INCLUDE="/usr/local/opt/klee/include"
    else
        echo "ERROR: KLEE headers not found. Install with: brew install klee"
        exit 1
    fi

    clang++ -O0 -Wno-everything -std=c++11 \
        -I "$KLEE_INCLUDE" \
        -I "/opt/homebrew/include" \
        -emit-llvm -c -g \
        "$outputDir/${basename}.cpp" \
        -o "$outputDir/${basename}.bc" 2>/dev/null

    echo "Running KLEE..."
    klee --max-instructions=2000000 --warnings-only-to-file \
        "$outputDir/${basename}.bc"

    echo ""
    echo "Results in klee-last/"
fi

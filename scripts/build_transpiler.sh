#!/bin/bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"

toolPath="$ROOT_DIR/klee/tools/klee"
kleeLibPath="$ROOT_DIR/klee/lib/Core"

echo "Building SKLEE Solidity transpiler..."

# Check dependencies
for cmd in flex bison g++; do
    if ! command -v "$cmd" &>/dev/null; then
        echo "ERROR: $cmd not found. Install with: brew install $cmd"
        exit 1
    fi
done

# Check boost
if [ ! -d "/opt/homebrew/include/boost" ] && [ ! -d "/usr/local/include/boost" ]; then
    echo "WARNING: boost headers not found. Install with: brew install boost"
fi

BOOST_INCLUDE=""
if [ -d "/opt/homebrew/include" ]; then
    BOOST_INCLUDE="-I/opt/homebrew/include"
elif [ -d "/usr/local/include" ]; then
    BOOST_INCLUDE="-I/usr/local/include"
fi

# Generate lexer and parser
flex -o "$toolPath/lexer.c" -l "$toolPath/lexer.l"
bison -vd -o "$toolPath/grammar.c" "$toolPath/grammar.y"

# Compile transpiler
g++ -w -Wno-write-strings $BOOST_INCLUDE \
    "$kleeLibPath/defs.cpp" \
    "$toolPath/lexer.c" \
    "$toolPath/grammar.c" \
    -o "$toolPath/verify" -ll

echo "Transpiler built: $toolPath/verify"
echo "Usage: $toolPath/verify < input.sol"

## SKLEE

Dynamic symbolic analysis of Ethereum smart contracts using KLEE.

SKLEE transpiles Solidity contracts to C++, compiles to LLVM bitcode, and runs KLEE symbolic execution to detect vulnerabilities. It generates concrete test cases that trigger each bug.

### Vulnerability Classes

1. Integer overflow/underflow
2. Unchecked send
3. Greedy contract
4. Prodigal contract
5. Suicidal contract
6. Call to unknown function
7. Memory overlap
8. Address typecast
9. Payable but no fallback
10. Timestamp dependence
11. Transaction order dependence
12. Block state dependence
13. Mapping read

### Pipeline

```
Solidity (.sol) → [flex/bison transpiler] → C++ (.cpp) → [clang] → LLVM bitcode (.bc) → [KLEE] → bug reports + test cases
```

### macOS Setup

**Transpiler only** (Solidity → C++, no KLEE needed):

```bash
brew install boost flex bison
bash scripts/build_transpiler.sh
bash scripts/transpile.sh path/to/Contract.sol
```

**Full analysis with stock KLEE** (overflow/underflow detection):

```bash
brew install klee boost flex bison
bash scripts/transpile.sh path/to/Contract.sol --analyze
```

Note: stock KLEE detects integer overflow/underflow. For the full 13 vulnerability classes, use the Docker setup (which includes the modified KLEE with custom checkers).

**Full analysis via Docker** (all 13 vulnerability classes):

```bash
docker build -t sklee .
docker run -v $(pwd)/contracts:/contracts -it sklee bash
# inside container:
cd /sklee/scripts
bash runKLEE.sh /contracts/YourContract.sol
bash getResult.sh
```

### Linux Setup

```bash
# Install dependencies
sudo apt-get install build-essential curl libcap-dev git cmake \
    libncurses5-dev python3 python3-pip gcc-multilib g++-multilib \
    clang llvm-10-dev bison flex libboost-all-dev perl minisat \
    libsqlite3-dev
pip3 install lit tabulate wllvm

# Build STP solver
git clone https://github.com/stp/stp
cd stp && git submodule init && git submodule update
mkdir build && cd build && cmake .. && cmake --build .
sudo cmake --install .
cd ../..

# Build klee-uclibc
git clone https://github.com/klee/klee-uclibc.git
cd klee-uclibc && ./configure --make-llvm-lib && make -j2
cd ..

# Build SKLEE (modified KLEE)
mkdir build && cd build
cmake -DENABLE_SOLVER_STP=ON -DENABLE_POSIX_RUNTIME=ON \
    -DENABLE_KLEE_UCLIBC=ON -DKLEE_UCLIBC_PATH=../klee-uclibc/ \
    -DLLVM_CONFIG_BINARY=/usr/lib/llvm-10/bin/llvm-config \
    -DENABLE_UNIT_TESTS=OFF \
    -DLLVMCC=/usr/lib/llvm-10/bin/clang \
    -DLLVMCXX=/usr/lib/llvm-10/bin/clang++ \
    ../klee/
make

# Run
cd ../scripts
bash runKLEE.sh ../output/Voting.sol
bash getResult.sh
```

### Directory Structure

```
klee/              Modified KLEE with Solidity vulnerability checkers
  tools/klee/      Solidity transpiler (lexer.l, grammar.y)
  lib/Core/        KLEE executor with SKLEE vulnerability checks
  include/         KLEE + SKLEE headers
scripts/           Build and run scripts
  build_transpiler.sh   Build just the transpiler (macOS/Linux)
  transpile.sh          Transpile + optionally analyze a contract
  runKLEE.sh            Full pipeline (Linux/Docker)
  getResult.sh          Extract human-readable results
benchmarks/        721 benchmark contracts with ground truth
output/            Transpiler output directory
types.h            Solidity type system modeled in C++ (overflow detection)
functions.h        Solidity primitives modeled in C++ (send, transfer, etc.)
```

### References

- [SKLEE: A Dynamic Symbolic Analysis Tool for Ethereum Smart Contracts](https://link.springer.com/chapter/10.1007/978-3-031-17108-6_15) (SEFM 2022)
- [KLEE Symbolic Execution Engine](https://klee-se.org/)

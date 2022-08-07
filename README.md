## About:

Analysis of Ethereum Smart Contracts using KLEE

The tools is an augmented version of KLEE to verify Solidity smart contracts using symbolic execution and generate test-cases which gives concrete value of the variable when a bug is found.
The following are the smart contract vulnerabilities which can be verified:

1. Unchecked send
2. Integer overflow/underflow
3. Greedy contract
4. Prodigal contract
5. Suicidal contract
6. Call to unknown function
7. Memory overlap
8. Address typecast
9. Payable but no fallback
10. Timestamp dependence
11. Transaction order dependence
12. Blockstate dependence
13. Mapping read

## Directory Structure:

```
Frontend: php script based to execute command in backend
-OnlineKLEE (only deployed on local server for now)
Libraries: libraries to be cloned for independent installation
-libc++-10
-libc++-build-10
-libc++-install-10
-llvm-10
-klee-uclibc
-stp
Core Functionality
-klee
Benchmarks
-SKLEE Benchmarks
Scripts
-scripts


```

Run the tool:

1. Upload Solidy contract file <filename> (in text format) to directory klee/tools/klee/
2. bash runKLEE.sh <filename>
3. bash getResult.sh

## Installation:

All commands listed in requirements.txt under scripts directory.

Instructions to install lib other than KLEE:
```
sudo apt install bison
sudo apt install lex
sudo apt-get install libboost-all-dev

```
Instructions to install KLEE: https://klee.github.io/build-llvm11/

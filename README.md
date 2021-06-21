# SmartContractVerifier: SKLEE

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
-OnlineKLEE
Libraries: cloned libraries for independent installation
-libc++-10
-libc++-build-10
-libc++-install-10
-llvm-10
-klee-uclibc
-stp
Core Functionality
-klee


```

flow:

1. upload file to klee/tools/klee/
2. bash  runKLEE.sh filename
3. bash getResult.sh

workflow:

1. The ktest-tool is a Python script that converts the contents of a .ktest file into human-readable form.

## Installation:

--tbd

```
sudo apt install bison
sudo apt install lex
sudo apt-get install libboost-all-dev
sudo apt-get install llvm-10
sudo apt install libtcmalloc-minimal4

```

use LF endings while editing else bash script will not run

## To-Do:

* [ ] Initial Cleanup: [Max 1 week]

  * [ ] Run the tool and get ouput to get better understanding of file system & scripts
  * [ ] Rearrange scripts to make it modular. create a temporary output folder where all outputs will be stored
  * [ ] Make scripts portable. Remove all hardcoded code
  * [ ] OnlineKLEE is poorly written. Modify it to create more generic implementation that can run without issues - use herokuapp
  * [ ] intermediate outputs are also hardcoded. Need to modify core functionality to change it
  * [ ] Code Documentation
  
* [ ] Final script touch up
  * [ ] Updated Directory paths 
  * [ ] Re-building the klee tool
  * [ ] --add-here--

* [ ] Modifying Grammer: [Max 1 week]
  * [ ] Add mapping between line of c++ code generated and corresponding solidity code - create lookup and integrate with frontend
  * [ ] Add support for few missing structures - modify grammer

## Issues:

* [ ] Supports solidity version 0.6.10 only. Failed to compile on higher versions. Can be made generic or autodetect from pragma directive
* [ ] Documentation is not available. start documenting on the go
* [ ] ktest-tool supposed to generate test cases. Need to be regenerated - build
* [ ] error while loading shared libraries: libtcmalloc.so.4: cannot open shared object file: No such file or directory


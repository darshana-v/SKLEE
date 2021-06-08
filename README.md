# SmartContractVerifier: SKLEE
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

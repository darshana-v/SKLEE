#ifndef SOLIDITY_FUNC
#define SOLIDITY_FUNC

// #include <klee/klee.h>
#include "types.h"
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <x86intrin.h>
#include <boost/multiprecision/cpp_int.hpp>

// #define unsigned unsigned
// #define int int


//number units
#define wei *1
#define szabo *(10^12)
#define finney *(10^15)
#define ether *(10^18)

//time units
#define seconds *1
#define minutes *60
#define hours minutes*60
#define days hours*24
#define weeks days*7
#define years days*365

// #define unsigned  boost::multiprecision::unsigned

int gas_exhausted;
int gas_tobeused;

address blockCoinbase;
// (uint): current block difficulty
unsigned blockDifficulty;
// (uint): current block gaslimit
unsigned blockGaslimit;
// (uint): current block number
unsigned blockNumber = 1000;
// (uint): current block timestamp
unsigned blockTimestamp;
// (bytes): complete calldata
char* msgData;
// (address payable): sender of the message (current call)
address msgSender;
// (uint): number of wei sent with the message
unsigned msgValue;
// (uint): current block timestamp (alias for block.timestamp)
unsigned now;
// (uint): gas price of the transaction
unsigned txGasprice;
// (address payable): sender of the transaction (full call chain)
address txOrigin;

bool approximate(unsigned amount)
{
    int retVal;
    int balance;
    klee_make_symbolic(&balance, sizeof(balance),"balance");
    klee_make_symbolic(&gas_tobeused, sizeof(gas_tobeused),"gas_use");
    klee_make_symbolic(&gas_exhausted, sizeof(gas_exhausted),"gas_exhausted");

    // sender.balance = balance;
    if(gas_exhausted)
    	return false;

    else if(gas_tobeused >= 2300)
    	return false;
    // else if(sender.balance <= amount)
    // 	return false;

    else
    {
        // receiver.balance = 0;
        klee_make_symbolic(&retVal, sizeof(retVal),"returnValue");
        if(retVal > 0)
        {
        	// receiver.balance += amount;
        	// sender.balance -= amount;
            return true;
        }
        else
            return false;
    }
    return true;
    // std::srand(std::time(0));
    // int ret_val = rand()%2;
    // bool sendVal;
    //
    // if(ret_val)
    // 	sendVal = true;
    // else
    // 	sendVal = false;
}

address::address(){};
address::address(std::string id){
    strcpy(this->addressId, id.c_str());
}

bool address::operator ==(address const &A) const{
    if(A.addressId == this->addressId)
        return true;
    return false;
}
bool address::operator !=(address const &A) const{
    if(A.addressId != this->addressId)
        return true;
    return false;
}

bool address::operator <(address const &A) const {
    std::string str1(this->addressId);
    std::string str2(A.addressId);
    if(str1 < str2)
        return true;
    return false;
}
address& address::operator =(std::string id){
    strcpy(this->addressId, id.c_str());
    this->balance = 0;
    return *this;
}

bool address::send(unsigned amount){
     if(approximate(amount))
        return 1;
    else
        return 0;
}

bool address::call(unsigned amount){
    if(approximate(amount))
        return true;
    else
        return false;
}

bool address::staticcall(unsigned amount){
    if(approximate(amount))
        return true;
    else
        return false;
}

bool address::delegatecall(unsigned amount){
    if(approximate(amount))
        return true;
    else
        return false;
}

bool address::transfer(unsigned amount){
    if(approximate(amount))
        return true;
    else{
        std::cerr << "Exception on transfer";
        return false;
    }
}

std::string getUniqueStr() {
   static int n = 1;
   std::stringstream os;
   os << n++;
   return os.str();
}

int suicide(address receiver){
    int retVal;
    klee_make_symbolic(&retVal, sizeof(retVal),"returnValue");
    if(retVal > 0)
        return 1;
    else
        return 0;
}

int selfdestruct(address receiver){
    int retVal;
    klee_make_symbolic(&retVal, sizeof(retVal),"returnValue");
    if(retVal > 0)
        return 1;
    else
        return 0;
}

void revert(){
}

void revert(std::string /*memory */ message){
}

char* blockhash(unsigned blockNo){
    if(blockNo == blockNumber)
        return NULL;
    // else
    std::string temp = getUniqueStr();// + std::string(blockNo);
    char* hash = strdup(temp.c_str());
    return hash;
    // return NULL;
}

char* keccak256(/*bytes*/char* memory){
    std::string temp = getUniqueStr() + std::string(memory);
    char* hash = strdup(temp.c_str());
    return hash;
}

char* sha256(/*bytes*/char* memory){
    std::string temp = getUniqueStr() + std::string(memory);
    char* hash = strdup(temp.c_str());
    return hash;
}

char* ripemd160(/*bytes*/char* memory){
    std::string temp = getUniqueStr() + std::string(memory);
    char* hash = strdup(temp.c_str());
    return hash;
}

address ecrecover(/*bytes32*/char* hash, unsigned /*uint8*/ v, char* /*bytes32*/ r, char* /*bytes32*/ s){
    return address();
}

unsigned addmod(unsigned x, unsigned y, unsigned k){
    if(k != 0)
        return (x + y) % k;
    return 0; //do the checks
}

unsigned mulmod(unsigned x, unsigned y, unsigned k){
    if(k != 0)
        return (x + y) % k;
    return 0; //do the checks
}


#endif

#ifndef SOLIDITY_TYPES
#define SOLIDITY_TYPES

//#include <klee/klee.h>
#include <klee/Support/ErrorHandling.h>
#include <string>
#include <type_traits>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/cstdint.hpp>
#include <cstdint>
#include <climits>

#define uint256_t boost::multiprecision::uint256_t
#define int256_t boost::multiprecision::int256_t
#define int64 int64_t
#define uint64 uint64_t
#define int128_t boost::multiprecision::int128_t
#define uint128_t boost::multiprecision::uint128_t

struct address{

    char addressId[20] = {0};
    unsigned balance = 0;

    address();
    address(std::string);
    bool operator<(address const &A) const;
    bool operator==(address const &A) const;
    bool operator!=(address const &A) const;

    address& operator=(std::string);
    address& operator=(address const &A);

    //returns false ,dont revert on failure
    bool send(unsigned amount);

    //reverts and throws exception on failure
    bool transfer(unsigned amount);

    //.gas() modifier for all three, .value() not for delegatecall, contract_object.call() allowed
    //bool call(unsigned amount);
    bool staticcall(std::string);
    bool delegatecall(std::string);
    bool call(std::string);
    // bool call(std::vector<char>);
};

// For addition

template <typename X, typename T>
bool checkAdd(T a, T x){

    if (std::is_same<X, int>::value){
        if ((x > 0) && (a > INT_MAX - x)) return true;/* `a + x` would overflow */;
        if ((x < 0) && (a < INT_MIN - x)) return true;/* `a + x` would underflow */;
        return false;
    }

    else{
        if ((x > 0) && (a > X::max - x))return true;/* `a + x` would overflow */;
        if ((x < 0) && (a < X::min - x))return true;/* `a + x` would underflow */;
        return false;        
    }
}

// For subtraction
template <typename X, typename T>
bool checkSub(T a, T x){

    if (std::is_same<X, int>::value){
        if ((x > 0) && (a > INT_MAX + x)) return true;/* `a + x` would overflow */;
        if ((x < 0) && (a < INT_MIN + x)) return true;/* `a + x` would underflow */;
        return false;
    }
    else{
        if ((x < 0) && (a > X::max + x))return true;/* `a - x` would overflow */;
        if ((x > 0) && (a < X::min + x))return true;/* `a - x` would underflow */;
        return false;        
    }
}

// For multiplication
template <typename X, typename T>
bool checkMult(T a, T x){
    // There may be a need to check for -1 for two's complement machines.
    // If one number is -1 and another is INT_MIN, multiplying them we get abs(INT_MIN) which is 1 higher than INT_MAX
    // if ((a == -1) && (x == INT_MIN)) /* `a * x` can overflow */
    // if ((x == -1) && (a == INT_MIN)) /* `a * x` (or `a / x`) can overflow */
    // general case
    if (std::is_same<X, int>::value){
        if(x != 0){
            if (a > INT_MAX / x) return true;/* `a + x` would overflow */;
            if (a < INT_MIN / x) return true;
        }/* `a + x` would underflow */
        return false;
    }
    else{
        if(x != 0){
            if (a > X::max / x) return true;/* `a * x` would overflow */;
            if ((a < X::min / x)) return true;/* `a * x` would underflow */;
        }
    }
    return false;
}

template <typename X, typename T>
bool checkAddU(T a, T x){
    if((a + x) < a)
       return true;
    return false;
}

// For subtraction
template <typename X, typename T>
bool checkSubU(T a, T x){
    if(a < x)
       return true;
   return false;
}

// For multiplication
template <typename X, typename T>
bool checkMultU(T a, T x){
    // There may be a need to check for -1 for two's complement machines.
    // If one number is -1 and another is INT_MIN, multiplying them we get abs(INT_MIN) which is 1 higher than INT_MAX
    // if ((a == -1) && (x == INT_MIN)) /* `a * x` can overflow */
    // if ((x == -1) && (a == INT_MIN)) /* `a * x` (or `a / x`) can overflow */
    // general case
    if (std::is_same<X, int>::value){
        if(x != 0){
            if (a > INT_MAX / x) return true;/* `a * x` would overflow */;
            if ((a < 0 / x)) return true;/* `a * x` would underflow */;
            return false; 
        }
    }

    else if(x != 0){
        if (a > X::max / x)return true;/* `a * x` would overflow */;
        if ((a < 0 / x))return true;/* `a * x` would underflow */;
    }
    return false;
}


template <class X>
struct stype{
public:
    // X obj;
    int data;
    // class X;
    operator int() const{
       return data;
    }
    //arithmetic operators

    template <typename T>
    X& operator= (const T& val){
        X object; 
        if(checkAdd<X, int>((int)val, 0)){
            klee::setOverflow(1);
        }
        data = (int)val;
        return object;
    }

    template <typename T>
    X operator+ (const T& val){
        X object; 
        if(checkAdd<X, int>((int)*this, (int)val)){
            klee::setOverflow(1);
        }
        data = (int)*this + (int)val;
        return object;
    }

    X& operator++(){
        X object;
        object = (int)*this + (int)1;
        return object;
    }

    X operator++(int){
        X object;
        object = *this;
        this->operator++();         
        return object;
    }

    template <typename T>
    X operator- (const T& val){
        X object; 
        if(checkSub<X, int>((int)*this, (int)val)){
            klee::setOverflow(2);
        }
        data = (int)*this - (int)val;
        return object;
    }
    template <typename T>
    X operator* (T val){
        X object; 
        if(checkMult<X, int>((int)*this, (int)val)){
            klee::setOverflow(1);
        }
        data = (int)*this * (int)val;
        return object;
    }
    template <typename T>
    X operator/ (T val){
        // int real = (int)((int)*this / (int)val);
        X object;
        object = (int)*this/(int)val;

        // if(real != (int)temp)
        //     klee::setOverflow(4);
        return object;
    }
    template <typename T>
    X& operator+= (T val){
        // object = (int)*this + (int)val;
        //return X;

        X object; 
        object =  *this + val;
        return object;
    }

    template <typename T>
    X& operator-= (T val){
        X object; 
        object =  *this - val;
        return object;
    }

    template <typename T>
    X& operator*= (T val){
        X object; 
        object =  *this * val;
        return object;
    }
    template <typename T>
    X& operator/= (T val){
        X object; 
        object =  *this / val;
        return object;
    }

    X operator>> (const int val) const{
       return (int)( (int)*this >> val );
    }
    X operator<< (const int val) const{
       return (int)( (int)*this << val );
    }
    //logical operations

    operator bool() const{
       return (int)*this != 0;
    }
    bool operator! () const{
       return !((int)*this);
    }
    X operator- (){
       return (int)( -(int)*this );
    }
    template <typename T>
    bool operator== (const T& val) const{
       return (bool)((int)*this == (int)val);
    }
    template <typename T>
    bool operator!= (const T& val) const{
       return (bool)((int)*this != (int)val);
    }
    template <typename T>
    bool operator> (const T& val) const{
       return (bool)((int)*this > (int)val);
    }
    template <typename T>
    bool operator< (const T& val) const{
       return (bool)((int)*this < (int)val);
    }
    template <typename T>
    bool operator>= (const T& val) const{
       return (bool)((int)*this >= (int)val);
    }
    template <typename T>
    bool operator<= (const T& val) const{
       return (bool)((int)*this <= (int)val);
    }
};


template <class X>
struct utype{
public:
    // X obj;
    unsigned data;
    operator unsigned() const{
       return data;
    }
    //arithmetic operators

    template <typename T>
    X& operator= (const T& val){
        X object; 
        if(checkAddU<X, unsigned>((unsigned)val, 0)){
            klee::setOverflow(1);
        }
        data = (unsigned)val;
        return object;
    }

    X& operator= (int val){
        X object; 
        if(checkAddU<X, unsigned>((unsigned)val, 0)){
            klee::setOverflow(1);
        }
        data = (unsigned)val;
        return object;
    }

    template <typename T>
    X operator+ (const T& val){
        X object; 
        if(checkAddU<X, unsigned>((unsigned)*this, (unsigned)val)){
            klee::setOverflow(1);
        }
        data = (unsigned)*this + (unsigned)val;
        return object;
    }

    X& operator++(){
        X object;
        object = (unsigned)*this + (unsigned)1;
        return object;
    }

    X operator++(int){
        X ret = (unsigned)*this;
        this->operator++();
        return ret;
    }

    template <typename T>
    X operator- (const T& val){
        X object; 
        if(checkSubU<X, unsigned>((unsigned)*this, (unsigned)val)){
            klee::setOverflow(2);
        }
        data = (unsigned)*this - (unsigned)val;
        return object;
    }
    template <typename T>
    X operator* (T val){
        X object; 
        if(checkMultU<X, unsigned>((unsigned)*this, (unsigned)val)){
            klee::setOverflow(1);
        }
        data = (unsigned)*this * (unsigned)val;
        return object;
    }
    template <typename T>
    X operator/ (T val){
        // int real = (unsigned)((unsigned)*this / (unsigned)val);
        X object;
        object = (unsigned)*this/(unsigned)val;

        // if(real != (unsigned)temp)
        //     klee::setOverflow(4);
        return object;
    }
    template <typename T>
    X& operator+= (T val){
        // object = (unsigned)*this + (unsigned)val;
        //return X;

        X object; 
        object =  *this + val;
        return object;
    }

    template <typename T>
    X& operator-= (T val){
        X object; 
        object =  *this - val;
        return object;
    }

    template <typename T>
    X& operator*= (T val){
        X object; 
        object =  *this * val;
        return object;
    }
    template <typename T>
    X& operator/= (T val){
        X object; 
        object =  *this / val;
        return object;
    }

    X operator>> (const int val) const{
       return (unsigned)( (unsigned)*this >> val );
    }
    X operator<< (const int val) const{
       return (unsigned)( (unsigned)*this << val );
    }

    //logical operations

    operator bool() const{
       return (unsigned)*this != 0;
    }
    bool operator! () const{
       return !((unsigned)*this);
    }
    X operator- (){
       return (unsigned)( -(unsigned)*this );
    }
    template <typename T>
    bool operator== (const T& val) const{
       return (bool)((unsigned)*this == (unsigned)val);
    }
    template <typename T>
    bool operator!= (const T& val) const{
       return (bool)((unsigned)*this != (unsigned)val);
    }
    template <typename T>
    bool operator> (const T& val) const{
       return (bool)((unsigned)*this > (unsigned)val);
    }
    template <typename T>
    bool operator< (const T& val) const{
       return (bool)((unsigned)*this < (unsigned)val);
    }
    template <typename T>
    bool operator>= (const T& val) const{
       return (bool)((unsigned)*this >= (unsigned)val);
    }
    template <typename T>
    bool operator<= (const T& val) const{
       return (bool)((unsigned)*this <= (unsigned)val);
    }
};


template <typename T, typename U>
U operator+(U i, const T& val){
    U object;
    if(sizeof(U) > sizeof(T)){
        if(checkAdd<U, int>((int)i, (int)val)){
            klee::setOverflow(1);
        }
    }
    else{
        if(checkAdd<T, int>((int)i, (int)val)){
            klee::setOverflow(1);
        }
    }
    object =  (int)i + (int)val;
    return object;

}

template <typename T, typename U>
U operator-(U i, const T& val){
    U object;
    if(sizeof(U) > sizeof(T)){
        if(checkSub<U, int>((int)i, (int)val)){
            klee::setOverflow(2);
        }
    }
    else{
        if(checkSub<T, int>((int)i, (int)val)){
            klee::setOverflow(2);
        }
    }
    object =  (int)i - (int)val;
    return object;
}

template <typename T, typename U>
U operator*(U i, const T& val){
    U object;
    if(sizeof(U) > sizeof(T)){
        if(checkMult<U, int>((int)i, (int)val)){
            klee::setOverflow(3);
        }
    }
    else{
        if(checkMult<T, int>((int)i, (int)val)){
            klee::setOverflow(3);
        }
    }
    object =  (int)i * (int)val;
    return object;
}

template <typename T, typename U>
U operator/(U i, const T& val){
    U object;
    object =  (int)i/(int)val;
    return object;
}

struct __attribute__((packed)) int8{
    int data:8;
    const static int min = -128;
    const static int max = 127;
    int8(){}
    template <typename T>
    int8(T val){
        data = val;
    }
    operator int() const{
       return data;
    }
};

struct __attribute__((packed)) int16{
    int data:16;
    const static int min = -32768;
    const static int max = 32767;
    int16(){}
    template <typename T>
    int16(T val){
        data = val;
    }
    operator int() const{
       return data;
    }
};

struct __attribute__((packed)) int24{
    int data:24;
    const static int min = -8388608;
    const static int max = 8388607;
    int24(){}
    template <typename T>
    int24(T val){
        data = val;
    }
    operator int() const{
       return data;
    }
};

struct __attribute__((packed)) int32: public stype<int32>{
    int data;
    const static int min = -2147483648;
    const static int max = 2147483647;
    int32(){}
    template <typename T>
    int32(T val){
        data = val;
    }
    operator int() const{
       return data;
    }
};

struct __attribute__((packed)) uint8{
    unsigned data:8;
    const static unsigned min = 0;
    const static unsigned max = 255;
    uint8(){}
    template <typename T>
    uint8(T val){
        data = val;
    }
    operator unsigned() const{
       return data;
    }
};

struct __attribute__((packed)) uint16{
    unsigned data:16;
    const static unsigned min = 0;
    const static unsigned max = 65535;
    uint16(){}
    template <typename T>
    uint16(T val){
        data = val;
    }
    operator unsigned() const{
       return data;
    }
};

struct __attribute__((packed)) uint24{
    unsigned data:24;
    const static unsigned min = 0;
    const static unsigned max = 8388607 * 2 + 1;
    uint24(){}
    template <typename T>
    uint24(T val){
        data = val;
    }
    operator unsigned() const{
       return data;
    }
};

struct __attribute__((packed)) uint32: public utype<uint32>{
    unsigned data;
    const static unsigned min = 0;
    const static unsigned max = 4294967295;
    uint32(){}
    template <typename T>
    uint32(T val){
        data = val;
    }
    operator unsigned() const{
       return data;
    }
};

struct __attribute__((packed)) int256: public stype<int256>{
    int256_t data;
    constexpr static int256_t min = - (2^255);
    constexpr static int256_t max = 2^ 255;
    int256(){}
    template <typename T>
    int256(T val){
        data = (int)val;
    }
    operator int() const{
       return data.convert_to<int>();
    }
};

struct __attribute__((packed)) uint256: public utype<uint256>{
    uint256_t data;
    static inline uint256_t min = 0;
    static inline uint256_t max = 2^ 255;
    uint256(){}
    template <typename T>
    uint256(T val){
        data = (unsigned)val;
    }
    operator unsigned() const{
       return data.convert_to<unsigned>();
    }
    operator long() const{
       return data.convert_to<long>();
    }
};

template <class X>
struct Vector: std::vector<X>{
    std::vector<X> vec;
    X& operator[] (const uint256_t nIndex){
       return vec[(unsigned)nIndex.convert_to<unsigned>()];
    }
    X& operator[] (const uint256 nIndex){
       return vec[(unsigned)nIndex];
    }
};

#endif

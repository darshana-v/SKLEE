#ifndef SOLIDITY_TYPES
#define SOLIDITY_TYPES

//#include <klee/klee.h>
#include <klee/Support/ErrorHandling.h>
// #include <string>
// #include <cstring>
#include <boost/multiprecision/cpp_int.hpp>
//
#define uint256_t boost::multiprecision::uint256_t
#define int256_t boost::multiprecision::int256_t

// #define uint256 unsigned
// #define int256 int

typedef struct __attribute__((packed)) int8{
public:
    int data:8;
    int8();
    template <typename T>
    int8(T val);
    // template <typename T>
    operator int() const;

    //arithmetic operators
    template <typename T, typename U>
    friend U operator+(U i, const T& val);
    template <typename T, typename U>
    friend U operator-(U i, const T& val);
    template <typename T, typename U>
    friend U operator*(U i, const T& val);
    template <typename T, typename U>
    friend U operator/(U i, const T& val);
    // template <typename T>
    // friend int256& operator[](int256& val, T index);

    template <typename T>
    int8& operator= (const T& val);

    template <typename T>
    int8 operator+ (const T& val);

    template <typename T>
    int8 operator- (T val);
    template <typename T>
    int8 operator* (T val);
    template <typename T>
    int8 operator/ (T val);
    template <typename T>
    int8& operator+= (T val);
    template <typename T>
    int8& operator-= (T val);

    template <typename T>
    int8& operator*= (T val);
    template <typename T>
    int8& operator/= (T val);

    int8 operator>> (const int val) const;
    int8 operator<< (const int val) const;

    //logical operations

    operator bool() const;
    bool operator! () const;
    int8 operator- ();
    template <typename T>
    bool operator== (const T& val) const;
    template <typename T>
    bool operator!= (const T& val) const;
    template <typename T>
    bool operator> (const T& val) const;
    template <typename T>
    bool operator< (const T& val) const;
    template <typename T>
    bool operator>= (const T& val) const;
    template <typename T>
    bool operator<= (const T& val) const;
}int8;

typedef struct __attribute__((packed)) int16{
public:
    int data:16;
    int16();
    template <typename T>
    int16(T val);
    // template <typename T>
    operator int() const;

    //arithmetic operators
    template <typename T, typename U>
    friend U operator+(U i, const T& val);
    template <typename T, typename U>
    friend U operator-(U i, const T& val);
    template <typename T, typename U>
    friend U operator*(U i, const T& val);
    template <typename T, typename U>
    friend U operator/(U i, const T& val);
    // template <typename T>
    // friend int256& operator[](int256& val, T index);

    template <typename T>
    int16& operator= (T val);

    template <typename T>
    int16 operator+ (T val);

    template <typename T>
    int16 operator- (T val);
    template <typename T>
    int16 operator* (T val);
    template <typename T>
    int16 operator/ (T val);
    template <typename T>
    int16& operator+= (T val);

    template <typename T>
    int16& operator-= (T val);

    template <typename T>
    int16& operator*= (T val);
    template <typename T>
    int16& operator/= (T val);

    int16 operator>> (const int val) const;
    int16 operator<< (const int val) const;

    //logical operations

    operator bool() const;
    bool operator! () const;
    int16 operator- ();
    template <typename T>
    bool operator== (const T& val) const;
    template <typename T>
    bool operator!= (const T& val) const;
    template <typename T>
    bool operator> (const T& val) const;
    template <typename T>
    bool operator< (const T& val) const;
    template <typename T>
    bool operator>= (const T& val) const;
    template <typename T>
    bool operator<= (const T& val) const;

}int16;

typedef struct uint256{
public:
    uint256_t data;
    uint256();
    template <typename T>
    uint256(T val);
    // template <typename T>
    operator uint256_t() const;

    // arithmetic operators
    template <typename T, typename U>
    friend U operator+(U i, const T& val);
    template <typename T, typename U>
    friend U operator-(U i, const T& val);
    template <typename T, typename U>
    friend U operator*(U i, const T& val);
    template <typename T, typename U>
    friend U operator/(U i, const T& val);

    template <typename T>
    uint256& operator= (const T& val);

    uint256& operator++();

    uint256 operator++(int);

    template <typename T>
    uint256 operator+ (const T& val);
    // uint256 operator++ ();

    template <typename T>
    uint256 operator- (const T& val);
    // template <typename T>
    uint256 operator-- ();
    template <typename T>
    uint256 operator* (const T& val);
    template <typename T>
    uint256 operator/ (const T& val);
    template <typename T>
    uint256 operator[](T index);
    template <typename T>
    uint256& operator+= (const T& val);
    template <typename T>
    uint256& operator-= (const T& val);
    template <typename T>
    uint256& operator*= (const T& val);
    template <typename T>
    uint256& operator/= (const T& val);


    operator bool() const;
    bool operator! () const;
    // uint256 operator- ();
    template <typename T>
    bool operator== (const T& val) const;
    template <typename T>
    bool operator!= (const T& val) const;
    template <typename T>
    bool operator> (const T& val) const;
    template <typename T>
    bool operator< (const T& val) const;
    template <typename T>
    bool operator>= (const T& val) const;
    template <typename T>
    bool operator<= (const T& val) const;

}uint256;


typedef struct int256{
public:

    int256_t data;
    int256();
    template <typename T>
    int256(T val);
    // template <typename T>
    operator int256_t() const;

    //arithmetic operators
    template <typename T, typename U>
    friend U operator+(U i, const T& val);
    template <typename T, typename U>
    friend U operator-(U i, const T& val);
    template <typename T, typename U>
    friend U operator*(U i, const T& val);
    template <typename T, typename U>
    friend U operator/(U i, const T& val);

    template <typename T>
    int256& operator= (const T& val);

    int256& operator++();

    int256 operator++(int);

    template <typename T>
    int256 operator+ (const T& val);
    // int256 operator++ ();

    template <typename T>
    int256 operator- (const T& val);
    // template <typename T>
    int256 operator-- ();
    template <typename T>
    int256 operator* (const T& val);
    template <typename T>
    int256 operator/ (const T& val);
    template <typename T>
    int256 operator[](T index);
    template <typename T>
    int256& operator+= (const T& val);
    template <typename T>
    int256& operator-= (const T& val);
    template <typename T>
    int256& operator*= (const T& val);
    template <typename T>
    int256& operator/= (const T& val);


    operator bool() const;
    bool operator! () const;
    // int256 operator- ();
    template <typename T>
    bool operator== (const T& val) const;
    template <typename T>
    bool operator!= (const T& val) const;
    template <typename T>
    bool operator> (const T& val) const;
    template <typename T>
    bool operator< (const T& val) const;
    template <typename T>
    bool operator>= (const T& val) const;
    template <typename T>
    bool operator<= (const T& val) const;

}int256;

// template <typename T, typename U>
// U operator+(U i, const T& val);
// template <typename T, typename U>
// U operator-(U i, const T& val);
//
// template <typename T, typename U>
// U operator*(U i, const T& val);
//
// template <typename T, typename U>
// U operator/(U i, const T& val);

// template <typename T>
// int256& operator[](int256& val, T index);


// template <typename T>
// operator int8(const T& val);
// template <typename T>
// operator int16(const T& val);

// typedef struct type;type;

struct address{

    char* addressId;
    unsigned balance;

    address();
    address(std::string);
    bool operator<(address const &A) const;
    bool operator==(address const &A) const;
    bool operator!=(address const &A) const;

    address& operator=(std::string id);

    //returns false ,dont revert on failure
    bool send(unsigned amount);

    //reverts and throws exception on failure
    bool transfer(unsigned amount);

    //.gas() modifier for all three, .value() not for delegatecall, contract_object.call() allowed
    bool call(unsigned amount);
    bool staticcall(unsigned amount);
    bool delegatecall(unsigned amount);

};

#endif

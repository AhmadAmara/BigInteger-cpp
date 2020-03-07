#pragma once

#include <iostream>
#include <ostream>
#include<string>
#include<vector>

#define BASE 10

typedef long long int ll;


/**
this class can represent a base 10 big integers
that cannot be stored in long long from the initlization
or after math operators evaluted on it 
*/
class BigInteger
{

private:
		typedef std::vector<int> Digits;

public:
	
	explicit BigInteger(ll integer);
	explicit BigInteger(std::string str_integer);
	BigInteger(); 

	explicit BigInteger(const Digits& digits, bool negative):
	m_digits(digits), m_negative(negative){};

	BigInteger(const BigInteger& other):
	m_digits(other.m_digits), m_negative(other.m_negative){};

	BigInteger& operator=(BigInteger other); // cpy assignment

	~BigInteger(){};

	BigInteger operator+(const BigInteger& other) const;
	BigInteger operator-(const BigInteger& other) const;
	BigInteger operator*(const BigInteger& other) const;
	BigInteger operator/(const BigInteger& other) const;
	BigInteger operator%(const BigInteger& other) const;

	BigInteger& operator+=(const BigInteger& other);
	BigInteger& operator-=(const BigInteger& other);
	BigInteger& operator*=(const BigInteger& other);
	BigInteger& operator/=(const BigInteger& other);
	BigInteger& operator%=(const BigInteger& other);

	BigInteger& operator--(); //prefix
	BigInteger& operator++(); //prefix
	BigInteger operator--(int); //postfix
	BigInteger operator++(int); //postfix
	BigInteger operator-(); 


	bool operator==(const BigInteger& other);
	bool operator!=(const BigInteger& other);
	bool operator>(const BigInteger& other);
	bool operator<(const BigInteger& other);
	bool operator>=(const BigInteger& other);
	bool operator<=(const BigInteger& other);

	friend std::ostream& operator<<(std::ostream& os, const BigInteger& num);



	// typedef Digits::iterator iterator;
	// typedef Digits::const_iterator const_iterator;
	// iterator begin() { return m_digits.begin(); }
	// iterator end() { return m_digits.end(); }

private:
	Digits m_digits;
	// std::vector<int> m_vInteger;
	bool m_negative; 

};




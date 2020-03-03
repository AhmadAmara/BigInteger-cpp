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

public:
	
	explicit BigInteger(ll integer);
	explicit BigInteger(std::string str_integer);
	BigInteger();
	BigInteger(const BigInteger& other);

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


private:
	std::vector<int> m_vInteger;
	bool m_negative; 

};




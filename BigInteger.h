#pragma once

#include <ostream>
#include<string>
#include<vector>

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


private:
	std::vector<int> m_integer_vector;
	bool m_negative; 

};


std::ostream& operator<<(std::ostream& os, const BigInteger& num);





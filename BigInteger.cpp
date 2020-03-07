#include "BigInteger.h"
#include<sstream>  
#include <algorithm>

BigInteger::BigInteger():  m_negative(false)
{
	m_digits.push_back(0);
}


BigInteger::BigInteger(std::string str_integer): m_negative(false)
{
	if(str_integer[0] == '-' || str_integer[0] == '+')
	{
		m_negative = str_integer[0] == '-';
		str_integer = str_integer.substr(1, str_integer.length());
	}
	
	reverse(str_integer.begin(), str_integer.end());
	for(char c: str_integer)
	{
		m_digits.push_back(c - '0');
	}
}



BigInteger::BigInteger(ll integer): m_negative(false)
{
	if(integer == 0)
	{
		m_digits.push_back(0);
		return;
	}

	if(integer < 0)
	{
		m_negative = true;
		integer = -integer;
	}

	while(integer)
	{
		m_digits.push_back(integer % BASE);
		integer /= 10;
	}
}


BigInteger BigInteger::operator*(const BigInteger& other) const
{
	std::vector<int> result_vec(m_digits.size() + other.m_digits.size(), 0);
	size_t this_idx = 0;
	size_t other_idx = 0;
	unsigned char carry = 0, temp;
	for(int d1: m_digits)
	{
		carry = 0;
		other_idx = 0;

		for(int d2: other.m_digits)
		{
			temp = d1 * d2 + result_vec[this_idx + other_idx] + (int)carry;
			carry = (int)(temp/10);
			temp = (int)(temp%10);
			result_vec[this_idx + other_idx] = temp;
			other_idx++;
		}
		if(carry > 0)
		{
			result_vec[this_idx + other_idx] += carry;
		}

		this_idx++;
	}
	// bool sign = m_negative == other.m_negative;
	return BigInteger(result_vec, m_negative != other.m_negative);
}



std::ostream& operator<<(std::ostream& os, const BigInteger& integer)
{
	if(integer.m_negative)
	{
		os << "-";
	}
	bool left_zeros = true;
	std::vector<int>::const_reverse_iterator iter;
	for (iter = integer.m_digits.rbegin(); iter != integer.m_digits.rend(); ++iter )
    { 
		if(*iter == 0 && left_zeros)
		{
			continue;
		}
		else
		{
			left_zeros = false;
		}

		os << *iter;
	} 
	
	return os;
}


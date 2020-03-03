#include "BigInteger.h"
#include<sstream>  

BigInteger::BigInteger():  m_negative(false)
{
	m_vInteger.push_back(0);
}

BigInteger::BigInteger(ll integer): m_negative(false)
{
	if(integer == 0)
	{
		m_vInteger.push_back(0);
		return;
	}

	if(integer < 0)
	{
		m_negative = true;
		integer = -integer;
	}

	while(integer)
	{
		m_vInteger.push_back(integer % BASE);
		integer /= 10;
	}
}


std::ostream& operator<<(std::ostream& os, const BigInteger& integer)
{
	std::string str_rep = "";
	if(integer.m_negative)
	{
		os << "-";
	}
	std::vector<int>::const_reverse_iterator iter;

	for (iter = integer.m_vInteger.rbegin(); iter != integer.m_vInteger.rend(); ++iter )
    { 
		os << *iter;
	} 
	
	return os;
}


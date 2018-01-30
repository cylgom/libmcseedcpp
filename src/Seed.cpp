#include "java.hpp"
#include "java/lang/String.hpp"
#include "Seed.hpp"
#include <string>
#include <iostream>

using std::string;
using std::u16string;
using java::decode16;
using java::encode16;
using java::hashcode16;

typedef string::size_type str_size_t;

Seed::Seed(const string& s) :
	seed(encode16(s), 0, 32)
{
}

Seed::Seed(const u16string& s) :
	seed(s, 0, 32)
{
}

void Seed::set(const string& s)
{
	u16string tmp(encode16(s), 0, 32);
	seed = tmp;
}

void Seed::set(const u16string& s)
{
	u16string tmp(s, 0, 32);
	seed = tmp;
}

jlong Seed::get()
{
	string s = decode16(seed);
	str_size_t len = s.size();
	bool number = true;

	if(len < 1
	|| (len < 2 && (s[0] == '-' || s[0] == '+'))
	|| (!isdigit(s[0]) && s[0] != '-' && s[0] != '+'))
	{
		number = false;
	}
	else
	{
		for(str_size_t i = 1; i < len; ++i)
		{
			if(!isdigit(s[i]))
			{
				number = false;
				break;
			}
		}
	}

	if(number)
	{
		return (jlong)stoll(s, &len, 10);
	}
	else
	{
		return hashcode16(seed);
	}
}

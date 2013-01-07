/*****************************************************************************
 * Int2Eng.cpp: Integer to English converter Implmentation
 * Copyright (C) 2013 John (Juhan) Lee
 * Authors:     John (Juhan) Lee<to.johnny.lee@gmail.com>
 * Description: Integer to english number conversion
		
	Write a program that takes an integer and displays 
	the English name of that value.
	You should support both positive and negative numbers. 
		
	Examples:
		
	10 -> ten
	121 -> one hundred twenty one
	1032 -> one thousand thirty two
	11043 -> eleven thousand forty three
	1200000 -> one million two hundred thousand

* Date:	05. Jan. 2013
 *****************************************************************************/

#include "Int2Eng.h"
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <cstdlib>

using namespace std;

const string STR_MINUS = "minus";

const std::string eng1[] = {
	"zero", "one", "two", "three", "four", "five",
	"six", "seven", "eight", "nine"
};

const std::string eng11[] = {
	"ten", "eleven", "twelve", "thirteen", "fourteen", 
	"fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

const std::string eng2[] = {
	"ten", "twenty", "thirty", "fourty", "fifty",
	"sixty", "seventy", "eighty", "ninety" 
};

const std::string eng3[] = {
	"hundred", "thousand", "million"
};

bool Int2Eng::parse()
{
	bool res = true;
	int offset = 0;
	if(_strInput.at(0) == '-')
	{
		_isMinus = true;
		offset = 1;
	}
	
	for_each(_strInput.begin() + offset, _strInput.end(), [&](char c){
		if(!isdigit(c))
			res = false;
	});

	//if value is not number stop here
	if(!res)
		return false;

	digit();

	if(res && _isMinus)
		return true;

	return res;
}

int Int2Eng::digit()
{
	_digit = _isMinus? _strInput.length()-1 : _strInput.length();
	return _digit;
}


std::string Int2Eng::getNumChar(int digit, const char c)
{
	string targetStr("");
	int number = 0;

	//convert character to number (e.g. '6' --> 6)
	number = c - '0';

	switch(digit)
	{
	case 1:
		if(_ten2nineteen)
			targetStr += eng11[number];
		else
			targetStr += eng1[number];

		break;

	case 2:
		if(number == 1)
			_ten2nineteen = true;
		else
			targetStr += eng2[number-1];
		break;
	
	case 3:
		//e.g. three hundred
		if(number != 0)
		{
			targetStr += eng1[number];
			targetStr += " ";
			targetStr += eng3[0];
		}		
		break;

	case 4:
		//e.g. four thousand
		if(_ten2nineeteen2)
		{
			targetStr += eng11[number];
			targetStr += " ";
			targetStr += eng3[1];
		}
		else
		{
			if(number != 0)
			{
				targetStr += eng1[number];
				targetStr += " ";
				targetStr += eng3[1];
			}
		}
		break;
	
	case 5:
		if(number == 1)
		{
			_ten2nineeteen2 = true;
		}
		else
		{
			targetStr += eng2[number-1];
		}
		break;
	
	//more to come to handle number bigger than 99999

	default:
		break;
	}
	return targetStr;
}

std::string Int2Eng::buildStr()
{
	string targetStr("");
	char numPart[32] = {0};
	int offset = 0;
	
	if(_isMinus)
	{
		_vOutString.push_back(STR_MINUS);
		offset = 1;
	}

	_strInput.copy(numPart, _strInput.length()-offset, offset);

	int digit = _digit;
	int index = 0;

	while(digit){
		string out(getNumChar(digit, numPart[index]));
		if(out.compare("") != 0)
			_vOutString.push_back(out);
		digit--;
		index++;
	}

	for(auto it = _vOutString.begin(); it != _vOutString.end(); it++)
	{
		targetStr += *it;
		if(it + 1 != _vOutString.end())
			targetStr += " ";
	}
	return targetStr;
}

std::string Int2Eng::getOutput()
{
	if(!parse())
		return "wrong input (Enter from 0 to 99999)";
	return string(buildStr());
}


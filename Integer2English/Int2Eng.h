/*****************************************************************************
 * Int2Eng.h: Integer to English converter Interface definition
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

#ifndef _INT2ENG_H_
#define _INT2ENG_H_


#include <string>
#include <vector>
#include "gtest/gtest_prod.h"

class Int2Eng
{
	std::string _strInput;

	std::vector<std::string> _vOutString;

	bool _isMinus;

	int _digit;

	bool _ten2nineteen;

	bool _ten2nineeteen2;

public:

	explicit Int2Eng(const std::string& input) : 
					_strInput(input), 
					_isMinus(false), 
					_digit(0),
					_ten2nineteen(false),
					_ten2nineeteen2(false)
					{}

	//verify input validity
	bool parse();

	//return number of digit
	int digit();

	std::string getNumChar(int digit, const char c);

	std::string getOutput();

private:
	std::string buildStr();

	//gtest testcases

	FRIEND_TEST(Analyse, t0);

	FRIEND_TEST(Analyse, t1);

	FRIEND_TEST(Analyse, t2);

	FRIEND_TEST(Analyse, t3);

	FRIEND_TEST(Analyse, t4);

};

#endif //_INT2ENG_H_
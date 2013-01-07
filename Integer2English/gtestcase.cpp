/*****************************************************************************
 * gtestcase.cpp: gtest unittest
 * Copyright (C) 2013 John (Juhan) Lee
 * Authors:     John (Juhan) Lee<to.johnny.lee@gmail.com>
 * Description: googletest unittest of Int2Eng Class
 * Date:	05. Jan. 2013
 *****************************************************************************/

#include "gtest/gtest.h"
#include "Int2Eng.h"

TEST(InputTest, twoDigit)
{
	Int2Eng in1("45");
	in1.parse();
	EXPECT_TRUE(in1.digit() == 2);

	Int2Eng in2("-93");
	in2.parse();
	EXPECT_TRUE(in2.digit() == 2);
}

TEST(InputTest, threeDigit)
{
	Int2Eng in1("456");
	in1.parse();
	EXPECT_TRUE(in1.digit() == 3);

	Int2Eng in2("-631");
	EXPECT_TRUE(in1.digit() == 3);
}

TEST(InputTest, fourDigit)
{
	Int2Eng in1("4567");
	in1.parse();

	EXPECT_TRUE(in1.digit() == 4);

	Int2Eng in2("-6315");
	in2.parse();
	EXPECT_TRUE(in2.digit() == 4);
}

TEST(InputTest, fiveDigit)
{
	Int2Eng in1("12345");
	in1.parse();

	EXPECT_TRUE(in1.digit() == 5);

	Int2Eng in2("-63186");
	in2.parse();
	EXPECT_TRUE(in2.digit() == 5);
}

TEST(InputTest, sixDigit)
{
	Int2Eng in1("453223");
	in1.parse();
	EXPECT_TRUE(in1.digit() == 6);

	
	Int2Eng in2("-631863");
	in2.parse();
	EXPECT_TRUE(in2.digit() == 6);
}

TEST(ValidityTest, isNumber)
{
	Int2Eng in1("34dasd");
	in1.parse();
	EXPECT_FALSE(in1.parse());

	Int2Eng in2("a4xjdhe");
	in2.parse();
	EXPECT_FALSE(in2.parse());

	Int2Eng in3("??92");
	
	in3.parse();
	EXPECT_FALSE(in3.parse());

	Int2Eng in4("12345678901234567890123456789012");//32bit
	in4.parse();
	EXPECT_TRUE(in4.parse());
}

TEST(ValidityTest, isNegative)
{
	Int2Eng in6("-34123");
	in6.parse();
	EXPECT_TRUE(in6.parse());

	Int2Eng in7("-3-4123");
	in7.parse();
	EXPECT_FALSE(in7.parse());
}

TEST(Analyse, t0)
{
	//10 -> ten
	Int2Eng in0("10");
	EXPECT_TRUE(in0.parse());
	ASSERT_STRCASEEQ("ten", in0.buildStr().c_str());

	Int2Eng in1("11");
	EXPECT_TRUE(in1.parse());
	ASSERT_STRCASEEQ("eleven", in1.buildStr().c_str());

	Int2Eng in2("12");
	EXPECT_TRUE(in2.parse());
	ASSERT_STRCASEEQ("twelve", in2.buildStr().c_str());

	Int2Eng in3("15");
	EXPECT_TRUE(in3.parse());
	ASSERT_STRCASEEQ("fifteen", in3.buildStr().c_str());

	Int2Eng in4("19");
	EXPECT_TRUE(in4.parse());
	ASSERT_STRCASEEQ("nineteen", in4.buildStr().c_str());

	Int2Eng in5("0");
	EXPECT_TRUE(in5.parse());
	ASSERT_STRCASEEQ("zero", in5.buildStr().c_str());

	Int2Eng in6("9");
	EXPECT_TRUE(in6.parse());
	ASSERT_STRCASEEQ("nine", in6.buildStr().c_str());


}


TEST(Analyse, t1)
{
	Int2Eng in1("64");
	EXPECT_TRUE(in1.parse());
	ASSERT_STRCASEEQ("sixty four", in1.buildStr().c_str());

	Int2Eng in2("99");
	EXPECT_TRUE(in2.parse());
	ASSERT_STRCASEEQ("ninety nine", in2.buildStr().c_str());

	Int2Eng in3("21");
	EXPECT_TRUE(in3.parse());
	ASSERT_STRCASEEQ("twenty one", in3.buildStr().c_str());

}

TEST(Analyse, t2)
{
	Int2Eng in1("264");
	EXPECT_TRUE(in1.parse());
	ASSERT_STRCASEEQ("two hundred sixty four", in1.buildStr().c_str());

	Int2Eng in2("-189");
	EXPECT_TRUE(in2.parse());
	ASSERT_STRCASEEQ("minus one hundred eighty nine", in2.buildStr().c_str());

	Int2Eng in3("-766");
	EXPECT_TRUE(in3.parse());
	ASSERT_STRCASEEQ("minus seven hundred sixty six", in3.buildStr().c_str());

	//121 -> one hundred twenty one
	Int2Eng in4("121");
	EXPECT_TRUE(in4.parse());
	ASSERT_STRCASEEQ("one hundred twenty one", in4.buildStr().c_str());

}

TEST(Analyse, t3)
{
	Int2Eng in1("6423");
	EXPECT_TRUE(in1.parse());
	ASSERT_STRCASEEQ("six thousand four hundred twenty three", in1.buildStr().c_str());

	Int2Eng in2("6419");
	EXPECT_TRUE(in2.parse());
	ASSERT_STRCASEEQ("six thousand four hundred nineteen", in2.buildStr().c_str());

	//1032 -> one thousand thirty two
	Int2Eng in3("1032");
	EXPECT_TRUE(in3.parse());
	ASSERT_STRCASEEQ("one thousand thirty two", in3.buildStr().c_str());


}

TEST(Analyse, t4)
{
	Int2Eng in1("46423");
	EXPECT_TRUE(in1.parse());
	ASSERT_STRCASEEQ("fourty six thousand four hundred twenty three", in1.buildStr().c_str());

	Int2Eng in2("46412");
	EXPECT_TRUE(in2.parse());
	ASSERT_STRCASEEQ("fourty six thousand four hundred twelve", in2.buildStr().c_str());

	//11043 -> eleven thousand forty three
	Int2Eng in3("11043");
	EXPECT_TRUE(in3.parse());
	ASSERT_STRCASEEQ("eleven thousand fourty three", in3.buildStr().c_str());
}



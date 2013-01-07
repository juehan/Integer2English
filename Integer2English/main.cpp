#include "Int2Eng.h"
#include <iostream>

#define _GTEST_

#ifdef _GTEST_
#include "gtest/gtest.h"
#endif//_GTEST_

using namespace std;
	
void StartGame()
{
	string input("");
	cout << "Number to English Converter (Enter 'x' to quit) " << endl;
	while(true) {
		cout << "Enter number: ";
		cin >> input;
		if(input.compare("x") == 0)
			break;
		Int2Eng i2e(input);
		if(i2e.digit() > 5)
		{
			cout << "wrong input (Enter from 0 to 99999)" << endl;
			continue;
		}
		cout << i2e.getOutput() << "\n" << endl;
	}
	cout << "Have a nice day" << endl;
}


int main(int argc, char** argv)
{
#ifdef _GTEST_
    cout << "running all tests ....\n" << endl;
    ::testing::InitGoogleTest(&argc, argv); //you have to initialize before its use
    RUN_ALL_TESTS(); //run all tests
#else
	StartGame();
#endif//_GTEST_
    return 0;
}

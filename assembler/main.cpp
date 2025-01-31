#include <iostream>
#include <fstream>
#include <string>
#include "Lexer.h"

using namespace std;

int main() {
	
	Lexer test1("test1.s");
	cout << "test 1:" << endl << "virtual answer:" << endl;
	test1.run();
	cout << "correct answer:" << endl << 45 << endl << 30 << endl << 32 << endl;
	cout << "-----------------------------------------------" << endl;

	Lexer test2("test2.s");
	cout << "test 2:" << endl << "virtual answer:" << endl;
	test2.run();
	cout << "correct answer:" << endl << 30 << endl << 20 << endl << 125 << endl << 5 << endl;
	cout << "-----------------------------------------------" << endl;

	Lexer test3("test3.s");
	cout << "test 3:" << endl << "virtual answer:" << endl;
	test3.run();
	cout << "correct answer:" << endl << 1 << endl << 1 << endl << 0 << endl << 1 << endl << 0 << endl << 0 << endl;
	cout << "-----------------------------------------------" << endl;

	Lexer test4("test4.s");
	cout << "test 4:" << endl << "virtual answer:" << endl;
	test4.run();
	cout << "correct answer:" << endl << -43 << endl << -38 << endl << -38 << endl << -43 << endl;
	cout << "-----------------------------------------------" << endl;

	Lexer test5("test5.s");
	cout << "test 5:" << endl << "virtual answer:" << endl;
	test5.run();
	cout << "correct answer:" << endl << 2 << endl << 6 << endl << 12 << endl << 20 << endl;
	cout << "-----------------------------------------------" << endl;

	Lexer test6("test6.s");
	cout << "test 6:" << endl << "virtual answer:" << endl;
	test6.run();
	cout << "correct answer:" << endl << -570 << endl << -855 << endl;
	cout << "-----------------------------------------------" << endl;

	Lexer test7("test7.s");
	cout << "test 7:" << endl << "virtual answer:" << endl;
	test7.run();
	cout << "correct answer:" << endl << 125 << endl << 36 << endl << 1024 << endl;
	cout << "-----------------------------------------------" << endl;

	Lexer test8("test8.s");
	cout << "test 8:" << endl << "virtual answer:" << endl;
	test8.run();
	cout << "correct answer:" << endl << 1 << endl << 1 << endl << 2 << endl << 3 << endl << 5 << endl << 8 << endl << 13 << endl;
	cout << "-----------------------------------------------" << endl;
	
	Lexer test9("test9.s");
	cout << "test 9:" << endl << "virtual answer:" << endl;
	test9.run();
	cout << "correct answer:" << endl << 120 << endl;
	cout << "-----------------------------------------------" << endl;

	/*
	
	you can add tests:


	Lexer customtest("");
	cout << "test 10:" << endl << "virtual answer:" << endl;
	customtest.run();
	cout << "correct answer:" << endl <<  << endl;
	cout << "-----------------------------------------------" << endl;
	*/

	return 0;
}
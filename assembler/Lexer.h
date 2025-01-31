#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <sstream>


using namespace std;

class Lexer {

public:
	
	Lexer(string assemble_file_name);
	void run();
	~Lexer();

private:
	vector <string> script;
	map<string, int> labels;
	void* stack = malloc(100000);
	// ra = registers[1]
	// sp = registers[2]
	int registers[32];
	int main;
};

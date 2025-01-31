#include "Lexer.h"

#define sp registers[2];
#define ra registers[1];

Lexer::Lexer(string assemble_file_name) {
	
	registers[0] = 0;
	registers[2] = 100000;

	ifstream assemble_file(assemble_file_name);
	
	string curr;
	int line = 0;
	if (assemble_file.is_open()) {
		while (assemble_file.good())
		{
			getline(assemble_file,curr);
			if (curr == "") {
				continue;
			}
			else if (curr[curr.size() - 1] == ':') {
				labels.emplace(curr.substr(0, curr.size() - 1), line);
				if (curr == "main:")
					main = line;
			}
			script.push_back(curr);
			line++;
		}
	}

}

void Lexer::run() {

	for (int i = main; i < script.size(); i++) {
		
		string curr = script[i];
		
		//cout << curr << endl;

		if (curr == "" || curr[0] == '#' || curr[curr.size() - 1] == ':')
			continue;

		if (curr == "ecall") {
			if (registers[10] == 1)
				cout << registers[11] << endl;
			else if (registers[10] == 10)
				return;
		}
		else {

			vector <string> arguments;
			char del = ' ';
			stringstream sstream(curr);
			string word;
			while (getline(sstream, word, del)) arguments.push_back(word);
			string command = arguments[0];
				
			if (command == "li") {
				int dest = stoi(arguments[1].substr(1, arguments[1].size() - 1));
				int immediate = stoi(arguments[2]);
				registers[dest] = immediate;
			}
			else if (command == "add") {
					
				int dest;
				if (arguments[1] == "sp")
					dest = 2;
				else if (arguments[1] == "ra")
					dest = 1;
				else
					dest = stoi(arguments[1].substr(1, arguments[1].size() - 1));

				int arg1;
				if (arguments[2] == "sp")
					arg1 = 2;
				else if (arguments[2] == "ra")
					arg1 = 1;
				else
					arg1 = stoi(arguments[2].substr(1, arguments[2].size() - 1));

				int arg2;
				if (arguments[3] == "sp")
					arg2 = 2;
				else if (arguments[3] == "ra")
					arg2 = 1;
				else
					arg2 = stoi(arguments[3].substr(1, arguments[3].size() - 1));

				registers[dest] = registers[arg1] + registers[arg2];
			}
			else if (command == "addi") {

				int dest;
				if (arguments[1] == "sp")
					dest = 2;
				else if (arguments[1] == "ra")
					dest = 1;
				else
					dest = stoi(arguments[1].substr(1, arguments[1].size() - 1));

				int arg1;
				if (arguments[2] == "sp")
					arg1 = 2;
				else if (arguments[2] == "ra")
					arg1 = 1;
				else
					arg1 = stoi(arguments[2].substr(1, arguments[2].size() - 1));

				int arg2 = stoi(arguments[3]);

				registers[dest] = registers[arg1] + arg2;
			}
			else if (command == "mul") {

				int dest;
				if (arguments[1] == "sp")
					dest = 2;
				else if (arguments[1] == "ra")
					dest = 1;
				else
					dest = stoi(arguments[1].substr(1, arguments[1].size() - 1));

				int arg1;
				if (arguments[2] == "sp")
					arg1 = 2;
				else if (arguments[2] == "ra")
					arg1 = 1;
				else
					arg1 = stoi(arguments[2].substr(1, arguments[2].size() - 1));

				int arg2;
				if (arguments[3] == "sp")
					arg2 = 2;
				else if (arguments[3] == "ra")
					arg2 = 1;
				else
					arg2 = stoi(arguments[3].substr(1, arguments[3].size() - 1));

				registers[dest] = registers[arg1] * registers[arg2];
			}
			else if (command == "muli") {

				int dest;
				if (arguments[1] == "sp")
					dest = 2;
				else if (arguments[1] == "ra")
					dest = 1;
				else
					dest = stoi(arguments[1].substr(1, arguments[1].size() - 1));

				int arg1;
				if (arguments[2] == "sp")
					arg1 = 2;
				else if (arguments[2] == "ra")
					arg1 = 1;
				else
					arg1 = stoi(arguments[2].substr(1, arguments[2].size() - 1));

				int arg2 = stoi(arguments[3]);

				registers[dest] = registers[arg1] * arg2;
			}
			else if (command == "sub") {
				int dest;
				if (arguments[1] == "sp")
					dest = 2;
				else if (arguments[1] == "ra")
					dest = 1;
				else
					dest = stoi(arguments[1].substr(1, arguments[1].size() - 1));

				int arg1;
				if (arguments[2] == "sp")
					arg1 = 2;
				else if (arguments[2] == "ra")
					arg1 = 1;
				else
					arg1 = stoi(arguments[2].substr(1, arguments[2].size() - 1));

				int arg2;
				if (arguments[3] == "sp")
					arg2 = 2;
				else if (arguments[3] == "ra")
					arg2 = 1;
				else
					arg2 = stoi(arguments[3].substr(1, arguments[3].size() - 1));

				registers[dest] = (registers[arg1] - registers[arg2]);
			}
			else if (command == "subi") {

				int dest;
				if (arguments[1] == "sp")
					dest = 2;
				else if (arguments[1] == "ra")
					dest = 1;
				else
					dest = stoi(arguments[1].substr(1, arguments[1].size() - 1));

				int arg1;
				if (arguments[2] == "sp")
					arg1 = 2;
				else if (arguments[2] == "ra")
					arg1 = 1;
				else
					arg1 = stoi(arguments[2].substr(1, arguments[2].size() - 1));

				int arg2 = stoi(arguments[3]);

				registers[dest] = registers[arg1] - arg2;
			}
			else if (command == "dev") {
				int dest;
				if (arguments[1] == "sp")
					dest = 2;
				else if (arguments[1] == "ra")
					dest = 1;
				else
					dest = stoi(arguments[1].substr(1, arguments[1].size() - 1));

				int arg1;
				if (arguments[2] == "sp")
					arg1 = 2;
				else if (arguments[2] == "ra")
					arg1 = 1;
				else
					arg1 = stoi(arguments[2].substr(1, arguments[2].size() - 1));

				int arg2;
				if (arguments[3] == "sp")
					arg2 = 2;
				else if (arguments[3] == "ra")
					arg2 = 1;
				else
					arg2 = stoi(arguments[3].substr(1, arguments[3].size() - 1));

				registers[dest] = registers[arg1] / registers[arg2];
			}
			else if (command == "devi") {

				int dest;
				if (arguments[1] == "sp")
					dest = 2;
				else if (arguments[1] == "ra")
					dest = 1;
				else
					dest = stoi(arguments[1].substr(1, arguments[1].size() - 1));

				int arg1;
				if (arguments[2] == "sp")
					arg1 = 2;	
				else if (arguments[2] == "ra")
					arg1 = 1;
				else
					arg1 = stoi(arguments[2].substr(1, arguments[2].size() - 1));

				int arg2 = stoi(arguments[3]);

				registers[dest] = registers[arg1] / arg2;
			}
			else if (command == "sw" || command == "sh" || command == "sb") {

				int index;
				if (arguments[1] == "sp")
					index = 2;
				else if (arguments[1] == "ra")
					index = 1;
				else
					index = stoi(arguments[1].substr(1, arguments[1].size() - 1));

				int addition = (int)(arguments[2][0] - '0');
				string pointer = arguments[2].substr(arguments[2].find('(') + 1, arguments[2].size() - 3);
				char* dest = (char*)stack + addition;
				if (pointer == "sp")
					dest += registers[2];
				else if (pointer == "ra")
					dest += registers[1];
				else
					dest += stoi(pointer.substr(1, pointer.size() - 1));

				if(command == "sw")
					*(int*)dest = registers[index];
				else if(command == "sh")
					*(short*)dest = (short)registers[index];
				else if (command == "sb")
					*dest = (char)registers[index];

			}
			else if (command == "lw" || command == "lh" || command == "lb") {

				int index;
				if (arguments[1] == "sp")
					index = 2;
				else if (arguments[1] == "ra")
					index = 1;
				else
					index = stoi(arguments[1].substr(1, arguments[1].size() - 1));

				int addition = (int)(arguments[2][0] - '0');
				string pointer = arguments[2].substr(arguments[2].find('(') + 1, arguments[2].size() - 3);
				char* dest = (char*)stack + addition;
				if (pointer == "sp")
					dest += registers[2];
				else if (pointer == "ra")
					dest += registers[1];
				else
					dest += stoi(pointer.substr(1, pointer.size() - 1));

				if (command == "lw")
					registers[index] = *(int*)dest;
				else if (command == "lh")
					registers[index] = *(short*)dest;
				else if (command == "lb")
					registers[index] = *dest;

			}
			else if (command == "j") {
				i = labels[arguments[1]];
			}
			else if (command == "call" || command == "jal") {
				registers[1] = i;
				i = labels[arguments[1]];
			}
			else if (command == "jr" || command == "jalr") {

				int index;
				if (arguments[1] == "sp")
					index = 2;
				else if (arguments[1] == "ra")
					index = 1;
				else
					index = stoi(arguments[1].substr(1, arguments[1].size() - 1));

				if (command == "jalr")
					registers[1] = i;

				i = registers[index];
			}
			else if (command == "ret") {
				i = registers[1];
			}
			else if (command == "mv") {

				int rd;
				if (arguments[1] == "sp")
					rd = 2;
				else if (arguments[1] == "ra")
					rd = 1;
				else
					rd = stoi(arguments[1].substr(1, arguments[1].size() - 1));

				int rs1;
				if (arguments[2] == "sp")
					rs1 = 2;
				else if (arguments[2] == "ra")
					rs1 = 1;
				else
					rs1 = stoi(arguments[2].substr(1, arguments[2].size() - 1));

				registers[rd] = registers[rs1];
			}
			else if (command == "beq" || command == "bne" || command == "blt" || command == "bge" || command == "bgt" || command == "ble") {

				int rs1;
				if (arguments[1] == "sp")
					rs1 = 2;
				else if (arguments[1] == "ra")
					rs1 = 1;
				else
					rs1 = stoi(arguments[1].substr(1, arguments[1].size() - 1));

				int rs2;
				if (arguments[2] == "sp")
					rs2 = 2;
				else if (arguments[2] == "ra")
					rs2 = 1;
				else
					rs2 = stoi(arguments[2].substr(1, arguments[2].size() - 1));

				int dest = labels[arguments[3]];

				if (command == "beq" && registers[rs1] == registers[rs2])
					i = dest;
				else if (command == "bne" && registers[rs1] != registers[rs2])
					i = dest;
				else if (command == "blt" && registers[rs1] < registers[rs2])
					i = dest;
				else if (command == "bge" && registers[rs1] >= registers[rs2])
					i = dest;
				else if (command == "bgt" && registers[rs1] > registers[rs2])
					i = dest;
				else if (command == "ble" && registers[rs1] <= registers[rs2])
					i = dest;
			}
		}
	}

}

Lexer::~Lexer()
{
	free(stack);
}

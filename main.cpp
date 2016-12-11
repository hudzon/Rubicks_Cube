#include "main.h"

using namespace std;

int main(int argc, char* argv[]) {
	int mass[6][3][3];
	string error = "";
	Cube cube;

	if (argc < 2) {
		cout << "No input file!" << endl;
		system("PAUSE");
		return 0;
	}
	if (argc < 3) {
		cout << "No output file!" << endl;
		system("PAUSE");
		return 0;
	}
	if (argc > 3) {
		cout << "Too much arguments!" << endl;
		system("PAUSE");
		return 0;
	}

	error = readFile(argv[1], mass);

	if (error == "") {
		cube = Cube(mass);
		cube.assemble();

		if (!cube.isAssembly()) {
			error = "It is impossible to assemble Rubick's cube, because he was mechanically disassembled!\n";
		}
		else if (writeFile(argv[2], cube.getScramble())) {
				cout << "Sucñess!" << endl;
			}
			else {
				cout << "Error writing to file!" << endl;
				system("PAUSE");
			}
	}

	if (error != "") {
		ofstream fout(argv[2]);
		fout << error;
		fout.close();
	}
	return 0;
}

string readFile(char* nameFile, int mass[6][3][3]) {
	ifstream fin(nameFile);
	int checkColors[6];

	for (int i = 0; i < 6; i++)
		checkColors[i] = 0;

	if (!fin.is_open()) {
		fin.close();
		return "File isn't open!\n";
	}

	int k = 0;
	while (!fin.eof()) {
		string buff = "";

		if (!(k % 3) && (k != 0))
			getline(fin, buff);
		getline(fin, buff);

		if (!lineFormat(buff)) {
			fin.close();
			stringstream out;
			out << k + 1;
			return string("Line number " + out.str() + " have wrong format of input data!\n");
		}

		if (k > 17) {
			fin.close();
			return "Too much lines in input  file!\n";
		}

		for (int i = 0; i < 3; i++) {
			mass[k / 3][k % 3][i] = (int)buff[i * 2] - 48;
			checkColors[(int)buff[i * 2] - 48]++;
		}
		k++;
	}

	if (k < 18) {
		fin.close();
		return "Little lines in input file!\n";
	}

	for (int i = 0; i < 6; i++) {
		if (checkColors[i] != 9) {
			fin.close();
			return "Input data don't match with Rubick's cube!\n";
		}
	}

	fin.close();

	return "";
}

bool writeFile(char* nameFile, string str) {
	ofstream fout(nameFile);

	fout << str;

	fout.close();

	ifstream check(nameFile);
	
	string buff = "";
	getline(check, buff);

	if (buff != str) {
		check.close();
		return false;

	}

	check.close();

	return true;
}

bool lineFormat(string line) {
	bool equals = line.length() == 5 ? true : false;
	for (int i = 0; (i < line.length()) && equals; i = i + 2)
	{
		if (((int)line[i] > 53) || ((int)line[i] < 48))
			equals = false;
	}
	
	return equals;
}

#include "main.h"

using namespace std;

int main(int argc, char* argv[]) {
	int mass[6][3][3];

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

	if (!readFile(argv[1], mass)) {
		system("PAUSE");
		return 0;
	}

	Cube cube(mass);

	cube.assemble();

	if (!cube.isAssembly()) {
		cout << "It is impossible to assemble Rubick's cube, because he was mechanically disassembled!" << endl;
		system("PAUSE");
		return 0;
	}

	if (writeFile(argv[2], cube.getScramble()))
		cout << "Sucñess!" << endl;
	else cout << "Error writing to file!" << endl;

	system("PAUSE");
	return 0;
}

bool readFile(char* nameFile, int mass[6][3][3]) {
	ifstream fin(nameFile);
	int checkColors[6];

	for (int i = 0; i < 6; i++)
		checkColors[i] = 0;

	if (!fin.is_open()) {
		cout << "File isn't open!\n";
		fin.close();
		return false;
	}

	int k = 0;
	while (!fin.eof()) {
		string buff = "";

		if (!(k % 3) && (k != 0))
			getline(fin, buff);
		getline(fin, buff);

		if (!lineFormat(buff)) {
			cout << "Line number " << k + 1 << " have wrong format of input data!" << endl;
			fin.close();
			return false;
		}

		if (k > 17) {
			cout << "Too much lines in input  file!" << endl;
			fin.close();
			return false;
		}

		for (int i = 0; i < 3; i++) {
			mass[k / 3][k % 3][i] = (int)buff[i * 2] - 48;
			checkColors[(int)buff[i * 2] - 48]++;
		}
		k++;
	}

	if (k < 18) {
		cout << "Little lines in input file!" << endl;
		fin.close();
		return false;
	}

	for (int i = 0; i < 6; i++) {
		if (checkColors[i] != 9) {
			cout << "Input data don't match with Rubick's cube!" << endl;
			fin.close();
			return false;
		}
	}

	fin.close();

	return true;
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
	for (int i = 0; i < line.length() && equals; i = i + 2)
	{
		if (((int)line[i] > 53) || ((int)line[i] < 48))
			equals = false;
	}
	
	return equals;
}

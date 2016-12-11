#include <Windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "main.h"
using namespace std;

class TestCube:public Cube {
public:
	TestCube(int sides[6][3][3]) : Cube(sides) {
	}

	void test1();
	void test2();
	void test3();
};

bool IsProcessPresent(const wchar_t * szExe);
void unitTests();

int main(int argc, char* argv[]) {
	int n,m;
	string* input;
	string* output;
	string check1, check2;
	char buf[100];

	if (argc < 2) {
		cout << "No input file!" << endl;
		system("PAUSE");
		return 0;
	}
	if (argc > 2) {
		cout << "Too much arguments!" << endl;
		system("PAUSE");
		return 0;
	}
	
	{
		ifstream fin(argv[1]);
		string buff;

		if (!fin.is_open()) {
			cout << "File isn't open!\n";
			fin.close();
			system("PAUSE");
			return 0;
		}

		fin >> n >> m;
		cout << m;
		input = new string[n + m];
		output = new string[n + m];

		getline(fin,input[0]);
		for (int i = 0; i < n + m; i++) {
			getline(fin, input[i]);
			getline(fin, output[i]);
		}

		fin.close();
	}

	cout << "In/out tests:\n";
	for (int i = 0; i < n + m; i++) {
		stringstream out;
		out << i + 1;

		memset(buf, 0, sizeof(buf));

		strncpy_s(buf, string("start RubicksCube.exe " + input[i] + " " + out.str() + "out.txt").c_str(), sizeof(buf)-1);
		
		wstring wNameProg;
		string nameProg = "RubicksCube.exe";
		for (int i = 0; i < nameProg.length(); ++i)
			wNameProg += wchar_t(nameProg[i]);

		system(buf); 
		while (IsProcessPresent(wNameProg.c_str())) {

		}

		{
			ifstream fin(output[i]);

			if (!fin.is_open()) {
				fin.close();
				cout << input[i] << " isn't open!\n";
			}

			getline(fin, check1);

			fin.close();
		}
		{
			ifstream fin(out.str() + "out.txt");

			if (!fin.is_open()) {
				fin.close();
				cout << out.str() << "out.txt" << " isn't open!\n";
			}

			getline(fin, check2);

			fin.close();
		}

		if (check1 == check2) {
			cout << "  test" << out.str()  << "\t\t\tOK\n";
		}
		else cout << "  test" << out.str() << "\t\t\tFAILED\n";

		if (i == (n - 1)) {
			cout << "Main tests:\n";
		}
	}

	delete[] input;
	delete[] output;

	unitTests();


	system("PAUSE");
	return 0;
}

bool IsProcessPresent(const wchar_t * szExe)
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(PROCESSENTRY32);
	Process32First(hSnapshot, &pe);

	if (!_wcsicmp((wchar_t *)&pe.szExeFile, szExe))
	{
		return true;
	}

	while (Process32Next(hSnapshot, &pe))
	{
		if (!_wcsicmp((wchar_t *)&pe.szExeFile, szExe))
		{
			return true;
		}
	}

	return false;
}

void unitTests() {
	int mass[6][3][3];
	bool check = false;

	for (int s = 0; s < 6; s++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				mass[s][i][j] = s;
			}
		}
	}

	TestCube cube(mass);

	cout << "Unit tests:\n";
	cube.test1();
	cube.test2();
	cube.test3();
}

void TestCube::test1() {
	bool check = false;
	int mass[6][3][3] = { { { 2, 2, 2 },
							{ 0, 0, 0 },
							{ 0, 0, 0 } },
						  { { 1, 1, 1 },
							{ 1, 1, 1 },
							{ 1, 1, 1 } },
						  { { 2, 2, 3 },
							{ 2, 2, 3 },
							{ 2, 2, 3 } },
						  { { 3, 3, 3 },
							{ 3, 3, 3 },
							{ 5, 5, 5 } },
						  { { 4, 4, 4 },
							{ 4, 4, 4 },
							{ 4, 4, 4 } },
						  { { 0, 5, 5 },
							{ 0, 5, 5 },
							{ 0, 5, 5 } } };
	rotateL(GREEN);

	for (int s = 0; s < 6; s++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (mass[s][i][j] == sides[s][i][j])
					check = true;
			}
		}
	}

	if (check)
		cout << "  test rotateL\t\tOK\n";
	else cout << "  test rotateL\t\tFAILED\n";
}

void TestCube::test2() {
	bool check = false;
	int mass[6][3][3] = { { { 5, 5, 5 },
							{ 0, 0, 0 },
							{ 0, 0, 0 } },
						  { { 1, 1, 1 },
							{ 1, 1, 1 },
							{ 1, 1, 1 } },
						  { { 2, 2, 0 },
							{ 2, 2, 0 },
							{ 2, 2, 0 } },
						  { { 3, 3, 3 },
							{ 3, 3, 3 },
							{ 2, 2, 2 } },
						  { { 4, 4, 4 },
							{ 4, 4, 4 },
							{ 4, 4, 4 } },
						  { { 3, 5, 5 },
							{ 3, 5, 5 },
							{ 3, 5, 5 } } };
	rotateR(GREEN);

	for (int s = 0; s < 6; s++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (mass[s][i][j] == sides[s][i][j])
					check = true;
			}
		}
	}

	if (check)
		cout << "  test rotateR\t\tOK\n";
	else cout << "  test rotateR\t\tFAILED\n";
}

void TestCube::test3() {

	if (fitnessFunc() == 531441)
		cout << "  test finess func\tOK\n";
	else cout << "  test finess func\tFAILED\n";
}

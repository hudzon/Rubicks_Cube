#include "main.h"

class Cube {
public:
	Cube();
	Cube(int sides[6][3][3]);

	void assemble();

	bool isAssembly() const;

	std::string getScramble() const;
	void print();  

	int fitnessFunc() const;

	Cube operator=(Cube cube);

private:
	int fitness;
	int sides[6][3][3];
	std::string scramble;
	std::string twistLang;

	Cube rotateR(int side) const;
	Cube rotateL(int side) const;

	void swap(int &x, int &y);
};

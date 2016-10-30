#include "main.h"

class Cube {
public:
	Cube();
	Cube(int sides[6][3][3]);

	void rotateR(int side);
	void rotateL(int side);

	void assemble();

	bool isAssembly();

	std::string getScramble();

private:
	int sides[6][3][3];
	std::string scramble;
};

#pragma once
#include "main.h"

void Cube::swap(int &x, int &y) {
	int buf = x;
	x = y;
	y = buf;
}

void Cube::print() {
	for (int s = 0; s < 6; s++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::cout << sides[s][i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << scramble << std::endl;
}

int Cube::fitnessFunc() const{
  int mass[6];
  int sum = 1;
  int max = 0;

  for (int i = 0; i < 6; i++) {
	  mass[i] = 0;
  }
  //version 1
  for (int s = 0; s < 6; s++) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        mass[sides[s][i][j]]++;
      }
    }

    for (int i = 0; i < 6; i++) {
      if (mass[i])
        max++;
      mass[i] = 0;
    }
    sum *= 9 / max;
    max = 0;
  }

  return sum;
}

Cube::Cube() {
	for (int s = 0; s < 6; s++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				sides[s][i][j] = s;
			}
		}
	}
	fitness = 0;

	scramble = "";
	twistLang = "DFLUBR";
}

Cube::Cube(int sides[6][3][3]) {
	for (int s = 0; s < 6; s++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				this->sides[s][i][j] = sides[s][i][j];
			}
		}
  }
  fitness = fitnessFunc();
  scramble = "";
  twistLang = "DFLUBR";

}

Cube Cube::rotateR(int side) const{
	Cube newCube = *this;

	// переставл€ю боковушки стороны
	newCube.swap(newCube.sides[side][0][1], newCube.sides[side][1][2]);
	newCube.swap(newCube.sides[side][0][1], newCube.sides[side][1][0]);
	newCube.swap(newCube.sides[side][2][1], newCube.sides[side][1][0]);

	//переставл€ю углы стороны
	newCube.swap(newCube.sides[side][0][0], newCube.sides[side][0][2]);
	newCube.swap(newCube.sides[side][0][0], newCube.sides[side][2][0]);
	newCube.swap(newCube.sides[side][2][0], newCube.sides[side][2][2]);

	switch (side)
	{
	case WHITE:
		for (int i = 0; i < 3; i++) {
      newCube.swap(newCube.sides[GREEN][2][i], newCube.sides[ORANGE][2][i]);
      newCube.swap(newCube.sides[GREEN][2][i], newCube.sides[RED][2][i]);
      newCube.swap(newCube.sides[BLUE][2][i], newCube.sides[RED][2][i]);
		}
		break;
	case GREEN:
		for (int i = 0; i < 3; i++) {
      newCube.swap(newCube.sides[WHITE][0][i], newCube.sides[RED][i][2]);
      newCube.swap(newCube.sides[WHITE][0][i], newCube.sides[ORANGE][2 - i][0]);
      newCube.swap(newCube.sides[YELLOW][2][2 - i], newCube.sides[ORANGE][2 - i][0]);
		}
		break;
	case RED:
		for (int i = 0; i < 3; i++) {
      newCube.swap(newCube.sides[WHITE][2 - i][0], newCube.sides[BLUE][i][2]);
      newCube.swap(newCube.sides[WHITE][2 - i][0], newCube.sides[GREEN][2 - i][0]);
      newCube.swap(newCube.sides[YELLOW][2 - i][0], newCube.sides[GREEN][2 - i][0]);
		}
		break;
	case YELLOW:
		for (int i = 0; i < 3; i++) {
      newCube.swap(newCube.sides[GREEN][0][i], newCube.sides[RED][0][i]);
      newCube.swap(newCube.sides[GREEN][0][i], newCube.sides[ORANGE][0][i]);
      newCube.swap(newCube.sides[BLUE][0][i], newCube.sides[ORANGE][0][i]);
		}
		break;
	case BLUE:
		for (int i = 0; i < 3; i++) {
      newCube.swap(newCube.sides[WHITE][2][2 - i], newCube.sides[ORANGE][i][2]);
      newCube.swap(newCube.sides[WHITE][2][2 - i], newCube.sides[RED][2 - i][0]);
      newCube.swap(newCube.sides[YELLOW][0][i], newCube.sides[RED][2 - i][0]);
		}
		break;
	case ORANGE:
		for (int i = 0; i < 3; i++) {
      newCube.swap(newCube.sides[WHITE][i][2], newCube.sides[GREEN][i][2]);
      newCube.swap(newCube.sides[WHITE][i][2], newCube.sides[BLUE][2 - i][0]);
      newCube.swap(newCube.sides[YELLOW][i][2], newCube.sides[BLUE][2 - i][0]);
		}
		break;
	}

	newCube.fitness = newCube.fitnessFunc();
	newCube.scramble = scramble;

	return newCube;
}

Cube Cube::rotateL(int side) const{
  Cube newCube = *this;

	// переставл€ю боковушки стороны
  newCube.swap(newCube.sides[side][0][1], newCube.sides[side][1][0]);
  newCube.swap(newCube.sides[side][0][1], newCube.sides[side][1][2]);
  newCube.swap(newCube.sides[side][2][1], newCube.sides[side][1][2]);

	//переставл€ю углы стороны
  newCube.swap(newCube.sides[side][0][0], newCube.sides[side][2][0]);
  newCube.swap(newCube.sides[side][0][0], newCube.sides[side][0][2]);
  newCube.swap(newCube.sides[side][2][2], newCube.sides[side][0][2]);

	switch (side)
	{
	case WHITE:
		for (int i = 0; i < 3; i++) {
      newCube.swap(newCube.sides[GREEN][2][i], newCube.sides[RED][2][i]);
      newCube.swap(newCube.sides[GREEN][2][i], newCube.sides[ORANGE][2][i]);
      newCube.swap(newCube.sides[BLUE][2][i], newCube.sides[ORANGE][2][i]);
		}
		break;
	case GREEN:
		for (int i = 0; i < 3; i++) {
      newCube.swap(newCube.sides[WHITE][0][i], newCube.sides[ORANGE][2 - i][0]);
      newCube.swap(newCube.sides[WHITE][0][i], newCube.sides[RED][i][2]);
      newCube.swap(newCube.sides[YELLOW][2][2 - i], newCube.sides[RED][i][2]);
		}
		break;
	case RED:
		for (int i = 0; i < 3; i++) {
      newCube.swap(newCube.sides[WHITE][2 - i][0], newCube.sides[GREEN][2 - i][0]);
      newCube.swap(newCube.sides[WHITE][2 - i][0], newCube.sides[BLUE][i][2]);
      newCube.swap(newCube.sides[YELLOW][2 - i][0], newCube.sides[BLUE][i][2]);
		}
		break;
	case YELLOW:
		for (int i = 0; i < 3; i++) {
      newCube.swap(newCube.sides[GREEN][0][i], newCube.sides[ORANGE][0][i]);
      newCube.swap(newCube.sides[GREEN][0][i], newCube.sides[RED][0][i]);
      newCube.swap(newCube.sides[BLUE][0][i], newCube.sides[RED][0][i]);
		}
		break;
	case BLUE:
		for (int i = 0; i < 3; i++) {
      newCube.swap(newCube.sides[WHITE][2][2 - i], newCube.sides[RED][2 - i][0]);
      newCube.swap(newCube.sides[WHITE][2][2 - i], newCube.sides[ORANGE][i][2]);
      newCube.swap(newCube.sides[YELLOW][0][i], newCube.sides[ORANGE][i][2]);
		}
		break;
	case ORANGE:
		for (int i = 0; i < 3; i++) {
      newCube.swap(newCube.sides[WHITE][i][2], newCube.sides[BLUE][2 - i][0]);
      newCube.swap(newCube.sides[WHITE][i][2], newCube.sides[GREEN][i][2]);
      newCube.swap(newCube.sides[YELLOW][i][2], newCube.sides[GREEN][i][2]);
		}
		break;
	}

  newCube.fitness = newCube.fitnessFunc();
  newCube.scramble = scramble;

  return newCube;
}

void Cube::assemble() {
	if (isAssembly())
		return;

	//genetic algorithm
	srand(time(0));

	bool found = false;
	Cube cubePopulation[1600];
	int numberPop = 1;
	int curIndex = 0;
	int lastTwist[1600] = { 10 };
	int indexSurviveCube = 100;
	cubePopulation[0] = *this;
	int maxFitness = cubePopulation[0].fitness;

	for (int i = 0; (i < 20) && (!found); i++) {
		for (int j = 0; j < numberPop; j++) {
			for (int k = 0; k < 6; k++) {
				if (k != lastTwist[j]) {
					cubePopulation[100 + curIndex] = cubePopulation[j].rotateR(k);
					cubePopulation[100 + curIndex].scramble += twistLang[k];
					cubePopulation[100 + curIndex].scramble += " ";
					lastTwist[100 + curIndex] = k;
					curIndex++;

					cubePopulation[100 + curIndex] = cubePopulation[j].rotateL(k);
					cubePopulation[100 + curIndex].scramble += twistLang[k];
					cubePopulation[100 + curIndex].scramble += "' ";
					lastTwist[100 + curIndex] = k;
					curIndex++;

					cubePopulation[100 + curIndex] = cubePopulation[j].rotateR(k);
					cubePopulation[100 + curIndex] = cubePopulation[j].rotateR(k);
					cubePopulation[100 + curIndex].scramble += "2";
					cubePopulation[100 + curIndex].scramble += twistLang[k];
					cubePopulation[100 + curIndex].scramble += " ";
					lastTwist[100 + curIndex] = k;
					curIndex++;
				}
			}
		}

		for (int j = 0; j < 100; j++) {
			for (int k = 100; k < 1600; k++) {
				if (cubePopulation[indexSurviveCube].fitness < cubePopulation[k].fitness)
					indexSurviveCube = k;
			}

			lastTwist[j] = lastTwist[indexSurviveCube];
			cubePopulation[j] = cubePopulation[indexSurviveCube];
			cubePopulation[indexSurviveCube].fitness = 0;
		}
		/*if (i < 2)
			for (int j = 70; j < 100; j++) {
				cubePopulation[j] = cubePopulation[rand() % (18 + 18 * 14 * i) + 100];
			}
		else for (int j = 70; j < 100; j++) {
				cubePopulation[j] = cubePopulation[rand() % 1500 + 100];
			}*/
		numberPop = 100;
		curIndex = 0;
		
		if ((cubePopulation[0].isAssembly()) || ((cubePopulation[0].fitness - maxFitness) < 50))
			found = true;

		maxFitness = cubePopulation[0].fitness;
	}

	*this = cubePopulation[0];
}


bool Cube::isAssembly() const {
	for (int s = 0; s < 6; s++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if(sides[s][i][j] != s)
					return false;
			}
		}
	}

	return true;
}

std::string Cube::getScramble() const {
	return scramble;
}

Cube Cube::operator=(Cube cube) {
  for (int s = 0; s < 6; s++) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        this->sides[s][i][j] = cube.sides[s][i][j];
      }
    }
  }
  this->scramble = cube.scramble;
  this->fitness = fitnessFunc();

  return *this;
}

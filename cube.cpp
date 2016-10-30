#pragma once
#include "main.h"

void swap(int x, int y) {
	int buf = x;
	x = y;
	y = buf;
}

Cube::Cube() {
	for (int s = 0; s < 6; s++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				sides[s][i][j] = s;
			}
		}
	}
}

Cube::Cube(int sides[6][3][3]) {
	for (int s = 0; s < 6; s++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				this->sides[s][i][j] = sides[s][i][j];
			}
		}
	}
}

void Cube::rotateR(int side) {
	// переставл€ю боковушки стороны
	swap(sides[side][0][1], sides[side][1][2]);
	swap(sides[side][0][1], sides[side][1][0]);
	swap(sides[side][2][1], sides[side][1][0]);

	//переставл€ю углы стороны
	swap(sides[side][0][0], sides[side][0][2]);
	swap(sides[side][0][0], sides[side][2][0]);
	swap(sides[side][2][0], sides[side][2][2]);

	switch (side)
	{
	case WHITE:
		for (int i = 0; i < 3; i++) {
			swap(sides[GREEN][2][i], sides[ORANGE][2][i]);
			swap(sides[GREEN][2][i], sides[RED][2][i]);
			swap(sides[BLUE][2][i], sides[RED][2][i]);
		}
		break;
	case GREEN:
		for (int i = 0; i < 3; i++) {
			swap(sides[WHITE][0][i], sides[RED][i][2]);
			swap(sides[WHITE][0][i], sides[ORANGE][2 - i][0]);
			swap(sides[YELLOW][2][2 - i], sides[ORANGE][2 - i][0]);
		}
		break;
	case RED:
		for (int i = 0; i < 3; i++) {
			swap(sides[WHITE][2 - i][0], sides[BLUE][i][2]);
			swap(sides[WHITE][2 - i][0], sides[GREEN][2 - i][0]);
			swap(sides[YELLOW][2 - i][0], sides[GREEN][2 - i][0]);
		}
		break;
	case YELLOW:
		for (int i = 0; i < 3; i++) {
			swap(sides[GREEN][0][i], sides[RED][0][i]);
			swap(sides[GREEN][0][i], sides[ORANGE][0][i]);
			swap(sides[BLUE][0][i], sides[ORANGE][0][i]);
		}
		break;
	case BLUE:
		for (int i = 0; i < 3; i++) {
			swap(sides[WHITE][2][2 - i], sides[ORANGE][i][2]);
			swap(sides[WHITE][2][2 - i], sides[RED][2 - i][0]);
			swap(sides[YELLOW][0][i], sides[RED][2 - i][0]);
		}
		break;
	case ORANGE:
		for (int i = 0; i < 3; i++) {
			swap(sides[WHITE][i][2], sides[GREEN][i][2]);
			swap(sides[WHITE][i][2], sides[BLUE][2 - i][0]);
			swap(sides[YELLOW][i][2], sides[BLUE][2 - i][0]);
		}
		break;
	}
}

void Cube::rotateL(int side) {
	// переставл€ю боковушки стороны
	swap(sides[side][0][1], sides[side][1][0]);
	swap(sides[side][0][1], sides[side][1][2]);
	swap(sides[side][2][1], sides[side][1][2]);

	//переставл€ю углы стороны
	swap(sides[side][0][0], sides[side][2][0]);
	swap(sides[side][0][0], sides[side][0][2]);
	swap(sides[side][2][2], sides[side][0][2]);

	switch (side)
	{
	case WHITE:
		for (int i = 0; i < 3; i++) {
			swap(sides[GREEN][2][i], sides[RED][2][i]);
			swap(sides[GREEN][2][i], sides[ORANGE][2][i]);
			swap(sides[BLUE][2][i], sides[ORANGE][2][i]);
		}
		break;
	case GREEN:
		for (int i = 0; i < 3; i++) {
			swap(sides[WHITE][0][i], sides[ORANGE][2 - i][0]);
			swap(sides[WHITE][0][i], sides[RED][i][2]);
			swap(sides[YELLOW][2][2 - i], sides[RED][i][2]);
		}
		break;
	case RED:
		for (int i = 0; i < 3; i++) {
			swap(sides[WHITE][2 - i][0], sides[GREEN][2 - i][0]);
			swap(sides[WHITE][2 - i][0], sides[BLUE][i][2]);
			swap(sides[YELLOW][2 - i][0], sides[BLUE][i][2]);
		}
		break;
	case YELLOW:
		for (int i = 0; i < 3; i++) {
			swap(sides[GREEN][0][i], sides[ORANGE][0][i]);
			swap(sides[GREEN][0][i], sides[RED][0][i]);
			swap(sides[BLUE][0][i], sides[RED][0][i]);
		}
		break;
	case BLUE:
		for (int i = 0; i < 3; i++) {
			swap(sides[WHITE][2][2 - i], sides[RED][2 - i][0]);
			swap(sides[WHITE][2][2 - i], sides[ORANGE][i][2]);
			swap(sides[YELLOW][0][i], sides[ORANGE][i][2]);
		}
		break;
	case ORANGE:
		for (int i = 0; i < 3; i++) {
			swap(sides[WHITE][i][2], sides[BLUE][2 - i][0]);
			swap(sides[WHITE][i][2], sides[GREEN][i][2]);
			swap(sides[YELLOW][i][2], sides[GREEN][i][2]);
		}
		break;
	}
}

void Cube::assemble(){
	
	//main algorithm
	for (int s = 0; s < 6; s++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				sides[s][i][j] = s;
			}
		}
	}

}


bool Cube::isAssembly() {
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

std::string Cube::getScramble() {
	return scramble;
}

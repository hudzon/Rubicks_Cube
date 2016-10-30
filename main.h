#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "cube.h"


#define WHITE 0
#define GREEN 1
#define RED 2
#define YELLOW 3
#define BLUE 4
#define ORANGE 5

bool readFile(char* nameFile, int mass[6][3][3]);
bool writeFile(char* nameFile, std::string str);

bool lineFormat(std::string line);

#pragma once
#include <vector>
#include <string>
#include <vector>
#include "point.h"
using namespace std;

vector<Point> readPointsFromFile(const string& filename);
void createInputFile(const string& filename);

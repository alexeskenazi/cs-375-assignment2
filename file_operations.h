#pragma once
#include <vector>
#include <string>
#include "point.h"
using namespace std;

vector<Point> readPointsFromFile(const string& filename);
void writeOutputFile(const string& filename, int i, int j, long double distance);
void createInputFile(const string& filename, const vector<Point>& points);

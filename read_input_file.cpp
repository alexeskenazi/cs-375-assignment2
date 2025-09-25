#include "read_input_file.h"
#include <cstdio>
#include <iostream>

std::vector<Point> readPointsFromFile(const std::string& filename) {
	std::vector<Point> points;
	FILE* fp = fopen(filename.c_str(), "r");
	if (!fp) {
		std::cerr << "Error opening file: " << filename << std::endl;
		return points;
	}
	char line[256];
	while (fgets(line, sizeof(line), fp)) {
		// Skip empty lines and comments
		if (line[0] == '\n' || line[0] == '\0' || line[0] == '*' || line[0] == ':') continue;
		long long x, y, z = 0;
		int numRead = sscanf(line, "%lld %lld %lld", &x, &y, &z);
		if (numRead >= 2) {
			Point pt;
			pt.x = x;
			pt.y = y;
			pt.z = (numRead == 3) ? z : 0;
			points.push_back(pt);
		}
	}
	fclose(fp);
	return points;
}

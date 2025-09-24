#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cassert>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

#define BUFSIZE 1000

struct Point {
    long long x;
    long long y;
};

double bruteForceClosest(const vector<Point>& pts, int& bestI, int& bestJ);

FILE *srcFP, *destFP;
long long numLines, *data;

long double dist(const Point& a, const Point& b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return sqrt((long double)dx * dx + (long double)dy * dy);
}

int main(int argc, char *argv[]) {
    int n = 10000;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i) {
            p[i].x = n - i;
            p[i].y = n - i;
    }

    int iBest, jBest;
    clock_t t0 = clock();
    double bestDist = bruteForceClosest(p, iBest, jBest);
    clock_t t1 = clock();

    double ms = 1000.0 * (t1 - t0) / CLOCKS_PER_SEC;

    cout << "Brute-force closest pair:\n";
    cout << "  i = " << iBest << "  (" << p[iBest].x << ", " << p[iBest].y << ")\n";
    cout << "  j = " << jBest << "  (" << p[jBest].x << ", " << p[jBest].y << ")\n";
    cout << "  distance = " << bestDist << "\n";
    cout << "Time (ms): " << ms << "\n";
    return 0;

  return numLines;
}   


// go through all pairs of points and find the closest pair
double bruteForceClosest(const vector<Point>& pts, int& bestI, int& bestJ) {
    long double bestDist = 1e18; // novice-friendly large value
    bestI = -1; bestJ = -1;
    int n = (int)pts.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long double d = dist(pts[i], pts[j]);
            if (d < bestDist) {
                bestDist = d;
                bestI = i;
                bestJ = j;
            }
        }
    }
    return bestDist;
}
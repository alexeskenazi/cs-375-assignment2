#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cassert>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include "file_operations.h"

#define LARGE_NUMBER 1000000000000000000.0

using namespace std;

int test1();
int test2();
int test3();
int test4();

int runTest(std::__1::vector<Point> &p);

double bruteForceClosest(const vector<Point>& pts, int& bestI, int& bestJ) {
    long double bestDist = LARGE_NUMBER;  // largest value possible
    bestI = -1; bestJ = -1;
    int n = (int)pts.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
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

long double closestPairRec(vector<Point>& Px, vector<Point>& Py, int& bestI, int& bestJ) {
    int n = Px.size();
    int mid = n / 2;
    Point midPoint = Px[mid];

    vector<Point> Qx;
    vector<Point> Rx;
    
    // Copy left half
    for (int i = 0; i < mid; i++) {
        Qx.push_back(Px[i]);
    }
    
    // Copy right half
    for (int i = mid; i < n; i++) {
        Rx.push_back(Px[i]);
    }

    vector<Point> Qy, Ry;
    for (int i = 0; i < Py.size(); i++) {
        if (Py[i].x <= midPoint.x)
            Qy.push_back(Py[i]);
        else
            Ry.push_back(Py[i]);
    }

    int bestIL = -1, bestJL = -1, bestIR = -1, bestJR = -1;
    long double dl, dr;
    if (Qx.size() > 1) {
        dl = closestPairRec(Qx, Qy, bestIL, bestJL);
    } else {
        dl = LARGE_NUMBER;
    }
    
    if (Rx.size() > 1) {
        dr = closestPairRec(Rx, Ry, bestIR, bestJR);
    } else {
        dr = LARGE_NUMBER;
    }

    long double d = dl;
    int offset = 0;
    if (dr < dl) {
        d = dr;
        offset = mid;
        bestI = bestIR + offset;
        bestJ = bestJR + offset;
    } else {
        bestI = bestIL;
        bestJ = bestJL;
    }

    // Build strip
    vector<Point> strip;
    for (int i = 0; i < Py.size(); i++) {
        if (abs(Py[i].x - midPoint.x) < d)
            strip.push_back(Py[i]);
    }

    // Check strip for closer pairs
    for (int i = 0; i < (int)strip.size(); i++) {
        for (int j = i + 1; j < (int)strip.size() && (strip[j].y - strip[i].y) < d; j++) {
            long double d_strip = dist(strip[i], strip[j]);
            if (d_strip < d) {
                d = d_strip;
                // Find indices in Px
                for (int idx1 = 0; idx1 < n; idx1++) {
                    if (Px[idx1].x == strip[i].x && Px[idx1].y == strip[i].y) bestI = idx1;
                    if (Px[idx1].x == strip[j].x && Px[idx1].y == strip[j].y) bestJ = idx1;
                }
            }
        }
    }
    return d;
}

double divideAndConquerClosest(const vector<Point>& pts, int& bestI, int& bestJ) {
    vector<Point> Px = pts;
    vector<Point> Py = pts;
    std::sort(Px.begin(), Px.end(), compareX);
    std::sort(Py.begin(), Py.end(), compareY);
    return closestPairRec(Px, Py, bestI, bestJ);
}


int test1() {
    cout << "Test 1: Points in decreasing order\n";
    int n = 10000;
    vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        p[i].x = n - i;
        p[i].y = n - i;
        p[i].z = n - i;  // 3D diagonal
    }

    createInputFile2D("input2D-1.txt", p);
    createInputFile3D("input3D-1.txt", p);

    return runTest(p);
}

int test2() {
    cout << "\nTest 2: Points in increasing order\n";
    int n = 10000;
    vector<Point> p(n);
    int i;
    for(i=0; i<n; i++) {
        p[i].x= i*i;
        p[i].y= i*i;
        p[i].z= i;  // 3D curve
    }

    createInputFile2D("input2D-2.txt", p);
    createInputFile3D("input3D-2.txt", p);

    return runTest(p);
}

int test3() {
    cout << "\nTest 3: Odd positive X and even negative X\n";
    int n = 20000;
    vector<Point> p(n);
    int i;

    // Generate points according to teacher's specification
    for(i=0; i<n; i++) {
        if (i%2==0) {
            p[i].x= i;
        } else {
            p[i].x= -1*i;
        }
        p[i].y= int( sqrt( (9999*9999) - ( (i-10000))* (i-10000) ) );
        p[i].z= i % 100;  // 3D spiral-like pattern
    }

    createInputFile2D("input2D-3.txt", p);
    createInputFile3D("input3D-3.txt", p);

    return runTest(p);
}

int test4() {
    int n = 20000;
    vector<Point> p(n);
    int i;

    for(i=0; i<n; i++) {
        if (i%2==0) {
            p[i].x= i * (1 + i/n);
            p[i].y= i * (1 + 2/n);
            p[i].z= i/10;  // Positive z
        } else {
            p[i].x= -1*i * (1.1 + 3/n);
            p[i].y= -1*i * (1.9 + 4/n);
            p[i].z= -i/10;  // Negative z
        }
    }

    createInputFile2D("input2D-4.txt", p);
    createInputFile3D("input3D-4.txt", p);

    return runTest(p);
}

int runTest(vector<Point> &p) {
    int iBest, jBest;
    clock_t t0 = clock();
    double bestDist = bruteForceClosest(p, iBest, jBest);
    clock_t t1 = clock();

    double ms = 1000.0 * (t1 - t0) / CLOCKS_PER_SEC;

    cout << "Brute-force closest pair:\n";
    cout << "  i = " << iBest << "  (" << p[iBest].x << ", " << p[iBest].y << ", " << p[iBest].z << ")\n";
    cout << "  j = " << jBest << "  (" << p[jBest].x << ", " << p[jBest].y << ", " << p[jBest].z << ")\n";
    cout << "  distance = " << bestDist << "\n";
    cout << "Time (ms): " << ms << "\n";

    int iBestDC, jBestDC;
    clock_t t0dc = clock();
    double bestDistDC = divideAndConquerClosest(p, iBestDC, jBestDC);
    clock_t t1dc = clock();
    double msDC = 1000.0 * (t1dc - t0dc) / CLOCKS_PER_SEC;

    cout << "\nDivide and conquer closest pair:\n";
    cout << "  i = " << iBestDC << "  (" << p[iBestDC].x << ", " << p[iBestDC].y << ", " << p[iBestDC].z << ")\n";
    cout << "  j = " << jBestDC << "  (" << p[jBestDC].x << ", " << p[jBestDC].y << ", " << p[jBestDC].z << ")\n";
    cout << "  distance = " << bestDistDC << "\n";
    cout << "Time (ms): " << msDC << "\n";

    return 0;
}

int main(int argc, char *argv[]) {
    // run tests if "test" argument provided
    if(argc>1) {
        if(strcmp(argv[1], "test") == 0) {
            test1();
            test2();
            test3();
            test4();
            exit(0);
        }
    }

    // check command line args
    if(argc<3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        printf("Usage: %s test\n", argv[0]);
        exit(0);
    }

    vector<Point> p = readPointsFromFile(argv[1]);

    int iBest, jBest;
    clock_t t0 = clock();
    double bestDist = bruteForceClosest(p, iBest, jBest);
    clock_t t1 = clock();

    double ms = 1000.0 * (t1 - t0) / CLOCKS_PER_SEC;
    cout << "-------------------------------------------------------\n";
    cout << "Brute-force closest pair:\n";
    cout << "  i = " << iBest << "  (" << p[iBest].x << ", " << p[iBest].y << ", " << p[iBest].z << ")\n";
    cout << "  j = " << jBest << "  (" << p[jBest].x << ", " << p[jBest].y << ", " << p[jBest].z << ")\n";
    cout << "  distance = " << bestDist << "\n";
    cout << "Time (ms): " << ms << "\n";

    int iBestDC, jBestDC;
    clock_t t0dc = clock();
    double bestDistDC = divideAndConquerClosest(p, iBestDC, jBestDC);
    clock_t t1dc = clock();
    double msDC = 1000.0 * (t1dc - t0dc) / CLOCKS_PER_SEC;

    cout << "\nDivide and conquer closest pair:\n";
    cout << "  i = " << iBestDC << "  (" << p[iBestDC].x << ", " << p[iBestDC].y << ", " << p[iBestDC].z << ")\n";
    cout << "  j = " << jBestDC << "  (" << p[jBestDC].x << ", " << p[jBestDC].y << ", " << p[jBestDC].z << ")\n";
    cout << "  distance = " << bestDistDC << "\n";
    cout << "Time (ms): " << msDC << "\n";
    writeOutputFile(argv[2], iBestDC, jBestDC, bestDistDC);


    return 0;
}

#pragma once

struct Point {
    long long x;
    long long y;
    long long z;
};

bool compareX(const Point& a, const Point& b);
bool compareY(const Point& a, const Point& b);
long double dist(const Point& a, const Point& b);
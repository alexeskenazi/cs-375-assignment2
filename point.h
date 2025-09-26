#pragma once

struct Point {
    long long x;
    long long y;
    long long z;
};

inline bool compareX(const Point& a, const Point& b) {
    return a.x < b.x;
}

inline bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

inline long double dist(const Point& a, const Point& b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return sqrt((long double)dx * dx + (long double)dy * dy);
}
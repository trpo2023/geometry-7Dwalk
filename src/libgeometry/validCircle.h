#ifndef validCircle_h
#define validCircle_h

#include <iostream>
struct Point {
    double x;
    double y;
};

struct Circle {
    Point center;
    double radius;
    double area;
    double perimeter;
};

bool validCircle(const std::string& input, struct Circle& circle);

#endif
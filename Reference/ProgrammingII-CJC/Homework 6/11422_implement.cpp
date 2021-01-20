#include "11422.h"
#include <iostream>
#include <cmath>

using namespace oj;
using namespace std;

Triangle::Triangle(double edge1, double edge2, double edge3) {
    this->edge1 = edge1;
    this->edge2 = edge2;
    this->edge3 = edge3;

    if(edge1 <= 0 || edge2 <= 0 || edge3 <= 0) {
        setArea(0.0);
        setPerimeter(0.0);
    } else if ((edge1 + edge2) <= edge3 || (edge2 + edge3) <= edge1 || (edge1 + edge3) <= edge2) {
        setArea(0.0);
        setPerimeter(0.0);
    } else {
        double s = 0.5*(edge1 + edge2 + edge3);
        setArea(sqrt(s * (s-edge1) * (s-edge2) * (s-edge3)));
        setPerimeter(edge1 + edge2 + edge3);
    }
}

Rectangle::Rectangle(double width, double height) {
    this->width = width;
    this->height = height;

    if(width <= 0 || height <= 0) {
        setArea(0.0);
        setPerimeter(0.0);
    } else {
        setArea(width * height);
        setPerimeter(2 * (width + height));
    }
}

Circle::Circle(double radius, double pi) {
    this->radius = radius;
    this->pi = pi;

    if(radius <= 0 || pi <= 0) {
        setArea(0.0);
        setPerimeter(0.0);
    } else {
        setArea(pi * radius * radius);
        setPerimeter(2 * pi * radius);
    }
}
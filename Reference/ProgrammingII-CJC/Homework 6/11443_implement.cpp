#include "11443.h"
#include <iostream>

using namespace std;
using namespace oj;

Sphere::Sphere(double radius, double pi) {
    if(radius <= 0 || pi <= 0) {
        setVolume(0.0);
    } else 
        setVolume(4.0/3.0 * pi * radius * radius * radius);
}

Cone::Cone(double radius, double height, double pi) {
    if(radius <= 0 || height <= 0 || pi <= 0) {
        setVolume(0.0);
    } else 
        setVolume(1.0/3.0 * pi * radius * radius * height);
}

Cuboid::Cuboid(double length, double width, double height) {
    if(length <= 0 || width <= 0 || height <= 0) {
        setVolume(0.0);
    } else 
        setVolume(length * width * height);
}

Cube::Cube(double length): Cuboid(length, length, length) {}
#include "11484.h"
#include <iostream>

using namespace std;
using namespace oj;

void Rectangle::draw() {
    int x, y;
    for (int i=0; i<4; ++i) {
        cin >> x >> y;
        Point temp(x, y);
        points.push_back(temp);
    }

    Point p1 = points[0];
    Point p2(0, 0);
    for (int i=1; i<4; ++i){
        if(points[i].x != p1.x && points[i].y != p1.y)
            p2 = points[i];
    }
    // cout << p1.x << " " << p1.y << endl;
    // cout << p2.x << " " << p2.y << endl;

    area = abs(p1.x - p2.x) * abs(p1.y - p2.y);
}

void Circle::draw() {
    int x, y;
    cin >> x >> y;
    Point temp(x, y);
    points.push_back(temp);

    int radius;
    cin >> radius;

    if(radius <= 0) {
        area = 0;
    } else {
        area = PI * radius * radius;
    }
}
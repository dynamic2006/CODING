#include <iostream>
using namespace std;

class Point {
    public:
        int x,y;
        Point(int px, int py):x(px),y(py) {}
};

class Circle {
    public:
        int radius;
        Point b;
        Circle(int px, int py, int r):b(px,py),radius(r){}
        Circle(Circle &o):b(o.b),radius(o.radius){}
};

int main() {
    Circle c1(1,3,5);
    Circle c2 = c1;
    cout <<"("<< c1.b.x <<","<< c1.b.y << ")" << " r= " << c1.radius << endl;
    cout <<"("<< c2.b.x <<","<< c2.b.y << ")" << " r= " << c2.radius << endl;

}
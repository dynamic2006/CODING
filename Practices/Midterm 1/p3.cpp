#include <iostream>
#include <cassert>

using namespace std;

class Triangle{
    public:
        Triangle() {p = new Point[3];}

        Triangle(Triangle& t);
        Triangle& operator=(const Triangle& t);

        Triangle(int x1, int y1, int x2, int y2, int x3, int y3){
            p = new Point[3];
            p[0].x = x1; p[0].y = y1;
            p[1].x = x2; p[1].y = y2;
            p[2].x = x3; p[2].y = y3;
        }
        
        ~Triangle(){
            delete[] p;
            cout << "Deletion complete" << endl;
        }

        bool isSame(const Triangle &other){
            for(int i=0; i<3; i++){
                if (this->p[i].x != other.p[i].x || this->p[i].y != other.p[i].y) return false;
            }
            return true;
        }
    
    private:
        struct Point
        {
            int x,y;
            Point(int px=0, int py=0) : x(px), y(py) {}
        };
        Point* p;
    
};

Triangle::Triangle(Triangle& t){
    this->p = new Point [3];

    if(t.p != nullptr){
        for(int i=0; i<3; i++){
            this->p[i].x = t.p[i].x;
            this->p[i].y = t.p[i].y;
        }
    }
}

Triangle& Triangle::operator=(const Triangle& t){
    for(int i=0; i<3; i++){
        this->p[i].x = t.p[i].x;
        this->p[i].y = t.p[i].y;
    }

    return* this;
}

int main() {
    Triangle* array[3];
    array[0] = new Triangle(1,1,1,3,3,1);
    array[1] = new Triangle(2,2,2,6,6,2);
    array[2] = new Triangle(3,3,3,9,9,3);

    Triangle c2 = *array[0]; // uses copy constructor

    c2 = *array[1]; // uses assignment operator
    assert(c2.isSame(*array[1]));

    for(int i=0; i<3; i++){
        delete array[i];
    }
}
#include <iostream>
#include <algorithm>

using namespace std;

struct Rect
{
    Rect(int x1, int y1, int x2, int y2): bx(x1), by(y1), tx(x2), ty(y2) {base = x2 - x1; height = y2 - y1;}
    ~Rect() {};

    int bx, by, tx, ty, base, height;

};

int area(Rect a)
{
    return ((a.tx - a.bx) * (a.ty - a.by));
}

int base_intersection(Rect a, Rect b)
{
    int base = min(a.tx, b.tx) - max(a.bx, b.bx);
    if (base > 0)
        return (base);
    return 0;
}

int height_intersection(Rect a, Rect b)
{
    int height = min(a.ty, b.ty) - max(a.by, b.by);
    if (height > 0)
        return (height);
    return 0;
}

int solver(Rect lawn, Rect feed)
{

    if( base_intersection(lawn,feed) == lawn.base && height_intersection(lawn, feed) == lawn.height )
        return 0;

    if(base_intersection(lawn,feed) == lawn.base)
        return ((lawn.height - height_intersection(lawn, feed)) * lawn.base);
    
    if(height_intersection(lawn , feed) == lawn.height)
        return ((lawn.base - base_intersection(lawn, feed)) * lawn.height);
    
    return (area(lawn));

}


int main()
{
    freopen("billboard.in" , "r" , stdin);
    freopen("billboard.out" , "w" , stdout);

    int x1, y1, x2, y2;
    
    cin >> x1 >> y1 >> x2 >> y2;
    Rect lawn_board = Rect(x1, y1, x2, y2);

    cin >> x1 >> y1 >> x2 >> y2;
    Rect feed_board = Rect(x1, y1, x2, y2);

    cout << solver(lawn_board, feed_board);



}

//Note program works for most test cases, but to cover all of them consider the corners of the lawn mower board that are covered
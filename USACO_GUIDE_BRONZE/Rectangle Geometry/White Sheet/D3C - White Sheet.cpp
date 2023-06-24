#include <iostream>
#include <algorithm>

using namespace std;

struct Rectangle
{
    Rectangle(int x_1, int y_1, int x_2, int y_2): bot_x(x_1), bot_y(y_1), top_x(x_2), top_y(y_2) { base = top_x - bot_x; height = top_y - bot_y;}
    ~Rectangle() {}
    
    int bot_x, bot_y, top_x, top_y, base, height;

};

int base_intersection(Rectangle a, Rectangle b)
{
    int base = min(a.top_x, b.top_x) - max(a.bot_x, b.bot_x);
    if (base > 0)
        return (base);
    return 0;
}

int height_intersection(Rectangle a, Rectangle b)
{
    int height = min(a.top_y, b.top_y) - max(a.bot_y, b.bot_y);
    if (height > 0)
        return (height);
    return 0;
}

bool solver(Rectangle w, Rectangle b1, Rectangle b2)
{

    if( base_intersection(w,b1) == w.base && height_intersection(w,b1) == w.height )
        return true;
    if( base_intersection(w,b2) == w.base && height_intersection(w,b2) == w.height )
        return true;

    //case where one of the black rectangles covers whole of white
    if(base_intersection(w,b1) == w.base && base_intersection(w,b2) == w.base)
        if (( height_intersection(w , b1) + height_intersection(w , b2) - height_intersection(b1 , b2) ) == w.height)
            return true;
    
    if(height_intersection(w , b1) == w.height && height_intersection(w , b2) == w.height)
        if(( base_intersection(w , b1) + base_intersection(w , b2) - base_intersection(b1 , b2)) == w.base)
            return true;
    
    return false;

}

int main()
{
    // freopen("whitesheet.in", "r", stdin);
    // freopen("whitesheet.out", "w", stdout);

    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
    
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    cin >> x5 >> y5 >> x6 >> y6;

    Rectangle white = Rectangle(x1, y1, x2, y2);
    Rectangle black1 = Rectangle(x3, y3, x4, y4);
    Rectangle black2 = Rectangle(x5, y5, x6, y6);

    if (solver(white,black1,black2))
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
        
}
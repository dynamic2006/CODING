#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{

    freopen("square.in" , "r" , stdin);
    freopen("square.out" , "w" , stdout);
    
    int a_x1 , a_y1 , a_x2 , a_y2 , b_x1 , b_y1 , b_x2 , b_y2;

    cin >> a_x1 >> a_y1 >> a_x2 >> a_y2 >> b_x1 >> b_y1 >> b_x2 >> b_y2;

    int min_x = min(a_x1 , b_x1);
    int max_x = max(a_x2 , b_x2);

    int min_y = min(a_y1 , b_y1);
    int max_y = max(a_y2 , b_y2);

    int x_dist = max_x - min_x;
    int y_dist = max_y - min_y;

    int s = max(x_dist , y_dist);
    cout << s*s;

}
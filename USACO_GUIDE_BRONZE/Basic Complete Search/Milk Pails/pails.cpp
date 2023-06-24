#include <iostream>
using namespace std;

int main()
{
    freopen("pails.in" , "r" , stdin);
    freopen("pails.out" , "w" , stdout);

    int x, y, m, i, j, max; cin >> x >> y >> m;

    i = m/y; j = 0; max = 0;
    while(i >= 0)
    {
        j = (m - y*i)/(x);
        if(x*j + y*i > max){max = x*j + y*i;}
        i--;
    }

    cout << max;
}
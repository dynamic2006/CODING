#include <iostream>

using namespace std;

int main()
{
    
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    int x, y; cin >> x >> y;
    int temp = x; int unit = 1; int dist = 1;
    int total = 0;

    while (temp != y)
    {
        while (temp != x + dist && temp != y)
        {
            temp += unit;
            total++;
        }
        unit = -unit;
        dist = (-2)*(dist);
    }

    cout << total;
}
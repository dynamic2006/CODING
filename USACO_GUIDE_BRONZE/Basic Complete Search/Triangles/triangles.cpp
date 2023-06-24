#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    freopen("triangles.in" , "r" , stdin);
    freopen("triangles.out" , "w" , stdout);

    int n, x, y, h, l; cin >> n;
    int max_area = 0;

    vector<pair<int, int>> points(n+1);

    for(int i=0; i<n; i++)
    {
        cin >> x >> y;
        points[i].first = x;
        points[i].second = y;
    }

    for(int a=0; a<n; a++)
        for(int b=0; b<n; b++)
            for(int c=0; c<n; c++)
            {
                if( points[a].first == points[b].first && points[a].second == points[c].second )
                {
                    h = abs(points[a].second - points[b].second);
                    l = abs(points[a].first - points[c].first);
                    max_area = max(max_area, h*l);
                }
            }
    
    cout << max_area;
}
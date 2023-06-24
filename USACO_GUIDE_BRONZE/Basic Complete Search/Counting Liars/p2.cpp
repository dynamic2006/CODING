#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    // freopen("4.in" , "r" , stdin);
    // freopen("liars.out" , "w" , stdout);

    int n, num; cin >> n;
    char dir;
    vector<pair<int,char>> locations(n);
    for(int i=0; i<n; i++)
    {
        cin >> dir >> num;
        locations[i].first = num;
        locations[i].second = dir;
    }

    int minliars = n;
    sort(locations.begin() , locations.end());

    for(int i=0; i<n; i++)
    {
        int numliars = 0;
        for(int j=0; j<i; j++)
        {
            if(locations[j].second == 'L')
                numliars++;
        }
        for(int j=i+1; j<n; j++)
        {
            if(locations[j].second == 'G')
                numliars++;
        }

        minliars = min(minliars, numliars);
    }

    cout << minliars;

}
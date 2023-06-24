#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("herding.in" , "r" , stdin);
    freopen("herding.out" , "w" , stdout);

    vector<int> cows(3);
    for(int i=0; i<3; i++)
        cin >> cows[i];
    sort(cows.begin() , cows.end());

    int dist1 = cows[1] - cows[0];
    int dist2 = cows[2] - cows[1];

    if(dist1 == 2 || dist2 == 2)
        cout << 1 << endl;
    else if(dist1 == 1 && dist2 == 1)
        cout << 0 << endl;
    else cout << 2 << endl;

    int max_dist = max(dist1 , dist2);
    cout << max_dist - 1 << endl;
}
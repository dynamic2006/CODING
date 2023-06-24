#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> diamonds;

int main()
{
    freopen("diamond.in" , "r" , stdin);
    freopen("diamond.out" , "w" , stdout);

    int n, k, temp, total, max; cin >> n >> k;
    total = 0; max = 0;
    for(int i=0; i<n; i++)
    {
        cin >> temp;
        diamonds.push_back(temp);
    }

    sort(diamonds.begin() , diamonds.end());

    int cur = 0; int check = 0;
    
    while(cur < n)
    {
        while(check < n && diamonds.at(check) <= diamonds.at(cur) + k)
        {
            total++;
            check++;
        }
        if(total > max){max = total;}
        total = 0;
        cur++;
        check = cur;
    }

    cout << max;


}
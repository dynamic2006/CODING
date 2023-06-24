#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("rut.in" , "r" , stdin);
    // freopen("rut.out" , "w" , stdout);

    int n; cin >> n;

    vector<array<int, 3>> nc, ec;
    for(int i=0; i<n; i++)
    {
        char dir; int x, y;
        cin >> dir >> x >> y;
        if(dir == 'N')
            nc.push_back({x, y, i});
        else ec.push_back({x, y, i});
    }
    sort(nc.begin() , nc.end());
    sort(ec.begin() , ec.end() , [](auto &a, auto &b){return a[1] < b[1];});

    vector<int> maxdist(n);
    for(int i=0; i<n; i++)
        maxdist[i] = -1;
    
    for (auto n_cow: nc)
    {
        for(auto e_cow: ec)
        {
            if (n_cow[0] >= e_cow[0] && n_cow[1] <= e_cow[1])
            {
                int vertical = e_cow[1] - n_cow[1];
                int horizontal = n_cow[0] - e_cow[0];

                if(vertical < horizontal && maxdist[e_cow[2]] == -1)
                {   
                    maxdist[e_cow[2]] = horizontal;
                }
                else if(horizontal < vertical && maxdist[e_cow[2]] == -1)
                {
                    maxdist[n_cow[2]] = vertical;
                    break;

                }


            }
        }
    }

    for(int i=0; i<n; i++)
    {
        if(maxdist[i] == -1)
            cout << "Infinity" << endl;
        else
            cout << maxdist[i] << endl;
    }
    
    
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("balancing.in" , "r" , stdin);
    freopen("balancing.out" , "w" , stdout);

    int n, b; cin >> n >> b;
    vector<int> x_pos(n);
    vector<int> y_pos(n);
    set<int> vertical;
    set<int> horizontal;
    for(int i=0; i<n; i++)
    {
        cin >> x_pos[i] >> y_pos[i];
        vertical.insert(x_pos[i]+1);
        horizontal.insert(y_pos[i]+1);
    }

    int m = 100;
    int maximum = 0;

    for(int v : vertical)
    {
        for(int h : horizontal)
        {
            int q1=0, q2=0, q3=0, q4=0;
            for(int i=0; i<n; i++)
            {
                if(x_pos[i] > v && y_pos[i] > h)
                    q1++;
                if(x_pos[i] < v && y_pos[i] > h)
                    q2++;
                if(x_pos[i] < v && y_pos[i] < h)
                    q3++;
                if(x_pos[i] > v && y_pos[i] < h)
                    q4++;
            }
            maximum = max(q1, max(q2, max(q3, q4)));
            m = min(m, maximum);
        }
    }

    cout << m;
}
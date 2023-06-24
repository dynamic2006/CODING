#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("kayak.in" , "r" , stdin);
    // freopen("kayak.out" , "w" , stdout);

    int minimum = (int) 1e9;
    int k; cin >> k;
    int n = 2*k;
    vector<int> weights(n);
    vector<int> diffs(k);

    for(int i=0; i<n; i++)
    {
        cin >> weights[i];
    }
    
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            vector<int> new_weights;
            for(int p=0; p<n; p++)
            {
                if(p != i && p != j)
                    new_weights.push_back(weights[p]);
            }
            sort(new_weights.begin() , new_weights.end());

            int total = 0;
            for(int a=0; a<n-2; a+=2)
            {
                total += new_weights[a+1] - new_weights[a];
            }

            minimum = min(minimum, total);
        }
    }

    cout << minimum << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("jurymarks.in" , "r" , stdin);
    // freopen("jurymarks.out" , "w" , stdout);

    int n, k; cin >> n >> k;
    vector<int> pre_sums(n);
    cin >> pre_sums[0]; int temp;
    for(int i=1; i<n; i++)
    {
        cin >> temp;
        pre_sums[i] = pre_sums[i-1] + temp;
    }

    vector<int> remembers(k);
    for(int i=0; i<k; i++)
        cin >> remembers[i];

    set<int> possible_initial;
    for(int i=0; i<n; i++)
    {
        possible_initial.insert(remembers[0] - pre_sums[i]);
    }

    int total = 0;
    for(auto x : possible_initial)
    {
        set<int> scores;
        bool works = true;
        for(int j=0; j<n; j++)
        {
            scores.insert(x + pre_sums[j]);
        }
        for(int r=0; r<k; r++)
        {
            if(!scores.count(remembers[r]))
            {
                works = false; break;
            }
        }
        total += works;
    }
    cout << total;
}
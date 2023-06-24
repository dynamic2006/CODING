#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("stacking.in" , "r" , stdin);
    //freopen("stacking.out", "w" , stdout);
    int n, k; cin >> n >> k;
    vector<int> haybales(n+1, 0);
    vector<int> presub(n+1, 0);
    for(int i=0; i<k; i++)
    {
        int stack1, stack2; cin >> stack1 >> stack2;
        presub[stack1]++; presub[stack2+1]--;
        // presub contains the diff between the cur element and the previous one
    }
    for(int i=1; i<=n; i++)
    {
        haybales[i] = haybales[i-1] + presub[i];
    }
    sort(haybales.begin() , haybales.end());
    cout << haybales[n/2 + 1];

}

//reconstructing the array from its presub array
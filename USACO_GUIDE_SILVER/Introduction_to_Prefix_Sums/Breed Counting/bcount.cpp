#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("bcount.in" , "r" , stdin);
    freopen("bcount.out" , "w" , stdout);

    int n, q; cin >> n >> q;
    int breed;
    vector<int> arr(n+1); arr[0] = 0; // array for actual cowline
    vector<array<int, 3>> triple_prefix(n+1); // prefix sums for each cow breed
    triple_prefix[0] = {0,0,0}; // init

    for(int i=1; i<=n; i++)
    {
        cin >> breed; // 1,2,3 -- breed id
        arr[i] = breed;
        triple_prefix[i] = triple_prefix[i-1];
        triple_prefix[i][breed-1]++;
    }

    for(int i=0; i<q; i++)
    {
        int a, b; cin >> a >> b;
        int count[3];
        for(int k=0; k<3; k++)
        {
            count[k] = triple_prefix[b][k] - triple_prefix[a-1][k]; // using prefix sums
        }
        cout << count[0] << " " << count[1] << " " << count[2] << endl;
    }

}
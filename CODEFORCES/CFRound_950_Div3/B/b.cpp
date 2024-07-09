#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("b.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n, f, k; cin >> n >> f >> k;
        vector<int> cubes(n);
        for(int i=0; i<n; i++) cin >> cubes[i];

        int favNum = cubes[f-1];
        sort(cubes.begin() , cubes.end() , greater<int>());

        bool removed = false;
        for(int i=0; i<k; i++){
            if(cubes[i] == favNum){
                removed = true; break;
            }
        }
        if(removed && k<n && cubes[k] == favNum){
            cout << "MAYBE" << endl;
        }
        else if(removed){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
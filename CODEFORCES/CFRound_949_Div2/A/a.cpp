#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("a.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int l, r; cin >> l >> r;
        int k = 1, score = 0;
        while(k*2 <= r){
            k *= 2; score++;
        }
        cout << score << endl;
    }
}
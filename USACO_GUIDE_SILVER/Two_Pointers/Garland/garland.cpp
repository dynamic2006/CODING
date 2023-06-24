#include <bits/stdc++.h>
using namespace std;

int n; string colors;

void solve(){
    int maxChanges; cin >> maxChanges;
    char favColor; cin >> favColor;

    int left = 0 , right = 0, changes = 0, max_len = 0;
    while(left < n && right < n){
        while(right < n){
            if(colors[right++] != favColor) changes++;
            if(changes > maxChanges){right--; changes--; break;}
        }
        max_len = max(max_len , right - left); //left included , right excluded
        if(colors[left++] != favColor) changes--;
    }

    cout << max_len << endl; return;

}

int main(){
    //freopen("garland.in" , "r" , stdin);

    cin >> n >> colors;
    int q; cin >> q;
    while(q--){
        solve();
    }
}
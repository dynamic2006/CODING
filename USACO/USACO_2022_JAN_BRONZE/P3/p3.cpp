#include <bits/stdc++.h>
using namespace std;

void solve(){
    string word; cin >> word;
    int len = word.size();

    if(len < 3){
        cout << -1 << endl; return;
    }

    int ops = 0;

    if(len == 3){
        if(word[1] == 'O'){
            if(word[0] != 'M') ops++;
            if(word[2] != 'O') ops++;
            cout << ops << endl; return;
        }
        else{
            cout << -1 << endl; return;
        }
    }

    ops = 4;

    if(len > 3){
        //check every middle char for an O
        for(int i=1; i<len-1; i++){
            int temp = 0;
            if(word[i] == 'O'){
                if(word[i-1] != 'M') temp++;
                if(word[i+1] != 'O') temp++;
                ops = min(ops , temp);
            }
        }
        //cout << ops << endl;
        //if no O's found, ops should still be 4
        if(ops == 4){
            cout << -1 << endl; return;
        }
        //otherwise, add on len-3 to ops
        cout << ops + len - 3 << endl; return;
    }
}

int main(){
    //freopen("p3.in" , "r" , stdin);

    int q; cin >> q;
    while(q--){
        solve();
    }
}
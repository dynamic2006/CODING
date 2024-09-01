#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("b.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int size = sqrt(n);
        if(size*size != n){
            cout << "No" << endl;
            continue;
        }
        
        bool valid = true;
        for(int i=0; i<size; i++){
            if(s[i] != '1'){
                valid = false; break;
            }
        }
        if(!valid){
            cout << "No" << endl;
            continue;
        }

        for(int r=1; r<size-1; r++){
            if(s[r*size] != '1' || s[(r+1)*size - 1] != '1'){
                valid = false; break;
            }
            for(int c=1; c<size-1; c++){
                if(s[r*size + c] != '0'){
                    valid = false; break;
                }
            }
            if(!valid) break;
        }
        if(!valid){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }
    }
}
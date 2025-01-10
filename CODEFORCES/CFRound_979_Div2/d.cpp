#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;
        vector<int> perm(n);
        for(int i=0; i<n; i++) cin >> perm[i];
        string s; cin >> s;

        set<int> badLRS;
        vector<bool> isSubPerm(n);
        
        int maxNumSeen = 0;
        for(int i=0; i<n; i++){
            maxNumSeen = max(maxNumSeen, perm[i]);
            if(maxNumSeen == i+1) isSubPerm[i] = true;
            else isSubPerm[i] = false;
        }

        for(int i=0; i<n-1; i++){
            if(s[i] == 'L' && s[i+1] == 'R'){
                if(!isSubPerm[i]) badLRS.insert(i);
            }
        }

        for(int i=0; i<q; i++){
            int k; cin >> k; k--;
            if(s[k] == 'L'){
                if(k > 0 && s[k-1] == 'L' && !isSubPerm[k-1]) badLRS.insert(k-1);
                if(k < n-1 && s[k+1] == 'R' && !isSubPerm[k]) badLRS.erase(k);
                s[k] = 'R';
            }
            else{
                if(k > 0 && s[k-1] == 'L' && !isSubPerm[k-1]) badLRS.erase(k-1);
                if(k < n-1 && s[k+1] == 'R' && !isSubPerm[k]) badLRS.insert(k);
                s[k] = 'L';
            }

            if(badLRS.empty()) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}
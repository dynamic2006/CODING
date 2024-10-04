#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    int maxLen = 0;
    int l=0, r=0;
    int maxLeft = 0, maxRight = 0;
    map<int, int> occs;
    while(r<n){
        occs[a[r++]]++;
        if(occs.size() <= k){
            // cout << "SIZE " << occs.size() << endl;
            // cout << "LEFT " << l << "RIGHT " << r << endl;
            if(r-l > maxLen){
                maxLen = r-l;
                maxLeft = l+1;
                maxRight = r;
            }
        }
        while(occs.size() > k){
            if(--occs[a[l]] == 0) occs.erase(a[l]);
            l++;
        }
    }

    cout << maxLeft << " " << maxRight << endl;
}
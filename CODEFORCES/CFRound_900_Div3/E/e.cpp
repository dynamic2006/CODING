#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> a;
vector<vector<int>> prefixBits;
int l, k;

bool valid(int rightIdx)
{
    if(rightIdx < l-1) return false;
    int num = 0;
    for(int i=0; i<32; i++){
        // cout << "PREFIX RIGHT " << prefixBits[rightIdx][i] << " PREFIX LEFT " << prefixBits[l-1][i] << endl;
        if(prefixBits[rightIdx][i] - prefixBits[l-1][i] == rightIdx-l+1 && (a[l-1] & (1<<i))){
            num |= (1<<i);
            // cout << "NUM " << num << endl;
        }
    }
    if(num >= k) return true;
    return false;
}

int binarySearch(int lo, int hi)
{
    lo--;
    while(lo<hi){
        int mid = lo+(hi-lo+1)/2;
        if(valid(mid)) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        a = vector<int>(n);
        for(int i=0; i<n; i++) cin >> a[i];
        int q; cin >> q;

        prefixBits = vector<vector<int>>(n, vector<int>(31, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<32; j++){
                if(i>0) prefixBits[i][j] = prefixBits[i-1][j];
                if(a[i] & (1<<j)) prefixBits[i][j]++;
            }
        }
        
        for(int query=0; query<q; query++){
            cin >> l >> k;

            int ans = binarySearch(l-1, n-1);
            if(ans < l-1) cout << -1 << " ";
            else cout << ans+1 << " ";
        }
        cout << endl;
    }
}
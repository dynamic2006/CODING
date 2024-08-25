#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("d1.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;
        ll f_bestK = 0;
        for(ll i=0; i<n; i++){
            ll f_tempBestK = -1;
            ll len; cin >> len;
            vector<ll> nums(len);
            for(ll j=0; j<len; j++) cin >> nums[j];
            sort(nums.begin(), nums.end());
            
            bool usedK = false;
            for(ll j=0; j<len; j++){
                if(nums[j] == f_tempBestK+1){
                    f_tempBestK++;
                }
                else if(nums[j] > f_tempBestK+1 && !usedK){
                    usedK = true;
                    f_tempBestK++; j--;
                }
                else if(nums[j] > f_tempBestK+1){
                    break;
                }
            }
            if(!usedK) f_tempBestK++;
            f_tempBestK++;

            // cout << "FBESTK NOW " << f_tempBestK << " ";
            f_bestK = max(f_bestK, f_tempBestK);
        }

        // cout << "FBESTK " << f_bestK << endl;

        ll ans = 0;
        if(m < f_bestK) ans = (m+1)*f_bestK;
        else{
            ans += (f_bestK+1)*f_bestK;
            // cout << ans << " ";
            ans += ((m+f_bestK+1)*(m-f_bestK))/2;
            // cout << ans << endl;
        }
        cout << ans << endl;

    }
}
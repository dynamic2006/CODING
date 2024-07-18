#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("d.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n, k, ans; cin >> n >> k;
        string s; cin >> s;
        string result = "";

        int cur = n-1; 
        while(cur >= 0 && s[cur] == s[n-1]) cur--;

        int endLen = n-1-cur;
        if(endLen > k){
            cout << -1 << endl;
            continue;
        }
        else if(endLen == k){
            ans = n;
            int len = 1;
            char c = s[0];
            for(int i=1; i<n; i++){
                if(s[i] == c)len++;
                else if(len > k){
                    if(c == s[n-1] || len % k != 0) ans = -1;
                    else ans = i-len+k;
                    //cout << "BREAKS AT 1 ON " << i << endl;
                    break;
                }
                else if(len < k){
                    ans = -1;
                    //cout << "BREAKS AT 2 ON " << i << endl;
                    break;
                }
                else{
                    len = 1;
                    c = s[i];
                }
            }

            if(ans == -1 || ans == n){
                cout << ans << endl;
                continue;
            }

            for(int i=ans; i<n; i++) result += s[i];
            for(int i=ans-1; i>=0; i--) result += s[i];
        }
        else{
            ans = n;
            int len = 1;
            char c = s[0];
            for(int i=1; i<n; i++){
                if(s[i] == c)len++;
                else if(len > k){
                    if(c != s[n-1] || len != 2*k-endLen) ans = -1;
                    else ans = i-len+(k-endLen);
                    //cout << "BREAKS AT 1 ON " << i << endl;
                    break;
                }
                else if(len < k){
                    if(c != s[n-1] || len != k-endLen) ans = -1;
                    else ans = i;
                    //cout << "BREAKS AT 2 WITH LEN " << len << " AND ANS " << ans << endl;
                    break;
                }
                else{
                    len = 1;
                    c = s[i];
                }
            }

            if(ans == -1 || ans == n){
                cout << ans << endl;
                //cout << "BREAKS AT 3" << endl;
                continue;
            }

            for(int i=ans; i<n; i++) result += s[i];
            for(int i=ans-1; i>=0; i--) result += s[i];
        }

        if(result.size() == 0) continue;
        //cout << result << endl;
        
        bool valid = true;
        int len=1; char c = result[0];
        for(int i=1; i<n; i++){
            if(result[i] == c) len++;
            else if(len != k){
                cout << -1 << endl;
                //cout << "SAFDSA " << i << endl;
                valid = false;
                break;
            }
            else{
                len = 1;
                c = result[i];
            }
        }

        if(valid && len == k) cout << ans << endl;
        //else cout << -1 << endl;
    }
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("c.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;

        ll pairs = n/2;
        ll opens = 0, closes = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '(') opens++;
            else if(s[i] == ')') closes++;
        }
        
        ll ans = 0;
        priority_queue<ll> openIdxs;
        for(int i=0; i<n; i++){
            if(s[i] == '_'){
                if(!openIdxs.empty() && closes < pairs){
                    //close asap
                    ans += i - openIdxs.top();
                    openIdxs.pop();
                    closes++;
                }
                else{
                    //place open bracket
                    openIdxs.push(i);
                    opens++;
                }
            }
            else if(s[i] == '('){
                //push open bracket
                openIdxs.push(i);
                opens++;
            }
            else{
                //found already counted close
                ans += i - openIdxs.top();
                openIdxs.pop();
            }
        }
        cout << ans << endl;
    }
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXSTOPS = 1500;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);
    
    ll n, k; cin >> n >> k;
    vector<ll> negStops(MAXSTOPS+1, 0), posStops(MAXSTOPS+1, 0);
    for(ll i=0; i<n; i++){
        ll xj, tj; cin >> xj >> tj;
        if(xj < 0) negStops[-xj] = tj;
        else posStops[xj] = tj;
    }

    ll ans = 0;

    ll mailCount = 0;
    ll dist = -1;
    for(int i=1500; i>=0; i--){
        if(dist == -1){
            if(posStops[i] != 0){
                int addMail = min(k - mailCount, posStops[i]);
                mailCount += addMail;
                posStops[i] -= addMail;
                dist = i;
            }
        }
        else{
            int addMail = min(k - mailCount, posStops[i]);
            mailCount += addMail;
            posStops[i] -= addMail;
        }
        if(mailCount == k){
            ans += 2*dist;
            mailCount = 0;
            dist = -1;
            // cout << i << " " << posStops[i] << endl;
            i++;
            // cout << i << endl;
        }
    }
    if(mailCount > 0 && dist != -1) ans += 2*dist;

    // cout << "POS STOPS ANS " << ans << endl;

    mailCount = 0;
    dist = -1;
    for(int i=1500; i>=0; i--){
        if(dist == -1){
            if(negStops[i] != 0){
                int addMail = min(k - mailCount, negStops[i]);
                mailCount += addMail;
                negStops[i] -= addMail;
                dist = i;
            }
        }
        else{
            int addMail = min(k - mailCount, negStops[i]);
            mailCount += addMail;
            negStops[i] -= addMail;
        }
        if(mailCount == k){
            ans += 2*dist;
            mailCount = 0;
            dist = -1;
            i++;
        }
    }
    if(mailCount > 0 && dist != -1) ans += 2*dist;

    cout << ans << endl;
}
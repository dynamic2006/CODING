#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXNUM = 1e18;

ll calcOps(string &s, int ignoreIdx)
{
    map<char, int> oddPosOccs, evenPosOccs;
    int modifiedIdx = 1;
    for(int i=1; i<=s.size(); i++){
        if(i == ignoreIdx) continue;
        else if(modifiedIdx%2 == 1){
            oddPosOccs[s[i-1]]++;
        }
        else evenPosOccs[s[i-1]]++;

        modifiedIdx++;
    }
    int ops = 0;
    int maxOddPosOcc = 0;
    for(auto &p : oddPosOccs){
        maxOddPosOcc = max(maxOddPosOcc, p.second);
    }
    int maxEvenPosOcc = 0;
    for(auto &p : evenPosOccs){
        maxEvenPosOcc = max(maxEvenPosOcc, p.second);
    }

    ll len = s.size()/2;
    return (len - maxOddPosOcc) + (len - maxEvenPosOcc);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("e.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;

        if(n%2 == 0){
            cout << calcOps(s, -1) << endl;
            continue;
        }

        ll ans = MAXNUM;
        for(int i=1; i<=n; i++){
            ans = min(ans, calcOps(s, i) + 1);
        }
        cout << ans << endl;
    }
}
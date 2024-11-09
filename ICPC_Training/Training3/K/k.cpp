#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

unordered_map<ll, double> dp;
bitset<7> masks[8];

//state format: [active encoding][value cards][nonvalue cards]
ll encode(bool active[7], ll other[8])
{
    ll state = 0;
    for(ll i=0; i<7; i++) state = (state << 1) | active[i];
    for(ll i=0; i<7; i++) state = (state << 3) | other[i];
    state <<= 5;
    state |= other[7];
    return state;
}

void decode(ll state, bool active[7], ll other[8])
{
    other[7] = state & 31;
    state >>= 5;
    for(ll i=6; i>=0; i--){
        other[i] = state & 7;
        state >>= 3;
    }
    for(ll i=6; i>=0; i--){
        active[i] = state & 1;
        state >>= 1;
    }
}

double solve(ll state)
{
    //if state has already been calculated
    if(dp.find(state) != dp.end()) return dp[state];
    dp[state] = 0.0;

    //decode state to get card info
    bool active[7];
    ll other[8];
    decode(state, active, other);

    bool allUp = true;
    for(ll i=0; i<7; i++) allUp &= active[i];
    if(allUp) return 0.0;

    //try picking each card and do dp transition
    ll total = 0;
    for(ll i=0; i<8; i++){
        bool tempActive[7];
        ll tempOther[8];
        memcpy(tempActive, active, sizeof(tempActive));
        memcpy(tempOther, other, sizeof(tempOther));

        if(tempOther[i] > 0){
            total += tempOther[i];
            tempOther[i]--;
            for(ll b=0; b<7; b++){
                tempActive[b] |= masks[i][b];
            }
            ll nextState = encode(tempActive, tempOther);
            
            dp[state] += (tempOther[i]+1)*(solve(nextState));
        }
    }
    if(total > 0) dp[state] /= total;
    dp[state]++;
    // cout << dp[state] << endl;
    // for(int i=0; i<7; i++) cout << active[i];
    // cout << endl;
    // for(int i=0; i<8; i++) cout << other[i] << " ";
    // cout << endl;
    return dp[state];

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    string s; cin >> s;

    // cout << "CHeck" << endl;
    //need to account for leftover cards in deck
    //also affects prob weights
    ll startCounts[8] = {4, 4, 4, 4, 4, 4, 4, 24};
    bool active[7] = {0,0,0,0,0,0,0};
    for(ll i=0; i<7; i++){
        if(s[i] == 'A') startCounts[0]--;
        else if(s[i] - '0' >= 2 && s[i] - '0' <= 7) startCounts[s[i] - '1']--;
        else startCounts[7]--;
    }

    for(ll i=0; i<7; i++){
        set<ll> seen;
        ll x = i;
        do{
            // cout << x << endl;
            seen.insert(x);
            char c = s[x];
            // cout << "c " << c << endl;
            if(c == 'A') x = 0;
            else if(c - '0' >= 2 && c - '0' <= 7){
                // cout << "HERE" << endl;
                x = (c - '0')-1;
            }
            else break;
        }while(!seen.count(x));

        ll mask = 0;
        for(auto x : seen){
            mask += (1 << x);
        }
        // cout << mask << endl;
        bitset<7> binary(mask);
        masks[i] = binary;
    }
    masks[7] = bitset<7>(0);

    double ans = solve(encode(active, startCounts));
    cout << fixed << setprecision(10) << ans << endl;

}
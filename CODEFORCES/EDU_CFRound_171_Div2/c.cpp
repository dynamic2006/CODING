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
        int n; cin >> n;
        string s; cin >> s;

        int ptr = 0;
        ll tot = 0;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i] == '0'){
                tot += i+1;
                ptr = max(ptr-1, 0);
            }
            else if(ptr >= i) tot += i+1;
            else ptr++;
        }
        cout << tot << endl;
    }
}
//we want most expensive toys for free
//right to left, if its a 1, then get x_i for free, match with cheapest option
//if its a 0 then we need to buy this one
//essentially if we encounter a zero, this toy is bought later,
//so it must be paid for because it shouldn't be taken over more expensive toy
//if its a 1 and no more cheap options left (keep ptr to last cheap bought)
//then we must buy this toy, but thats okay because that means
//we got a more expensive toy for free in its place
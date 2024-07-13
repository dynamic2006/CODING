#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("c.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        ll n, left, right; cin >> n >> left >> right;
        vector<ll> cards(n);
        for(int i=0; i<n; i++) cin >> cards[i];

        ll roundsWon = 0;
        ll curTotal = 0;
        int l=0, r=0;
        while(r<n){
            while(r<n && curTotal<left){
                curTotal += cards[r++];
            }
            while(l<r && curTotal>right){
                curTotal -= cards[l++];
            }
            //if curTotal is in bounds, can start next block
            //else KEEP curTotal value for next block
            //especially needed for case where curTotal < l
            if(curTotal >= left && curTotal <= right){
                roundsWon++;
                curTotal = 0;
                l = r;
            }
        }
        cout << roundsWon << endl;
    }
}
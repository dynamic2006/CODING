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
        int n, k; cin >> n >> k;
        map<int, int> occs;
        for(int i=0; i<n; i++){
            int a; cin >> a;
            occs[a]++;
        }

        int maxCards = 0, tempCards = 0;
        int prevCardNum = -1, diffCards = 0;
        for(auto &ptr : occs){
            if(tempCards == 0){
                prevCardNum = ptr.first;
                tempCards += ptr.second;
                diffCards = 1;
            }
            else if(ptr.first != prevCardNum+1){
                maxCards = max(maxCards, tempCards);
                tempCards = ptr.second;
                prevCardNum = ptr.first;
                diffCards = 1;
            }
            else if(diffCards == k){
                maxCards = max(maxCards, tempCards);
                tempCards -= occs[ptr.first-diffCards];
                tempCards += occs[ptr.first];
                prevCardNum = ptr.first;
            }
            else{
                tempCards += ptr.second;
                prevCardNum = ptr.first;
                diffCards++;
            }
        }
        maxCards = max(maxCards, tempCards);
        cout << maxCards << endl;
    }
}
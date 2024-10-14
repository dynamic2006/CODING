#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int MAXNUM = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n; cin >> n;
    vector<pair<pair<int, int>, int>> occs(26, {{-1, -1},-1});
    for(int i=0; i<n; i++){
        int a; string s;
        cin >> a;
        cin >> s;
        for(int c = 0; c < s.size(); c++){
            if(occs[s[c] - 'a'].first.first == -1) occs[s[c] - 'a'].first.first = a;
            else if(occs[s[c] - 'a'].second == -1){
                occs[s[c] - 'a'].second = a - occs[s[c] - 'a'].first.first;
                occs[s[c] - 'a'].first.first = a;
                occs[s[c] - 'a'].first.second = c;
            }
        }
    }

    int longestPeriod = 0;
    for(int i=0; i<26; i++){
        longestPeriod = max(longestPeriod, occs[i].second);
    }

    char ans;
    pair<int , int> earliestApp = {MAXNUM , MAXNUM};
    for(int i=0; i<26; i++){
        if(occs[i].second == longestPeriod){
            if(occs[i].first.first < earliestApp.first){
                earliestApp = occs[i].first;
                ans = 'a' + i;
            }
            else if(occs[i].first.first == earliestApp.first && occs[i].first.second < earliestApp.second){
                earliestApp = occs[i].first;
                ans = 'a' + i;
            }
        }
    }
    cout << ans << endl;
}
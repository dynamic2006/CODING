#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n; cin >> n;

    vector<pair<int, int>> moves;
    moves.push_back({1,3});

    for(int i=2; i<=n; i++){
        int size = moves.size();
        moves.push_back({1,3});
        for(int j=0; j<size; j++){
            int from = moves[j].first;
            int to = moves[j].second;

            moves.push_back({3-(from%3), 3-(to%3)});

            if(from == 2) moves[j].first = 3;
            if(from == 3) moves[j].first = 2;
            if(to == 2) moves[j].second = 3;
            if(to == 3) moves[j].second = 2;
        }
    }
    cout << moves.size() << endl;
    for(auto &move : moves){
        cout << move.first << " " << move.second << endl;
    }
}
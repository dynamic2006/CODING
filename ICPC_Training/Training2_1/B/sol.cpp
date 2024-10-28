#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);
}

//ideas
//doors matter, not distance
//for each cell, track vis for vis from up, down, left, right
//never leave cell from place that it was already visited from
//then just bfs on cells and update to get min cost to get to cell
//do this for both prisoners
//somehow track duplicate doors
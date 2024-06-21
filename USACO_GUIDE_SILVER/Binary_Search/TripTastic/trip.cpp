#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXNUM = 1e6;

int t, n, m, k;
vector<vector<int>> rooms;
vector<vector<ll>> prefix;

bool valid(int maxDist)
{
    //try every possible spot with maxDist prefix box sum
    for(int r=1; r<=n; r++){
        for(int c=1; c<=m; c++){
            if(rooms[r-1][c-1] == 0) continue;
            int leftBound = max(0, c-maxDist-1);
            int rightBound = min(m, c+maxDist);
            int upBound = max(0, r-maxDist-1);
            int downBound = min(n, r+maxDist);
            ll spaces = prefix[downBound][rightBound] - prefix[upBound][rightBound] - prefix[downBound][leftBound] + prefix[upBound][leftBound];
            if(spaces > k) return true;
        }
    }
    return false;
}

int binarySearch(int lo, int hi)
{
    hi++;
    while(lo<hi){
        int mid = lo+(hi-lo)/2;
        if(valid(mid)) hi=mid;
        else lo=mid+1;
    }
    return lo;
}

void solve()
{
    cin >> n >> m >> k;
    //how to initialize vector of vectors with all zeros
    rooms = vector<vector<int>>(n, vector<int>(m,0));
    prefix = vector<vector<ll>>(n+1, vector<ll>(m+1,0));

    for(int r=0; r<n; r++){
        for(int c=0; c<m; c++){
            cin >> rooms[r][c];
        }
    }

    for(int r=1; r<=n; r++){
        for(int c=1; c<=m; c++){
            prefix[r][c] = prefix[r-1][c] + prefix[r][c-1] - prefix[r-1][c-1] + rooms[r-1][c-1];
        }
    }

    if(prefix[n][m] <= k){
        cout << -1 << endl;
        return;
    }

    //distance can't be greater than max of dimensions
    int ans = binarySearch(0, max(n,m));
    cout << ans << endl;
}

int main()
{
    //freopen("trip.in" , "r" , stdin);

    cin >> t;

    for(int i=0; i<t; i++){
        solve();
    }
}
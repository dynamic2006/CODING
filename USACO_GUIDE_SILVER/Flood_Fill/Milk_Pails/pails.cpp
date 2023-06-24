#include <bits/stdc++.h>
using namespace std;

const int MAXNUM = 100;
int x, y, k, m, ans = 1e5;

//keep track of amts in buckets and operations done
bool states[MAXNUM+1][MAXNUM+1][MAXNUM+1];

void solve(int a, int b, int ops){

    if(a < 0 || a > x || b < 0 || b > y || ops > k) return;
    if(states[a][b][ops]) return;

    states[a][b][ops] = true;
    ans = min(ans , abs(m-a-b));

    solve(a, 0, ops+1);
    solve(0, b, ops+1);
    solve(x, b, ops+1);
    solve(a, y, ops+1);

    int pourBA = min(x-a, b), pourAB = min(y-b, a);

    solve(a+pourBA, b-pourBA, ops+1);
    solve(a-pourAB, b+pourAB, ops+1);

}

int main(){

    freopen("pails.in" , "r" , stdin);
    freopen("pails.out" , "w" , stdout);

    cin >> x >> y >> k >> m;

    solve(0,0,0);
    cout << ans << endl;
    return 0;

}
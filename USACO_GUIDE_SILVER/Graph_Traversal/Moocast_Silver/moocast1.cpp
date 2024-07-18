#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Cow
{
    int x, y;
    int power;
};

int n, curCows;
vector<Cow> cows;
vector<bool> visited;

void dfs(int cowIdx)
{
    curCows++;
    visited[cowIdx] = true;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            ll pythag = pow((ll)cows[i].x - (ll)cows[cowIdx].x, 2) + pow((ll)cows[i].y - (ll)cows[cowIdx].y, 2);
            //cout << "PYTHAG " << pythag << endl;
            if(pythag <= pow((ll)cows[cowIdx].power, 2)){
                //cout << "CONT DFS" << endl;
                dfs(i);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    freopen("moocast.in" , "r" , stdin);
    freopen("moocast.out" , "w" , stdout);

    cin >> n;
    cows = vector<Cow>(n);
    for(int i=0; i<n; i++) cin >> cows[i].x >> cows[i].y >> cows[i].power;

    int maxCows = 0;
    for(int i=0; i<n; i++){
        //try starting dfs from cow i
        curCows = 0;
        visited.assign(n, false);
        dfs(i);
        //cout << curCows << endl;
        maxCows = max(maxCows, curCows);
    }

    cout << maxCows << endl;

}
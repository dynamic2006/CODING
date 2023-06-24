#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int n , m;
string farms;
vector<int> adj[MAXN+1];
pair<int , char> components[MAXN+1];

void makeComponents(int groupNum, int start , char color){
    components[start] = {groupNum , color};
    for(auto next : adj[start]){
        if(farms[next-1] == color && components[next].second != 'H' && components[next].second != 'G') makeComponents(groupNum, next, color);
    }
}

int main(){

    freopen("milkvisits.in" , "r" , stdin);
    freopen("milkvisits.out" , "w" , stdout);

    cin >> n >> m;
    cin >> farms;
    for(int i=1; i<n; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int curGroup = 1;
    for(int i=1; i<=n; i++){
        if(components[i].second != 'H' && components[i].second != 'G'){
            makeComponents(curGroup, i , farms[i-1]); curGroup++;
        }
    }

    for(int i=0; i<m; i++){
        int a, b; char type;
        cin >> a >> b >> type;
        if(components[a].second == type || components[b].second == type || components[a].first != components[b].first) cout << 1;
        else cout << 0;
    }
    cout << endl;
    return 0;


}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 100;

int pathDiff;
map<string, int> id;
vector<string> cows(2*MAXN+1, "");
vector<int> parents(2*MAXN+1, -1);
vector<vector<int>> adj;

bool dfs(int cur, int a, int b, bool& foundA, bool& foundB)
{
    if(cur == a) foundA = true;
    if(cur == b) foundB = true;
    if(foundA && foundB) return true;
    for(auto& next : adj[cur]){
        // cout << "VISITING " << cows[next] << endl;
        dfs(next, a, b, foundA, foundB);
    }
    // cout << "OUT OF DFS AT " << cows[cur] << endl;
    if(foundA && foundB) return true;
    return false;

}

void pathDFS(int cur, int target, int level)
{
    if(cur == target) pathDiff = level;
    for (auto& next : adj[cur]) {
        pathDFS(next, target, level+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);
    // freopen("input.in" , "r" , stdin);

    int n; cin >> n;
    adj = vector<vector<int>>(2*MAXN+1, vector<int>());

    int nextId = 3;
    string a, b; cin >> a >> b;
    id[a] = 1; id[b] = 2;
    cows[1] = a; cows[2] = b;

    for(int i=0; i<n; i++){
        cin >> a >> b;
        // if(i == 93) cout << a << " " << b << endl;
        if(!id.count(a)){
            id[a] = nextId;
            cows[nextId] = a;
            nextId++;
        }
        // cout << "OK" << endl;
        // cout << nextId << endl;
        if(!id.count(b)){
            id[b] = nextId;
            cows[nextId] = b;
            // cout << "GOOD HERE" << endl;
            nextId++;
        }

        // cout << "CHECK AT " << i << endl;

        adj[id[a]].push_back(id[b]);
        parents[id[b]] = id[a];

        // cout << "GOOD" << endl;
    }

    // cout << "CJECK" << endl;

    //check if bessie and elsie are even in the same tree (cousins at least)
    //if not in same tree, then output NOT RELATED
    //if in same tree
    //if they are direct descendents of each other, either bessie is in elsies tree
    //or elsie is in bessies tree -- try both of these
    //otherwise one may be an aunt of another, so their mothers are direct descendants
    //again, see is bessie's mom in in elsies' moms' tree or vice versa
    
    bool found = false;
    for(int i=1; i<nextId; i++){
        //dfs and see if cows are in same tree (confirms cousinhood at least)
        bool foundA = false;
        bool foundB = false;
        // cout << "GOING INTO DFS AT " << cows[i] << endl;
        if(dfs(i, 1, 2, foundA, foundB)) found = true;
        // cout << endl;
    }

    // cout << "CHECK" << endl;

    if(!found){
        cout << "NOT RELATED" << endl;
        return 0;
    }
    pathDiff = 0;

    bool foundA, foundB;

    foundA = false; foundB = false;
    if(dfs(1, 1, 2, foundA, foundB)){
        //1 is an ancestor of 2
        pathDFS(1, 2, 0);
        // cout << dist << endl;
        switch (pathDiff){
            case 1:
                cout << cows[1] << " is the mother of " << cows[2] << endl;
                break;
            case 2:
                cout << cows[1] << " is the grand-mother of " << cows[2] << endl;
                break;
            default:
                cout << cows[1] << " is the ";
                for(int i=2; i<pathDiff; i++){
                    cout << "great-";
                }
                cout << "grand-mother of " << cows[2] << endl;
                break;
        }
        return 0;
    }

    foundA = false; foundB = false;
    if(dfs(2, 1, 2, foundA, foundB)){
        //2 is an ancestor of 1
        pathDFS(2, 1, 0);
        // cout << dist << endl;
        switch (pathDiff){
            case 1:
                cout << cows[2] << " is the mother of " << cows[1] << endl;
                break;
            case 2:
                cout << cows[2] << " is the grand-mother of " << cows[1] << endl;
                break;
            default:
                cout << cows[2] << " is the ";
                for(int i=2; i<pathDiff; i++){
                    cout << "great-";
                }
                cout << "grand-mother of " << cows[1] << endl;
                break;
        }
        return 0;
    }

    int x = parents[1], y = parents[2];

    foundA = false; foundB = false;
    if(dfs(x, x, y, foundA, foundB)){
        //1 is an something-aunt of 2 (or sisters)
        pathDFS(x, y, 0);
        switch (pathDiff){
            case 0:
                cout << "SIBLINGS" << endl;
                break;
            case 1:
                cout << cows[1] << " is the aunt of " << cows[2] << endl;
                break;
            case 2:
                cout << cows[1] << " is the great-aunt of " << cows[2] << endl;
                break;
            default:
                cout << cows[1] << " is the ";
                for(int i=2; i<pathDiff; i++){
                    cout << "great-";
                }
                cout << "great-aunt of " << cows[2] << endl;
                break;
        }
        return 0;
    }

    foundA = false; foundB = false;
    if(dfs(y, x, y, foundA, foundB)){
        //2 is an something-aunt of 1 (or sisters)
        pathDFS(y, x, 0);
        // cout << dist << endl;
        switch (pathDiff){
            case 0:
                cout << "SIBLINGS" << endl;
                break;
            case 1:
                cout << cows[2] << " is the aunt of " << cows[1] << endl;
                break;
            case 2:
                cout << cows[2] << " is the great-aunt of " << cows[1] << endl;
                break;
            default:
                cout << cows[2] << " is the ";
                for(int i=2; i<pathDiff; i++){
                    cout << "great-";
                }
                cout << "great-aunt of " << cows[1] << endl;
                break;
        }
        return 0;
    }

    cout << "COUSINS" << endl;
    return 0;

}
#include <bits/stdc++.h>
using namespace std;

const long long MAXNODES = 1e5;
const long long MAXSIZE = 1e9;
const long long MAXLEN = 1e14;

struct Path {
    long long toNode;
    long long length;
    long long size;

    Path(long long n, long long l, long long s){
        toNode = n;
        length = l;
        size = s;
    }

    Path(){
        toNode = -1;
        length = -1;
        size = -1;
    }
};

long long n, m;
map<long long, vector<Path>> adj;

//implement dijkstra's with restriction to paths with size >= cowSize
long long valid(long long cowSize){

    long long minDistances[MAXNODES + 1];
    fill(minDistances, minDistances + MAXNODES + 1, MAXLEN+1);
    bool processed[MAXNODES + 1];
    fill(processed, processed + MAXNODES + 1, 0);

    priority_queue<pair<long long, long long>> nextNodes;
    nextNodes.push({0,1});
    minDistances[1] = 0;

    while(!nextNodes.empty()){
        long long node = nextNodes.top().second;
        nextNodes.pop();

        if(processed[node]) continue;
        processed[node] = true;

        for(auto path : adj[node]){
            if(path.size < cowSize) continue;

            if(minDistances[node] + path.length < minDistances[path.toNode]){
                minDistances[path.toNode] = minDistances[node] + path.length;
                nextNodes.push({-minDistances[path.toNode] , path.toNode});
            }
        }
    }

    return minDistances[n];

}

//binarySearch to find largest cowSize possible
pair<long long, long long> binarySearch(long long lo, long long hi){
    lo--;
    long long shortestLen = -1;
    while(lo < hi){
        long long mid = lo + (hi-lo+1)/2;
        shortestLen = valid(mid);
        if(shortestLen != MAXLEN + 1) lo = mid;
        else hi = mid-1;
    }
    return {lo, shortestLen};
}

int main() {

    //freopen("p3.in" , "r" , stdin);

    //strategy
    //binary search to find largest cow that works
    //use dijkstra's to test if path can be found + shortest path

    cin >> n >> m;
    for(long long i=0; i<m; i++){
        long long a, b, l, s; cin >> a >> b >> l >> s;
        adj[a].push_back(Path(b, l, s));
        adj[b].push_back(Path(a, l, s));
    }

    pair<long long, long long> ans = binarySearch(0, MAXSIZE+1);
    cout << ans.first << " " << ans.second << endl;

}
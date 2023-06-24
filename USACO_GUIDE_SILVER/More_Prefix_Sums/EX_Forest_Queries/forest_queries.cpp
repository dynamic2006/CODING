#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("forest_queries.in" , "r" , stdin);
    int n, q; cin >> n >> q;
    vector<string> forest(n);
    for(int i=0; i<n; i++){
        cin >> forest[i];
    }

    int prefix_sum_trees[1001][1001];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            prefix_sum_trees[i][j] = prefix_sum_trees[i-1][j] + prefix_sum_trees[i][j-1] - prefix_sum_trees[i-1][j-1];
            if(forest[i-1][j-1] == '*') prefix_sum_trees[i][j]++;
        }
    }

    int y1, x1, y2, x2;
    for(int query = 0; query < q; query++){
        cin >> y1 >> x1 >> y2 >> x2;
        cout << prefix_sum_trees[y2][x2] - prefix_sum_trees[y1-1][x2] 
        - prefix_sum_trees[y2][x1-1] + prefix_sum_trees[y1-1][x1-1] << endl;
    }

}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("b.in" , "r" , stdin);

    int t; cin >> t;
    for(int i=0; i<t; i++){
        int n, m; cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m,0));

        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                cin >> matrix[r][c];
            }
        }

        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                int maxNeighbor = -1;
                if(r>0){
                    if(matrix[r-1][c] < matrix[r][c]) maxNeighbor = max(maxNeighbor, matrix[r-1][c]);
                    else continue;
                }
                if(r<n-1){
                    if(matrix[r+1][c] < matrix[r][c]) maxNeighbor = max(maxNeighbor, matrix[r+1][c]);
                    else continue;
                }
                if(c>0){
                    if(matrix[r][c-1] < matrix[r][c]) maxNeighbor = max(maxNeighbor, matrix[r][c-1]);
                    else continue;
                }
                if(c<m-1){
                    if(matrix[r][c+1] < matrix[r][c]) maxNeighbor = max(maxNeighbor, matrix[r][c+1]);
                    else continue;
                }

                if(maxNeighbor != -1) matrix[r][c] = maxNeighbor;
            }
        }

        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                cout << matrix[r][c] << " ";
            }
            cout << endl;
        }
    }
}
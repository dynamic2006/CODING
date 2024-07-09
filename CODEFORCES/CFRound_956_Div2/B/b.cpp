#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("b.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<string> a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];

        //debug
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout << a[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout << b[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        bool possible = true;
        //check rows
        for(int i=0; i<n; i++){
            int sumA = 0, sumB = 0;
            for(int j=0; j<m; j++){
                sumA += (a[i][j] - '0');
                sumB += (b[i][j] - '0');
            }
            if(sumA % 3 != sumB % 3){
                cout << "NO" << endl;
                possible = false;
                break;
            }
            sumA = 0; sumB = 0;
        }

        if(!possible) continue;

        //check cols
        for(int j=0; j<m; j++){
            int sumA = 0, sumB = 0;
            for(int i=0; i<n; i++){
                sumA += (a[i][j] - '0');
                sumB += (b[i][j] - '0');
            }
            if(sumA % 3 != sumB % 3){
                cout << "NO" << endl;
                possible = false;
                break;
            }
            sumA = 0; sumB = 0;
        }

        if(possible) cout << "YES" << endl;

    }


}
//IDEAS
//operation conserves sum of rows and cols mod 3
//so if rows and cols of both grids have same sums mod 3
//then fix any nums in (n-1)x(n-1) subgrid to match target grid
//do that with 2x2 subrectangles, now every val in subgrid matches
//then if any vals in last row/col don't match, contradiction
//the sum of the rows and cols assumed to be same mod 3
//so necessary and sufficient that rows and cols same sum mod 3
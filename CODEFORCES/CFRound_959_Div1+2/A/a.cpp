#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("a.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<vector<int>> nums(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> nums[i][j];
            }
        }
        //cout << "CHECK" << endl;

        if(n*m == 1){
            cout << -1 << endl;
            continue;
        }

        int temp = nums[0][0];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                //cout << "CHECK" << endl;
                if(i==n-1 && j==m-1) nums[i][j] = temp;
                else if(j == m-1) nums[i][j] = nums[i+1][0];
                else nums[i][j] = nums[i][j+1];
                //cout << "CHECK" << endl;
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << nums[i][j] << " ";
            }
            cout << endl;
        }
    }
}
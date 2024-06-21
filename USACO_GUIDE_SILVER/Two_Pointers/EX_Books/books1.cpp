#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("books.in" , "r" , stdin);

    int n, t; cin >> n >> t;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    int l=-1, r=-1;
    int time = 0;
    int maxBooks = 0;
    while(r<n-1){
        while(r+1 < n && time + nums[r+1] <= t){
            time += nums[++r];
        }
        //cout << "LEFT " << l << " RIGHT " << r << " TIME " << time << endl;
        maxBooks = max(maxBooks, r-l);
        //cout << "BOOKS " << r-l << " MAXBOOKS " << maxBooks << endl;

        time -= nums[++l];
    }

    cout << maxBooks << endl;
}
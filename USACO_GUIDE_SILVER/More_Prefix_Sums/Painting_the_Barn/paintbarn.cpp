#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("paintbarn.in", "r" , stdin);
    freopen("paintbarn.out" , "w" , stdout);
    int n, k; cin >> n >> k;
    int total = 0;
    int arr[1003][1003] = {0};
    int prefix[1003][1003] = {0};
    for(int i=0; i<n; i++)
    {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1++; y1++; x2++; y2++;
        arr[x1][y1]++;
        arr[x2][y1]--;
        arr[x1][y2]--;
        arr[x2][y2]++;
    
    }
    for(int i=1; i<=1000; i++)
    {
        for(int j=1; j<=1000; j++)
        {
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + arr[i][j];
            if(prefix[i][j] == k)
                total++;
        }
    }
    cout << total;
    
}

//in this case the prefix sum is what we wanted
//the arr contains the changes (if any) at each cell
//then the prefix adds up all previous changes and if the value is k, total++
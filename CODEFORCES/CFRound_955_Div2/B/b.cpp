#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("b.in" , "r" , stdin);

    int t; cin >> t;
    for(int i=0; i<t; i++){
        int x, y, k; cin >> x >> y >> k;
        while(k>=0){
            int d = x/y;
            int r = x%y;
            if(y-r > k){
                cout << x + k << endl;
                break;
            }

            k -= (y-r);
            x = d+1;
        }
    }

    
}
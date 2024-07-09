#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("c.in" , "r" , stdin);

    int t; cin >> t;
    for(int tc=0; tc<t; tc++){
        int n; cin >> n;
        vector<int> a(n), b(n);
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];

        int aRating = 0, bRating = 0;
        int netPlus = 0, netMinus = 0;
        for(int i=0; i<n; i++){
            if(a[i] > b[i]) aRating += a[i];
            else if (a[i] < b[i]) bRating += b[i];
            //otherwise both are equal
            else{
                if(a[i] == -1) netMinus++;
                else if(a[i] == 1) netPlus++;
            }
        }

        for(int i=0; i<netMinus; i++){
            if(aRating >= bRating) aRating--;
            else bRating--;
        }
        for(int i=0; i<netPlus; i++){
            if(aRating <= bRating) aRating++;
            else bRating++;
        }

        cout << min(aRating, bRating) << endl;
    }
}
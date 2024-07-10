#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("b.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;

        int maxCommon = 0;
        for(int i=0; i<b.size(); i++){
            int ai = 0, bi = i;
            while(ai<a.size() && bi<b.size()){
                if(a[ai] == b[bi]) bi++;
                ai++;
            }
            maxCommon = max(maxCommon, bi - i);
        }
        cout << a.size() + b.size() - maxCommon << endl;
    }
}
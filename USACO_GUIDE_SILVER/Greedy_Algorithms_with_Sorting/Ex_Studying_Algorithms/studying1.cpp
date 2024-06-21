#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("studying.in" , "r" , stdin);
    int n, x; cin >> n >> x;
    vector<int> algs(n);
    for(int i=0; i<n; i++){
        cin >> algs[i];
    }
    sort(algs.begin() , algs.end());

    int maxAlgs = 0;
    int time = 0;
    for(auto alg : algs) {
        if(time + alg <= x){
            time += alg;
            maxAlgs++;
        }
        else break;
    }
    cout << maxAlgs << endl;
    return 0;
}
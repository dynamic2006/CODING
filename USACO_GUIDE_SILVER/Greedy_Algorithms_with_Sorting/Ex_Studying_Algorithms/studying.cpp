#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("studying.in" , "r" , stdin);
    int n; int x; cin >> n >> x;
    vector<int> algs(n);
    for(int i=0; i<n; i++){
        cin >> algs[i];
    }
    sort(algs.begin() , algs.end());

    int total = 0;
    for(int i=0; i<n; i++){
        if(algs[i] <= x){
            x -= algs[i];
            total++;
        }
        else{
            break;
        }
    }
    cout << total << endl;
}
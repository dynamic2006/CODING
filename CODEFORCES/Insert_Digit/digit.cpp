#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("digit.in" , "r" , stdin);
    int t; cin >> t;
    for(int i=0; i<t; i++){
        int n, d; cin >> n >> d;
        string num; cin >> num;

        int j=0;
        bool used = false;

        while(j<n){
            if(!used && num[j] - '0' < d){
                cout << d; used = true;
            }
            else{
                cout << num[j]; j++;
            }
        }
        if(!used) cout << d;

        cout << endl;
    }
}
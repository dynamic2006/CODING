#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("p1.in" , "r" , stdin);

    int n; cin >> n;
    vector<int> tuitions(n);
    for(int i=0; i<n; i++){
        cin >> tuitions[i];
    }
    sort(tuitions.begin() , tuitions.end());

    long long max_total[2]; max_total[0] = 0; 
    for(long long i=0; i<n; i++){
        if((n-i)*tuitions[i] > max_total[0]){
            max_total[0] = (n-i)*tuitions[i];
            max_total[1] = tuitions[i];
        }

    }

    cout << max_total[0] << " " << max_total[1];
}
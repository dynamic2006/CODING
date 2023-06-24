#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string solve(){
    int n; cin >> n;
    vector<ll> input(2*n);
    vector<ll> distance_sums;
    vector<ll> diff_array(n); diff_array[0] = 0;
    for(int i=0; i<2*n; i++){
        cin >> input[i];
    }
    sort(input.begin() , input.end());

    ll prev_dist = -1, streak = 0;
    for(int i=0; i<2*n; i++){
        if(input[i] != prev_dist){
            distance_sums.push_back(input[i]); 
            prev_dist = input[i]; streak = 1;
        }
        else{
            streak++; if(streak > 2) return "NO";
        }
    }
    
    
    //first check -- are there n distinct numbers?
    if(distance_sums.size() != n) return "NO";

    for(int i=n-1; i>0; i--){
        ll dist = distance_sums[i] - distance_sums[i-1];
        if(dist % (2*i) != 0 || dist == 0) return "NO";

        ll i_th_diff = dist / (2*i);
        diff_array[n-i] = i_th_diff;
    }
    for(int i=1; i<n; i++){
        distance_sums[0] -= 2*i*diff_array[i];
    }
    if(distance_sums[0] <= 0 || distance_sums[0] % (2*n) != 0) return "NO";
    return "YES";
}

int main(){
    //freopen("nezzar.in" , "r" , stdin);

    int t; cin >> t;
    for(int i=0; i<t; i++){
        cout << solve() << endl;
    }
}
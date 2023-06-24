#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    string cows; cin >> cows;

    string pastures = "";
    for(int i=0; i<k; i++){
        pastures += '.';
    }

    int total_patches = 0;
    int last_g_index = -k-1, last_h_index = -k-1;
    for(int i=0; i<n-k; i++){
        if(cows[i] == 'G' && i - last_g_index > k){
            pastures += 'G'; last_g_index = i+k;
            total_patches++;
        }
        else if(cows[i] == 'H' && i - last_h_index > k){
            pastures += 'H'; last_h_index = i+k;
            total_patches++;
        }
        else{
            pastures += '.';
        }
    }

    for(int i=n-k; i<n; i++){
        if(cows[i] == 'G' && i - last_g_index > k){
            if(pastures[i] == '.'){
                pastures[i] = cows[i];
            }
            else{
                pastures[i-1] = cows[i];
            }
            last_g_index = i; total_patches++;
        }
        else if(cows[i] == 'H' && i - last_h_index > k){
            if(pastures[i] == '.'){
                pastures[i] = cows[i];
            }
            else{
                pastures[i-1] = cows[i];
            }
            last_h_index = i; total_patches++;
        }
    }

    cout << total_patches << endl << pastures << endl;


}

int main(){
    //freopen("p2.in" , "r" , stdin);
    
    int t; cin >> t;
    for(int i=0; i<t; i++){
        solve();
    }
}
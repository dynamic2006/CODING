#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("b.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        vector<int> bits(32, 0);

        int lastZero = -1;
        int counter = 0;
        for(int i=0; i<=30; i++){
            if(x & (1<<i)){
                counter++;
                // if(nonzero){
                //     bits[i+2]++;
                //     bits[i]--;
                //     nonzero = false;
                // }
                // else{
                //     bits[i]++;
                //     nonzero = true;
                // }
            }
            else{
                if(counter > 0){
                    bits[lastZero + counter + 1]++;
                    bits[lastZero+1]--;
                    counter = 0;
                }
                lastZero = i;
            }
        }
        for(int i=1; i<32; i++){
            if(bits[i] == -1 && bits[i-1] == 1){
                bits[i-1] = -1;
                bits[i] = 0;
            }
            else if(bits[i] == 1 && bits[i-1] == -1){
                bits[i-1] = 1;
                bits[i] = 0;
            }
        }

        cout << 32 << endl;
        for(auto bit : bits) cout << bit << " ";
        cout << endl;
    }
}
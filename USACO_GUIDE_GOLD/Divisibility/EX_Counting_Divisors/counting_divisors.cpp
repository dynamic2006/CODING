#include <bits/stdc++.h>
using namespace std;

const int SIZE = 10e6;
int sieve[SIZE + 1];

//if x is prime, sieve[x] set to x
//if x is not prime, sieve[x] is the largest prime that divides x
void fillSieve(){
    for(int i=2; i<=SIZE; i++){
        if(sieve[i]) continue;
        for(int j=i; j<=SIZE; j+=i) sieve[j] = i;
    }
}

int main(){

    fillSieve();

    //freopen("counting_divisors.in" , "r" , stdin);
    //freopen("counting_divisors.out" , "w" , stdout);

    int n; cin >> n;
    for(int i=0; i<n; i++){
        int ans = 1;
        int x; cin >> x;
        while(sieve[x] != 0){
            int temp = x;
            int exp = 0;
            while(temp % sieve[x] == 0){
                exp++;
                temp /= sieve[x];
            }
            x = temp;
            ans *= (exp+1);
        }
        
        cout << ans << endl;
    }
    return 0;
    
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isprime(ll num)
{
    for(int i=2; i*i<=num; i++){
        if(num % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n, b; cin >> n >> b;
    if(b < n){
        cout << "impossible" << endl;
        return 0;
    }

    vector<int> nums(n);
    ll sum = 0;
    for(int i=0; i<n; i++){
        nums[i] = i+1;
        sum += nums[i];
    }

    bool valid = false;
    if(isprime(sum)) valid = true;
    for(int i=n-1; i>=0; i--){
        for(int j=1; j<=b-n; j++){
            nums[i]++; sum++;
            if(isprime(sum)){
                valid = true;
                break;
            }
        }
        if(valid) break;
    }

    if(valid){
        for(int cycle = 0; cycle<n; cycle++){
            for(int i=cycle; i<n; i++) cout << nums[i] << " ";
            for(int i=0; i<cycle; i++) cout << nums[i] << " ";
            cout << endl;
        }
    }
    else cout << "impossible" << endl;
}
#include <bits/stdc++.h>
using namespace std;

//returns true iff og vector a gives valid b vector
bool valid(vector<int> &a)
{
    int prevGCD = -1, curGCD = -1;
    int size = a.size();
    for(int i=0; i<size-1; i++){
        curGCD = __gcd(a[i], a[i+1]);
        if(curGCD < prevGCD) return false;
        prevGCD = curGCD;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("d.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        int idx = n;
        vector<int> b(n-1);
        for(int i=0; i<n-1; i++){
            b[i] = __gcd(a[i] , a[i+1]);
            if(i>0 && b[i] < b[i-1]) idx = i;
        }

        if(idx == n){
            cout << "YES" << endl;
            continue;
        }

        vector<int> a1 = a, a2 = a, a3 = a;
        if(idx-1 >= 0) a1.erase(a1.begin() + idx - 1);
        a2.erase(a2.begin() + idx);
        a3.erase(a3.begin() + idx + 1);

        if(valid(a1) || valid(a2) || valid(a3)){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}
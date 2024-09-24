#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);

    while(true){
        string str;
        if(getline(cin, str)){
            int sum = 0;
            for(auto &c : str) sum += c;
            cout << sum << endl;
        }
        else break;
    }
}



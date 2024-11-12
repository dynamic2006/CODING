#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
 
template<class T, class U> 
ostream& operator << (ostream& out, const pair<T, U> pi) {
    out << "(" << pi.first << "," << pi.second << ") ";
    return out;
}
template<class T> 
ostream& operator << (ostream& out, const vector<T>& v) {
    for (auto x : v) cout << x << " ";
    return out;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const auto start_time = chrono::steady_clock::now();
void time_elapsed() {
    auto diff = chrono::steady_clock::now() - start_time;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
}

void solve() {
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
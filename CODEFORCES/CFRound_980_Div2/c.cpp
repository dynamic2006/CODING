#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Pair
{
    int x, y;
    bool swapped = false;
};

bool cmp(const Pair &p1, const Pair &p2){
    if(p1.x < p2.x) return true;
    if(p2.x < p1.x) return false;
    if(p1.y < p2.y) return true;
    if(p2.y < p1.y) return false;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<Pair> a(n);
        for(int i=0; i<n; i++){
            int x, y; cin >> x >> y;
            // cout << x << " " << y << " ";
            a[i].x = min(x,y);
            a[i].y = max(x,y);
            // cout << a[i].first << " " << a[i].second << endl;
            if(a[i].x != x){
                // cout << "setting " << i << " to swapped since min is " << a[i].first << " not " << x << endl;
                a[i].swapped = true;
            }
        }

        sort(a.begin(), a.end(), cmp);

        for(int i=0; i<n; i++){
            if(a[i].swapped){
                cout << a[i].y << " " << a[i].x << " ";
            }
            else cout << a[i].x << " " << a[i].y << " ";
        }
        cout << endl;
    }
}
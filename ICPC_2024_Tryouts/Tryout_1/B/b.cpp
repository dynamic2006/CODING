#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n; cin >> n;
    double min_intercept = 1000.00;
    for(int i=0; i<n; i++){
        double x_1, y_1, x_2, y_2;
        cin >> x_1 >> y_1 >> x_2 >> y_2;
        if(x_2 == x_1 || x_2 > 0 && x_1 > 0 || x_2 < 0 && x_1 < 0) continue;
        double slope = (y_2 - y_1)/(x_2 - x_1);
        double y_int = slope*(-x_1)+y_1;
        if(y_int > 0) min_intercept = min(min_intercept, y_int);
    }
    if(min_intercept > 999) min_intercept = -1.0;
    cout << setprecision(10) << min_intercept << endl;
}
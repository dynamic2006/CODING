#include <bits/stdc++.h>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int N, X, Y;
        cin >> N >> X >> Y;
        vector<int> A(N), B(N), C(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i] >> B[i] >> C[i];
        }
        auto check = [&](int w) -> bool {
            int lx = max(1, X - w), hx = min(X + Y - w - 1, X);
            for (int i = 0; i < N; i++) {
                int a = A[i], b = B[i], c = C[i], d = X + Y - w;
                if (b - a > 0) {
                    lx = max(lx, (-c + b * d + (b - a - 1)) / (b - a));
                } else if (a - b > 0) {
                    hx = min(hx, (c - b * d) / (a - b));
                } else {
                    if (a * d > c) {
                        return false;
                    }
                }
            }
            return lx <= hx;
        };
        int lo = 0, hi = X + Y - 2;
        while (hi > lo) {
            int mid = (lo + hi) / 2;
            if (check(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        cout << lo << endl;
    }
    return 0;
}

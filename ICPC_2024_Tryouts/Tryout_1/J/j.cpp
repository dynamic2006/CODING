#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int L, xNum, xDen, yNum, yDen, zNum, zDen;
    cin >> L >> xNum >> xDen >> yNum >> yDen >> zNum >> zDen;

    if(L == 0){
        cout << 1 << endl;
        return 0;
    }

    for(int i=1; i<=L; i++){
        int count = 0;
        double xFrac = (double)xNum / xDen;
        double yFrac = (double)yNum / yDen;
        double zFrac = (double)zNum / zDen;

        if((double)1/3 < xFrac && xFrac < (double)2/3) count++;
        if((double)1/3 < yFrac && yFrac < (double)2/3) count++;
        if((double)1/3 < zFrac && zFrac < (double)2/3) count++;
        if(count >= 2){
            cout << 0 << endl;
            return 0;
        }

        xNum*=3; xNum %= xDen;
        yNum*=3; yNum %= yDen;
        zNum*=3; zNum %= zDen;
    }
    cout << 1 << endl;
}
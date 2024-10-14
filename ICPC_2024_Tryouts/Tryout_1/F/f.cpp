#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    double x_1, y_1, x_2, y_2, a;
    cin >> x_1 >> y_1 >> x_2 >> y_2 >> a;

    double angle = atan2((y_2 - y_1), (x_2 - x_1));
    double centerX = (x_1 + x_2)/2;
    double centerY = (y_1 + y_2)/2;

    a/=2;
    double c = sqrt((x_1-x_2)*(x_1-x_2) + (y_1-y_2)*(y_1-y_2)) / 2;
    double b = sqrt(a*a - c*c);

    double deltaX = sqrt(a*a*cos(angle)*cos(angle) + b*b*sin(angle)*sin(angle));
    double deltaY = sqrt(a*a*sin(angle)*sin(angle) + b*b*cos(angle)*cos(angle));

    double xLow = centerX - deltaX;
    double xHigh = centerX + deltaX;
    double yLow = centerY - deltaY;
    double yHigh = centerY + deltaY;

    cout << setprecision(10) << xLow << " " << yLow << " " << xHigh << " " << yHigh << endl;
    
}


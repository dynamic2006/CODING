#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x_1, y_1, x_2, y_2;
ll n; 
string wind;

ll xChangeWindCycle = 0, yChangeWindCycle = 0;

bool enoughDays(ll days){
    //calculate the new starting position after days due to the wind
    ll cycles = days/n;
    ll xStart = x_1 + (cycles * xChangeWindCycle);
    ll yStart = y_1 + (cycles * yChangeWindCycle);
    for(ll i=0; i < (days % n); i++){
        if(wind[i] == 'U') yStart++;
        else if(wind[i] == 'D') yStart--;
        else if(wind[i] == 'R') xStart++;
        else xStart--;
    }

    //now we have the correct starting position
    //compare the needed moves to the days, if too many moves needed, return false
    if(abs(x_2 - xStart) + abs(y_2 - yStart) > days) return false;
    return true;

}

ll binarySearch(ll lo, ll hi){
    hi++;
    while(lo < hi){
        ll mid = lo + (hi - lo)/2;
        if(enoughDays(mid)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    return lo;
}

int main() {
    //freopen("magic.in" , "r" , stdin);

    cin >> x_1 >> y_1;
    cin >> x_2 >> y_2;
    cin >> n;
    cin >> wind;
    for(ll i=0; i<n; i++){
        if(wind[i] == 'U') yChangeWindCycle++;
        else if(wind[i] == 'D') yChangeWindCycle--;
        else if(wind[i] == 'R') xChangeWindCycle++;
        else xChangeWindCycle--;
    }

    //each wind cycle has length n
    //for a solution to exist, must be able to improve position by atleast 1 per wind cycle
    //so worst case scenario, we need to move abs(x_2 - x_1) + abs(y_2 - y_1) time overall, 1 move per cycle
    //so for n move of a cycle, we do one move of improvement --> n*(abs(x_2 - x_1) + abs(y_2 - y_1)) moves AT MOST
    ll minDays = binarySearch(1 , n*(abs(x_2 - x_1) + abs(y_2 - y_1)));
    if(minDays > n*(abs(x_2 - x_1) + abs(y_2 - y_1))) minDays = -1;
    cout << minDays << endl;

}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll xZero, yZero, xOne, yOne, cycLen;
ll xDiff, yDiff, xPerCycle=0, yPerCycle=0;
string cycle;

bool valid(ll days){
    //for a given number of days the wind mvmts are known
    //find the overall displacement due to wind
    //then other diff must be made up by ship sailing
    //note that if destination can be reached in some d < days
    //then this process will also show that days is valid
    //because do all same mvmts for d days, then for the rest
    //just make a mvmt that is the opposite of the wind

    ll cycles = days / cycLen , curX = xZero, curY = yZero, leftover = days % cycLen;
    curX += cycles * xPerCycle; curY += cycles * yPerCycle;

    for(ll i=0; i<leftover; i++){
        if (cycle[i] == 'R') curX++;
        else if (cycle[i] == 'L') curX--;
        else if (cycle[i] == 'U') curY++;
        else curY--;
    }

    if(abs(curX - xOne) + abs(curY - yOne) <= days) return true;
    return false;

}

ll binarySearch(ll lo , ll hi){
    hi++;
    while(lo < hi){
        ll mid = lo + (hi - lo)/2;
        if(valid(mid)) hi = mid;
        else lo = mid+1;
    }
    return lo;
}

int main(){

    //freopen("ship.in" , "r" , stdin);

    //key idea -- should be able to improve ship position
    //by atleast one over the course of one cycle
    //so takes atmost (xdiff + ydiff)*cycLen days

    cin >> xZero >> yZero;
    cin >> xOne >> yOne;
    cin >> cycLen;
    cin >> cycle;

    for(ll i=0; i<cycLen; i++){
        if (cycle[i] == 'R') xPerCycle++;
        else if (cycle[i] == 'L') xPerCycle--;
        else if (cycle[i] == 'U') yPerCycle++;
        else yPerCycle--;
    }

    //binarySearch on the minimum number of days
    //set hi as (xdiff + ydiff)*cycLen days

    xDiff = xOne - xZero; yDiff = yOne - yZero;
    ll minDays = binarySearch(0 , cycLen * (abs(xDiff) + abs(yDiff)));
    if(minDays > cycLen * (abs(xDiff) + abs(yDiff))) minDays = -1;

    cout << minDays << endl;
    return 0;

}
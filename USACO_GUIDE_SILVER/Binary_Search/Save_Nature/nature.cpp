#include <bits/stdc++.h>
using namespace std;

long long n, x, a, y, b, k;
vector<int> ticketPrices;

bool valid(int tickets){
    long long totalContribution = 0;
    int i = 0;
    
    int common = tickets / (a*b/__gcd(a,b));
    for(int j = 0; j < common; j++ , i++){
        totalContribution += (x+y)*(ticketPrices[i])/100;
    }

    int firstProg = tickets / a; firstProg -= common;
    for(int j = 0; j < firstProg; j++ , i++){
        totalContribution += x*(ticketPrices[i])/100;
    }

    int secondProg = tickets / b; secondProg -= common;
    for(int j = 0; j < secondProg; j++, i++){
        totalContribution += y*(ticketPrices[i])/100;
    }

    if(totalContribution < k) return false;
    return true;

}

int binarySearch(int lo, int hi){
    hi++;
    while(lo < hi){
        int mid = lo + (hi-lo)/2;
        if(valid(mid)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    return lo;
}

int solve(){
    cin >> n;
    ticketPrices.clear(); ticketPrices.resize(n);
    for(int i=0; i<n; i++){
        cin >> ticketPrices[i];
    }
    sort(ticketPrices.begin() , ticketPrices.end() , greater<int>());
    cin >> x >> a >> y >> b >> k;

    //for convienience -- makes sure first program has higher % than second always
    if(y > x){
        int tempX = y, tempA = b;
        y = x; b = a;
        x = tempX; a = tempA;
    }

    int neededTickets = binarySearch(1 , n);
    if(neededTickets > n) return -1;
    else return neededTickets;

}

int main(){
    //freopen("nature.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        cout << solve() << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("p1.in" , "r" , stdin);

    int n; cin >> n;
    string cows; cin >> cows;
    
    vector<int> lists(n);
    for(int i=0; i<n; i++){
        cin >> lists[i];
    }

    char first = cows[0] , second;
    // My First comment
    if(first == 'H') second = 'G';
    else second = 'H';

    int secondStart = 0, firstEnd = n-1;
    while(cows[secondStart] != second || cows[firstEnd] != first){
        if(cows[secondStart] != second) secondStart++;
        if(cows[firstEnd] != first) firstEnd--;
    }

    int cur = 0, ans = 0;
    while(cows[cur] == first){
        int end = lists[cur] - 1;
        //cout << end << " ";
        if(end >= secondStart || cur == 0 && end >= firstEnd) ans++;
        cur++;
    }
    //cout << endl;

    cout << ans << endl;

}
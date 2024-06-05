#include <bits/stdc++.h>
using namespace std;

map<int, bool> targets;

int main(){

    freopen("p3.in" , "r" , stdin);

    int t, c; cin >> t >> c;
    vector<int> prefixSum(c+1), leftPrefixSum(c+1), left2PrefixSum(c+1), rightPrefixSum(c+1), right2PrefixSum(c+1);
    prefixSum[0] = 0; leftPrefixSum[0] = 0; left2PrefixSum[0] = 0; rightPrefixSum[0] = 0; right2PrefixSum[0] = 0;

    for(int i=0; i<t; i++){
        int x; cin >> x;
        targets[x] = true;
    }

    string commands; cin >> commands;

    int pos = 0;
    for(int i=0; i<c; i++){
        if(commands[i] == 'R'){
            pos++;
        }
        else if(commands[i] == 'L'){
            pos--;
        }
        else{
            prefixSum[i+1] = prefixSum[i] + 1*targets[pos];
            leftPrefixSum[i+1] = leftPrefixSum[i] + 1*targets[pos-1];
            left2PrefixSum[i+1] = left2PrefixSum[i] + 1*targets[pos-2];
            rightPrefixSum[i+1] = rightPrefixSum[i] + 1*targets[pos+1];
            right2PrefixSum[i+1] = right2PrefixSum[i] + 1*targets[pos+2];
        }
    }

    //go thru command string, alter each char, find max hit targets over all chars
    int ans = 0;
    for(int i=0; i<c; i++){
        if(commands[i] == 'R'){
            //try switching to F -> use leftPrefixSum
            ans = max(ans, prefixSum[i] + (leftPrefixSum[c] - leftPrefixSum[i]));
            //try switching to L -> use left2PrefixSum
            ans = max(ans, prefixSum[i] + (left2PrefixSum[c] - left2PrefixSum[i]));
        }
        else if(commands[i] == 'L'){
            //try switching to F -> use rightPrefixSum
            ans = max(ans, prefixSum[i] + (rightPrefixSum[c] - rightPrefixSum[i]));
            //try switching to L -> use right2PrefixSum
            ans = max(ans, prefixSum[i] + (right2PrefixSum[c] - right2PrefixSum[i]));
        }
        else{
            //this is if char is 'F'
            //try switching to R
            
            //try switching to L
        }
    }

    
}
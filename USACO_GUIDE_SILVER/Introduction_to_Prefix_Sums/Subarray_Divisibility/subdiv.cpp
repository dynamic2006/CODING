#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("subdiv.in" , "r" , stdin);
    int n; cin >> n;
    long long answer = 0;
    
    vector<long long> prefix(n+1);
    prefix[0] = 0;
    map<long long, long long> prefix_occurences;
    prefix_occurences[0] = 1;
    
    for(int i=1; i<=n; i++)
    {
        cin >> prefix[i];
        prefix[i] += prefix[i-1];

        int index = prefix[i] % n; // we only care about modulo since n must divide sum of subarray

        if(prefix[i] % n < 0) // convert the index into a positive number
            index += n;

        answer += prefix_occurences[index];
        prefix_occurences[index]++;
    }
    cout << answer;
    
}
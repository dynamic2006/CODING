#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("div7.in" , "r" , stdin);
    freopen("div7.out" , "w" , stdout);
    
    int n; cin >> n;
    vector<int> ids(n+1); ids[0] = 0; //vector to store the ids of the cows
    vector<int> prefix(n+1); prefix[0] = 0; //prefix sum vector for modded sum cow ids (sum MOD 7)
    for(int i=1; i<=n; i++)
    {
        cin >> ids[i];
        prefix[i] = (prefix[i-1] + ids[i]) % 7; //filling in the prefix sums
    }

    int max_len = 0; //this will be the answer
    int first_occurence[7] = {0,0,0,0,0,0,0}; //stores the first occurence of each remainder MOD 7 (0,1,2,3,4,5,6)

    for(int i=1; i<=n; i++){
        if(first_occurence[prefix[i]] == 0) //if remainder has not occured before...
            first_occurence[prefix[i]] = i; //...then set this index as the first occurence of the remainder
        max_len = max( max_len, i - first_occurence[prefix[i]]); //update max_length
    }

    cout << max_len << endl;

}

//make an array that stores the first occurence of each remainder to increase efficiency
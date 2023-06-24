#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int rows = text1.size(), cols = text2.size();
        int dp[rows+1][cols+1];
        for(int i=0; i<=rows; i++){
            for(int j=0; j<=cols; j++){
                dp[i][j] = 0;
            }
        }

        for(int i=1; i<=rows; i++){
            for(int j=1; j<=cols; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[rows][cols];

    }
};

//full tutorial on USACO guide
//dp[i][j] is max subsequence length for first i letters of text1, and first j letters of text2
//if text1[i] == text2[j] then max length is dp[i-1][j-1] + 1 since a new common letter is added
//otherwise, the max length is the max of dp[i-1][j] and dp[i][j-1]
//since in this case we need to choose whether to increment i or j by one
//to get the maximum length
#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("diamond.in" , "r" , stdin);
    freopen("diamond.out" , "w" , stdout);

    int n , k; cin >> n >> k;
    vector<int> diamond_sizes(n);
    for(int i=0; i<n; i++){
        cin >> diamond_sizes[i];
    }
    sort(diamond_sizes.begin() , diamond_sizes.end());

    vector<int> caseSizes(n);
    int left = 0, right = 0;
    while(left < n){
        while(right < n && diamond_sizes[right] - diamond_sizes[left] <= k) right++;
        caseSizes[left] = right - left; //right excluded, left included
        left++;
    }

    vector<int> maxFollowingCaseSizes(n+1); maxFollowingCaseSizes[n] = 0;
    for(int i=n-1; i>=0; i--){
        //suffix sum -- finds the 
        maxFollowingCaseSizes[i] = max(maxFollowingCaseSizes[i+1] , caseSizes[i]);
    }

    int maximum_total_diamonds = 0;
    for(int l=0; l<n; l++){
        //find the maximum total diamonds in the two cases combined over all minimum diamond values l
        //caseSizes[l] gets the diamonds for case 1, maxFollowingCaseSizes[l+caseSizes[l]] gets the corresponding largest case 2 size
        //caseSizes is 0-indexed but maxFollowingCaseSizes is 1-indexed, so the index l+caseSizes[l] will not include diamonds from case1
        //note that for any case l, the maxFollowingCaseSizes[l] must be n-l (only that many diamonds left larger than lth diamond)
        //so if maxFollowingCaseSizes[l] is n-l at most, then l+caseSizes[l] is at most (n-l)+(l)=n, so the index never goes out of bounds
        maximum_total_diamonds = max(maximum_total_diamonds , caseSizes[l] + maxFollowingCaseSizes[l + caseSizes[l]]);
    }

    cout << maximum_total_diamonds << endl;
}
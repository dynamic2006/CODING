#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("berries.in" , "r" , stdin);
    freopen("berries.out" , "w" , stdout);

    int n, k; cin >> n >> k;
    vector<int> berryTrees(n);
    for(int i=0; i<n; i++){
        cin >> berryTrees[i];
    }
    sort(berryTrees.begin() , berryTrees.end());

    long long maxValue = 0;
    vector<int> tempBerryTrees;
    for(long long minElsieBasket = 1; minElsieBasket <= *berryTrees.rbegin(); minElsieBasket++){
        tempBerryTrees.clear();
        tempBerryTrees = berryTrees;
        long long totalBaskets = 0;
        for(int x = 0; x<tempBerryTrees.size(); x++){
            totalBaskets += (tempBerryTrees[x])/minElsieBasket;
            tempBerryTrees[x] %= minElsieBasket;
        }
        
        //this value of minBasket is too large, previous one works tho
        if(totalBaskets < k/2){
            break;
        }

        //all baskets are full with minBasket berries
        if(totalBaskets >= k){
            maxValue = max(maxValue , minElsieBasket*(k/2));
            continue;
        }

        long long bessieFullBaskets = totalBaskets - (k/2);

        //otherwise some of Bessie's baskets have less than minElsieBasket berries
        sort(tempBerryTrees.begin() , tempBerryTrees.end());
        long long extraBerries = 0;
        while(totalBaskets != k && !tempBerryTrees.empty()){
            extraBerries += *tempBerryTrees.rbegin();
            totalBaskets++; tempBerryTrees.pop_back();
        }
        maxValue = max(maxValue , bessieFullBaskets*minElsieBasket + extraBerries);
    }
    cout << maxValue << endl;
}
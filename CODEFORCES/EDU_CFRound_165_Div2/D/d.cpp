#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<pair<int, int>> costs(n);
        for(int i=0; i<n; i++) cin >> costs[i].second;
        for(int i=0; i<n; i++) cin >> costs[i].first;

        // cout << "CHECK" << endl;
        sort(costs.begin(), costs.end(), greater<pair<int, int>>());

        // cout << "CHECK" << endl;

        vector<ll> suffixSumAliceProfit(n);
        suffixSumAliceProfit[n-1] = max(0, costs[n-1].first - costs[n-1].second);
        for(int i=n-2; i>=0; i--){
            suffixSumAliceProfit[i] = suffixSumAliceProfit[i+1] + max(0, costs[i].first - costs[i].second);
        }

        ll aliceLoss = 0;
        priority_queue<int> pq;
        for(int i=0; i<k; i++){
            pq.push(costs[i].second);
            aliceLoss += costs[i].second;
        }

        // cout << "CHECK" << endl;

        ll maxProfit = 0;
        for(int i=k; i<n; i++){
            maxProfit = max(maxProfit, suffixSumAliceProfit[i] - aliceLoss);
            if(!pq.empty() && costs[i].second < pq.top()){
                // cout << "CHECK" << endl;
                aliceLoss -= pq.top();
                pq.pop(); pq.push(costs[i].second);
                aliceLoss += costs[i].second;
            }
        }

        // cout << "CHECK" << endl;

        cout << maxProfit << endl;


    }
}

//alice chooses subset of items to buy
//if alice bought less than k items, bob takes all for free
//otherwise bob takes k items for free and for the rest of the chosen items, bob will buy then form Alice for b_i price

//IDEAS
//alice should NEVER take less than k items -- better to not take any items at all
//for each item -- if alice profits then she should buy it
//sort items in decreasing order cost to Bob
//keep priority queue of least expensive k items for alice
//after first k items -- greedily take item i if it profits alice, else dont - calc with prefix sum

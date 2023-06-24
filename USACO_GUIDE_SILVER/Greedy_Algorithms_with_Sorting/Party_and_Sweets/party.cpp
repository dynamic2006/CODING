#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("party.in" , "r" , stdin);

    long long totalSweets = 0;
    long long extra = 0;
    long long n, m; cin >> n >> m;
    vector<long long> boysMin(n) , girlsMax(m);
    for(int i=0; i<n; i++){
        cin >> boysMin[i];
        totalSweets += m*boysMin[i];
    }
    for(int i=0; i<m; i++){
        cin >> girlsMax[i];
        extra += girlsMax[i];
    }

    sort(boysMin.begin() , boysMin.end());
    sort(girlsMax.begin() , girlsMax.end());

    if(*boysMin.rbegin() > *girlsMax.begin()){
        cout << "-1" << endl; return 0;
    }

    totalSweets += extra - (m)*(*boysMin.rbegin());
    
    if(*boysMin.rbegin() < *girlsMax.begin()){
        totalSweets += boysMin[boysMin.size() - 1] - boysMin[boysMin.size() - 2];
    }

    cout << totalSweets << endl;
    return 0;

}
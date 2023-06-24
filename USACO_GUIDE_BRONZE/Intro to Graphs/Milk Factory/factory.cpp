#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("factory.in" , "r" , stdin);
    freopen("factory.out" , "w", stdout);

    map<int , set<int>> stations;

    int n, a, b; cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        stations[b].insert(a); //can get to station b from station a
    }

    for(int i=1; i<=n; i++){
        //iterate through stations
        //end search if it connects to n-1 stations
        int connections = 0;
        vector<int> stack; stack.push_back(i);
        while(stack.size() != 0){
            for(const int& station : stations[stack[0]]){
                connections++; stack.push_back(station);
                if(connections == n-1){
                    cout << i; return 0;
                }
            }
            stack.erase(stack.begin());
        }
    }
    cout << -1;

}
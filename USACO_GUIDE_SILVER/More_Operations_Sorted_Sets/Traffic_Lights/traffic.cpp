#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("traffic.in" , "r" , stdin);
    int x, n, light_pos; cin >> x >> n;
    set<int> lights; multiset<int> gaps; 
    lights.insert(0); lights.insert(x); gaps.insert(x);
    set<int>::iterator it = lights.begin();
    for(int i=0; i<n; i++){
        cin >> light_pos;
        it = lights.insert(light_pos).first;
        gaps.insert(*(it) - *prev(it));
        gaps.insert(*next(it) - *(it));
        gaps.erase(gaps.find(*next(it) - *prev(it)));
        
        cout << *prev(gaps.end()) << endl;
    }
    return 0;
    
    // for(auto x : gaps){
    //     cout << x << endl;
    // }
}
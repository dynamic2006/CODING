#include <bits/stdc++.h>
using namespace std;

vector<int> removedNums;

//given a starting value and the array, checks if the value of x is valid
//pass arr multiset by copy constructor so that original isn't changed
bool check(multiset<int> arr, int x){
    while(!arr.empty()){
        if(arr.find(x - *arr.rbegin()) != arr.end() && arr.find(x - *arr.rbegin()) != prev(arr.end())){
            removedNums.push_back(*arr.rbegin());
            removedNums.push_back(x - *arr.rbegin());

            arr.erase(arr.find(x - *(arr.rbegin())));
            x = *arr.rbegin();
            arr.erase(prev(arr.end()));
        }
        else{
            removedNums.clear();
            return false;
        }
    }
    return true;
}

void solve(){
    int n , num; cin >> n;
    multiset<int> arr;

    for(int i=0; i<2*n; i++){
        cin >> num; arr.insert(num);
    }

    multiset<int>::iterator start = arr.begin();
    while(start != prev(arr.end())){
        int x = *start + *arr.rbegin();
        if(check(arr , x)){
            cout << "YES" << endl;
            cout << x << endl;
            for(int i=0; i<removedNums.size(); i+=2){
                cout << removedNums[i] << " " << removedNums[i+1] << endl;
            }
            removedNums.clear();
            return;
        }
        start++;
    }
    cout << "NO" << endl;
    return;

}

int main(){
    //freopen("array.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        solve();
    }
}
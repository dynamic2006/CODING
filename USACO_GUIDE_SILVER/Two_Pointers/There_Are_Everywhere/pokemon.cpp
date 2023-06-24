#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("pokemon.in" , "r" , stdin);
    int n; cin >> n;
    string flats; cin >> flats;
    set<char> distinct_flats;
    for(int i=0; i<n; i++){
        distinct_flats.insert(flats[i]);
    }

    map<char , int> cur_pokemon; cur_pokemon[flats[0]] = 1;
    int left = 0 , right = 1, min_range = n+1;
    while(left < right){
        while(cur_pokemon.size() != distinct_flats.size() && right < n){
            cur_pokemon[flats[right++]]++;
        }
        if(cur_pokemon.size() == distinct_flats.size()){
            min_range = min(min_range , right - left); //include right, exclude left
        }
        if(--cur_pokemon[flats[left]] == 0)
            cur_pokemon.erase(flats[left]);
        left++;
    }
    cout << min_range << endl;
    return 0;
}
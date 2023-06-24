#include <bits/stdc++.h>
using namespace std;

map<char, int> occ;

void resetOcc(){
    occ['b'] = 0;
    occ['e'] = 0;
    occ['s'] = 0;
    occ['i'] = 0;
}

bool check(){
    if(occ['b'] >= 1 && occ['e'] >= 2 && occ['i'] >= 1 && occ['s'] >= 2) return true;
    else return false;
}

int main(){
    //freopen("p3.in" , "r" , stdin);

    string s; cin >> s;
    //cout << "SIZE " << s.size() << endl;
    int l=0, r=0;
    long long ans = 0;
    resetOcc();
    while(r < s.size()){
        long long temp = 0;
        while(s[r] != 'b' && r < s.size()) r++;
        occ['b'] = 1; l = r;
        while(!check() && r < s.size()){
            //cout << "LENGHTENING" << endl;
            r++;
            occ[s[r]]++;
        }
        while(occ['b'] > 1 && s[l+1] == 'b' && check()){
            //cout << "SHORTENING" << endl;
            occ['b']--;
            l++;
        }
        temp += (s.size() - r)*(l+1);
        ans += temp;
        //resetOcc();
        //cout << r << " " << l << " TEMP " << temp << endl;
        //cout << ans << endl;

        while(s[l+1] != 'b'){
            //cout << "MOVING" << endl;
            occ[s[l]]--;
            l++;
            if(l == r) r++;
            if(r >= s.size()) break;
        }
        occ[s[l]]--;
    }
    cout << ans << endl;

}
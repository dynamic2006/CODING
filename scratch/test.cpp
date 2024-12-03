#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.in", "r", stdin);

    string s;
    ll total = 0;
    ll count = 0;
    while(getline(cin, s)){
        cout << s << endl;
        for(int i=0; i<s.size()-2; i++){
            if(s[i] == 'm' && s[i+1] == 'u' && s[i+2] == 'l'){
                bool found = false;
                for(int a = 0; a<=999; a++){
                    for(int b=0; b<=999; b++){
                        string aStr = to_string(a), bStr = to_string(b);
                        string test = "mul(" + aStr + ","  + bStr + ")";
                        string cur = "";
                        for(int x=i; x<min(s.size(), i+test.size()); x++) cur += s[x];
                        if(cur == test){
                            total += a*b;
                            found = true;
                            i += test.size();
                            cout << count << " FOUND" << endl;
                            count++;
                        }
                        if(found) break;
                    }
                    if(found) break;
                }
            }
        }
        cout << "FINISHED LINE" << endl;
    }
    cout << total << endl;
}
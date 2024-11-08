#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n; cin >> n;
    vector<string> responses(n);
    bool found = false;
    for(int i=0; i<n; i++) cin >> responses[i];
    for(int i=0; i<n; i++){
        if(i+1<n && responses[i+1] == "Present!") i++;
        else{
            cout << responses[i] << endl;
            found = true;
        }
    }
    if(!found) cout << "No Absences" << endl;
}
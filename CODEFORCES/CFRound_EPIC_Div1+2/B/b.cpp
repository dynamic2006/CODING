#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("b.in" , "r" , stdin);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        int min = 0;
        map<int, int> updates; //updates[i] is # of elements that need to be updated i times
        updates[0] = 0;
        for(int i=0; i<n; i++){
            if(a[i] <= min) updates[min - a[i]]++;
            //cout << min << "-" << a[i] << "=" << updates[abs(a[i] - min)] << " ";
            min = max(min, a[i]);
        }

        //cout << "CHECK" << endl;
        // for(auto a : updates){
        //     cout << a.first << " " << a.second << endl;
        // }

        long long ans = 0, curCount = 0;
        if(updates.size() == 0){
            //cout << "UHON" << endl;
            cout << ans << endl; continue;
        }
        for(auto it = prev(updates.end()); it != updates.begin(); it--){
            //cout << "CHECK" << endl;
            curCount += it->second;
            if(it->second != 0) ans += (it->first - prev(it)->first)*(curCount + 1);
            //cout << "ANS " << ans << endl;
        }

        cout << ans << endl;
    }
}
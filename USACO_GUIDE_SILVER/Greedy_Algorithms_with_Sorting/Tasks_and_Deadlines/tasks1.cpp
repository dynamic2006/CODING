#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
vector<pair<ll, ll>> tasks;

int main()
{
    //freopen("tasks.in" , "r" , stdin);

    cin >> n;
    tasks.resize(n);
    for(ll i=0; i<n; i++) cin >> tasks[i].first >> tasks[i].second;
    sort(tasks.begin(), tasks.end());

    ll finishTime = 0;
    ll ans = 0;
    for(ll i=0; i<n; i++){
        finishTime += tasks[i].first;
        ans += tasks[i].second;
        ans -= finishTime;
    }
    cout << ans << endl;
}
//optimal strat is to do fastest tasks first
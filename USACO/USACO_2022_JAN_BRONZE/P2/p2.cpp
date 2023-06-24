#include <bits/stdc++.h>
using namespace std;

struct AC{
    int a , b , cool , cost;
    bool on = false;
};

int n , m;
vector<AC> conds;
vector<int> stalls;

//copys -- doesn't affect og stalls vector
bool valid(vector<int> line){
    for(int i=0; i<m; i++){
        if(conds[i].on){
            for(int x=conds[i].a; x<=conds[i].b; x++){
                line[x] += conds[i].cool;
            }
        }
    }

    //check if this works
    for(int i=1; i<=100; i++){
        if(line[i] < 0) return false;
    }
    return true;
}

int main(){
    //freopen("p2.in" , "r" , stdin);

    cin >> n >> m;
    conds.resize(m);
    stalls.resize(101);

    int start, end, diff;
    for(int i=0; i<n; i++){
        cin >> start >> end >> diff;
        for(int j=start; j<=end; j++){
            stalls[j] -= diff;
        }
    }
    for(int i=0; i<m; i++){
        cin >> conds[i].a >> conds[i].b >> conds[i].cool >> conds[i].cost;
    }

    //go thru every possibility of conditioners -- only 1024 at most
    int ans = 10e7;
    for(int i=0; i<pow(2,m); i++){
        int combo = i , temp = 0;
        for(int j=0; j<m; j++){
            if(combo <= 0){
                conds[j].on = false; continue;
            }
            int rem = combo % 2;
            combo -= rem; combo /= 2;
            conds[j].on = rem;
            if(conds[j].on){
                temp += conds[j].cost;
            }
        }
        if(valid(stalls)){
            ans = min(temp , ans);
        }
    }

    cout << ans << endl;


}
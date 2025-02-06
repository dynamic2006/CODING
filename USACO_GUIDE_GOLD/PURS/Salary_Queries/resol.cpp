#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Query
{
    char op;
    int i, j;
};

struct Segtree
{
    static constexpr int unit = 0;
    int f(int a, int b){return a+b;}

    vector<int> s; int n;

    Segtree(int n=0, int def=unit): s(2*n, def), n(n){}

    void update(int pos, int val){
        for(s[pos+=n]+=val; pos/=2;){
            s[pos] = f(s[pos*2], s[pos*2+1]);
        }
    }

    int query(int b, int e){
        int ra = 0, rb = 0;
        for(b+=n, e+=n; b<e; b/=2, e/=2){
            if(b%2) ra = f(ra, s[b++]);
            if(e%2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n, q; cin >> n >> q;
    vector<int> idxes;

    vector<int> salary(n);
    for(int i=0; i<n; i++){
        cin >> salary[i];
        idxes.push_back(salary[i]);
    }

    vector<Query> queries(q);
    for(int i=0; i<q; i++){
        cin >> queries[i].op >> queries[i].i >> queries[i].j;
        if(queries[i].op == '!'){
            queries[i].i--;
            idxes.push_back(queries[i].j);
        }
    }

    sort(idxes.begin(), idxes.end());
    idxes.erase(unique(idxes.begin(), idxes.end()), idxes.end());

    map<int, int> comp;
    for(int i=0; i<idxes.size(); i++) comp[idxes[i]] = i;

    Segtree segtree(comp.size());

    for(int i=0; i<salary.size(); i++) segtree.update(comp[salary[i]], 1);

    //answer queries
    for(auto& q : queries){
        switch (q.op){
            case '!':
                //change salary of this person
                segtree.update(comp[salary[q.i]], -1);
                salary[q.i] = q.j;
                segtree.update(comp[salary[q.i]], 1);
                break;
            case '?':
                //answer query of form salaries in range [a,b]
                //for a use lower bound
                //for b use upper bound
                int x, y;
                auto a = comp.lower_bound(q.i);
                auto b = comp.upper_bound(q.j);
                if(a == comp.end()){
                    cout << 0 << endl;
                    break;
                }
                else x = a->second;

                if(b == comp.end()){
                    y = comp.size();
                }
                else y = b->second;

                cout << segtree.query(x, y) << endl;
                break;
        }
    }

}
//ideas
//make segtree nodes the diff values of salaries possible
//need to offline process the queries
//
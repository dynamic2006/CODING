#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;
// template<class T>
// using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

struct SegTree
{
    int f(int a, int b){return (a+b);}
    vector<int> s; int n;
    SegTree(int n=0, int def=0):s(2*n, 0), n(n){}

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

struct Query
{
    char op;
    int x, y;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n, q; cin >> n >> q;
    vector<int> p(n);
    for(int i=0; i<n; i++) cin >> p[i];

    vector<int> salaries = p;
    vector<Query> queries(q);
    for(int i=0; i<q; i++){
        cin >> queries[i].op >> queries[i].x >> queries[i].y;
        // cout << queries[i].op << " " << queries[i].x << " " << queries[i].y << endl;
        if(queries[i].op == '!'){
            salaries.push_back(queries[i].y);
            queries[i].x--;
        }
    }
    sort(salaries.begin(), salaries.end());
    salaries.erase(unique(salaries.begin(), salaries.end()) , salaries.end());
    // for(auto &x : salaries) cout << x << " ";
    // cout << endl;

    //now salaries contains all possible salaries
    //build an ord stat tree off it
    map<int, int> comp;
    int counter = 0;
    for(auto &x : salaries){
        comp[x] = counter++;
    }

    // Tree<int> tree;
    SegTree tree(comp.size());
    for(auto &x : p) tree.update(comp[x], 1);

    for(auto &qi : queries){
        if(qi.op == '!'){
            tree.update(comp[p[qi.x]], -1);
            p[qi.x] = qi.y;
            tree.update(comp[p[qi.x]], 1);
        }
        else{
            int b = comp.lower_bound(qi.x)->second;
            int e;

            auto it = comp.upper_bound(qi.y);
            if(it == comp.end()) e = comp.size();
            else e = it->second;

            // cout << b << " " << e << endl;
            cout << tree.query(b,e) << endl;
        }
    }
}

//ideas
//n+q is at most 4*10^5, so store all possible salary vals
//coord compress salary vals
//for update, delete previous salary and insert new salary
//use ordered set, so for query a,b use order_of_key
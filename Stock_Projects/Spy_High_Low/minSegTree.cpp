#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace chrono;

struct MinSegTree
{
    static const double unit;

    double f(double a, double b){return min(a,b);}
    vector<double> s; int n;
    MinSegTree(int n=0, double def=unit):s(2*n, def), n(n){}

    void update(int pos, double val){
        for(s[pos+=n]=val; pos/=2;){
            s[pos] = f(s[pos*2], s[pos*2+1]);
        }
    }

    double query(int b, int e){
        double ra = unit, rb = unit;
        for(b+=n, e+=n; b<e; b/=2, e/=2){
            if(b%2) ra = f(ra, s[b++]);
            if(e%2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }

    double getMin(){
        return s[1];
    }
};

const double MinSegTree::unit = DBL_MAX;
const int BUCKETSIZE = 200;

int main() {
    auto start = high_resolution_clock::now();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("low.in", "r", stdin);
    freopen("low.out", "w", stdout);

    MinSegTree segtree(BUCKETSIZE);

    double num;
    int counter = 0;
    bool filled = false;
    while(cin >> num){
        segtree.update(counter++, num);
        if(counter == 200){
            counter = 0;
            filled = true;
        }
        if(!filled) cout << "N/A" << endl;
        else cout << segtree.getMin() << endl;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " ms" << endl;
}
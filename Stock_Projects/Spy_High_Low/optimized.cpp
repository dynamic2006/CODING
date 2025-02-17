#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace chrono;

struct SegTree
{
    double fmin(double a, double b){return min(a,b);}
    double fmax(double a, double b){return max(a,b);}

    vector<double> segmin, segmax; int n;
    SegTree(int n=0):segmin(2*n, DBL_MAX), segmax(2*n, DBL_MIN), n(n){}

    void update(int pos, double valmin, double valmax){
        if(valmin > curLow && segmin[pos+n] == curLow) pushMin(pos, valmin);
        else{
            curLow = min(valmin, curLow);
            segmin[pos+n] = valmin;
        }
        if(valmax < curHigh && segmax[pos+n] == curHigh) pushMax(pos, valmax);
        else{
            curHigh = max(valmax, curHigh);
            segmax[pos+n] = valmax;
        }
    }

    void pushMin(int pos, double valmin){
        for(segmin[pos+=n]=valmin; pos/=2;){
            segmin[pos] = fmin(segmin[pos*2], segmin[pos*2+1]);
        }
        curLow = segmin[1];
    }

    void pushMax(int pos, double valmax){
        for(segmax[pos+=n]=valmax; pos/=2;){
            segmax[pos] = fmax(segmax[pos*2], segmax[pos*2+1]);
        }
        curHigh = segmax[1];
    }

    double getMin(){
        return curLow;
    }

    double getMax(){
        return curHigh;
    }

    double curLow = DBL_MAX, curHigh = DBL_MIN;
};

const int BUCKETSIZE = 200;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("hilo.in", "r", stdin);
    freopen("hilo.out", "w", stdout);

    auto start = high_resolution_clock::now();

    SegTree segtree(BUCKETSIZE);

    double hi, lo;
    int counter = 0;
    bool filled = false;
    while(cin >> hi){
        cin >> lo;
        segtree.update(counter++, lo, hi);
        if(counter == 200){
            counter = 0;
            filled = true;
        }
        if(!filled) cout << "N/A,N/A" << endl;
        else cout << segtree.getMax() << "," << segtree.getMin() << endl;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " ms" << endl;
}
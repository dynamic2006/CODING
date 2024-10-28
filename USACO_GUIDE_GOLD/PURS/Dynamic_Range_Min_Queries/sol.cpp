#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template <class T> class MinSegTree
{
    private:
        const T MAXNUM = numeric_limits<T>().max(); //maxnum

        int len;
        vector<T> segtree; //idx zero not used

        //combine used to combine lower nodes to parent node
        T combine(const T &a, const T &b){ return min(a,b); };

        void build(const vector<T> &arr, int cur, int left, int right){
            if(left == right){
                segtree[cur] = arr[left];
                return;
            }
            int mid = (left + right)/2;
            build(arr, 2*cur, left, mid);
            build(arr, 2*cur + 1, mid+1, right);
            segtree[cur] = combine(segtree[2*cur], segtree[2*cur + 1]);
        }

        void set(int ind, T val, int cur, int left, int right){
            if(left == right){
                segtree[cur] = val;
                return;
            }
            int mid = (left + right)/2;
            if(ind <= mid) set(ind, val, 2*cur, left, mid);
            else set(ind, val, 2*cur+1, mid+1, right);
            segtree[cur] = combine(segtree[2*cur], segtree[2*cur + 1]);
        }

        T range_min(int start, int end, int cur, int left, int right){
            if(right < start || end < left) return MAXNUM;
            if(start <= left && right <= end) return segtree[cur];
            int mid = (left+right)/2;
            T leftRes = range_min(start, end, 2*cur, left, mid);
            T rightRes = range_min(start, end, 2*cur+1, mid+1, right);
            return combine(leftRes, rightRes);
        }
    
    public:
        MinSegTree(int len) : len(len) {segtree = vector<T>(len*4, MAXNUM);};
        
        MinSegTree(const vector<T> &arr) : len(arr.size()){
            segtree = vector<T>(len*4, MAXNUM);
            build(arr, 1, 0, len-1);
        }

        void set(int ind, T val){ set(ind, val, 1, 0, len-1); }

        T range_min(int start, int end){ return range_min(start, end, 1, 0, len-1); }
};

int n, q;
vector<int> x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    cin >> n >> q;
    x = vector<int>(n);
    for(int i=0; i<n; i++) cin >> x[i];

    MinSegTree<int> segtree(x);
    for(int i=0; i<q; i++){
        int t, x, y; cin >> t >> x >> y;
        if(t == 1){
            segtree.set(x-1, y);
        }
        else{
            cout << segtree.range_min(x-1,y-1) << endl;
        }
    }

}
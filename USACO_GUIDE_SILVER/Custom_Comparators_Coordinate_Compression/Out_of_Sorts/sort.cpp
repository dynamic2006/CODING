#include <bits/stdc++.h>
using namespace std;

struct Num{
    long number, ogIndex, sortIndex;
};

bool cmp(Num& a, Num& b){
    if(a.number == b.number){
        return a.ogIndex < b.ogIndex;
    }
    return a.number < b.number;
}

int main(){
    freopen("sort.in" , "r" , stdin);
    freopen("sort.out" , "w" , stdout);

    long n; cin >> n;
    vector<Num> nums(n);
    for(long i=0; i<n; i++){
        cin >> nums[i].number;
        nums[i].ogIndex = i;
    }

    sort(nums.begin() , nums.end() , cmp);

    long maxDist = 0;
    for(long i=0; i<n; i++){
        //assign sorted[i] to index i
        nums[i].sortIndex = i;
        //cout << nums[i].number << " " << nums[i].ogIndex << " " << nums[i].sortIndex << endl;
        long dist = max(nums[i].ogIndex - nums[i].sortIndex , (long) 0);
        maxDist = max(maxDist , dist);
    }

    cout << maxDist + 1 << endl;
    return 0;

}
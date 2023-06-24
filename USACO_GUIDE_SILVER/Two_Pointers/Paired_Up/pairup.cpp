#include <bits/stdc++.h>
using namespace std;

struct MilkTime{
    int time, cows;
};

bool cmp (MilkTime& a, MilkTime& b){
    return a.time < b.time;
}

int main(){
    freopen("pairup.in" , "r" , stdin);
    freopen("pairup.out" , "w" , stdout);

    int n; cin >> n;
    vector<MilkTime> milktimes(n);
    for(int i=0; i<n; i++){
        cin >> milktimes[i].cows >> milktimes[i].time;
    }
    sort(milktimes.begin() , milktimes.end() , cmp);

    int left = 0, right = n-1, required_time = -1;
    while (left <= right){
        //get the amount of time for the combo of right and left milktimes
        //then the total required time is updated if this value is larger
        required_time = max(required_time , milktimes[left].time + milktimes[right].time);

        //the number of used cows is the min of left and right cows
        int used_cows = min(milktimes[left].cows , milktimes[right].cows);
        //UNLESS left is equal to right (in sample, 5 paired with 5)
        //then used_cows is divided by two to account for this
        if(left == right){used_cows = used_cows/2;}
        //adjust the cows by substracting used cows
        milktimes[left].cows -= used_cows; milktimes[right].cows -= used_cows;

        //if cows reached 0 on left and/or right, must move pointer to next idx
        if(milktimes[left].cows == 0){left++;}
        if(milktimes[right].cows == 0){right--;}

    }
    cout << required_time << endl;
}
/*
 * NOTES
 * making an array of all the values (with duplicates for the number of cows for each time) would take too long
 * instead, use two pointers and at any position, get rid of as many cows as possible
 * this number is the minimum of the cows for milktimes[left] and milktimes[right]
 * this way, large amounts of cows can be paired up in O(1) time instead of O(n)
*/
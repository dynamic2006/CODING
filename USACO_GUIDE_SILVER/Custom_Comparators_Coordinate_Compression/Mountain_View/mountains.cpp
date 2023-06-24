#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

bool cmp(Point& a, Point& b){
    return(a.y > b.y);
}

int main()
{
    freopen("mountains.in" , "r" , stdin);
    freopen("mountains.out" , "w" , stdout);

    int n; cin >> n;
    vector<Point> peaks(n);
    for(int i=0; i<n; i++){
        cin >> peaks[i].x >> peaks[i].y;
    }

    //sort peaks in decreasing y order
    sort(peaks.begin() , peaks.end() , cmp);

    //process from back and pop each time
    int diff, sum; int total = 0;
    for(int i=n-1; i>=1; i--){
        bool inside = false;
        for(int j=0; j<i; j++){
            diff = peaks[j].y - peaks[j].x;
            sum = peaks[j].y + peaks[j].x;
            if(peaks[i].y + peaks[i].x <= sum && peaks[i].y - peaks[i].x <= diff){inside = true; break;}
        }
        if(!inside){total++;}
        //peaks.pop_back();
    }

    cout << total + 1;


}
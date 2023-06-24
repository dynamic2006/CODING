#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct Point{
    //coords of the point
    int x, y;
    //sum of all distances from point to
    //other points in the same row or col
    long long heightSum, baseSum;
};

int n;
vector<Point> points;
map<int , set<pair<int , int>>> vLines; //keys are xcoords, corresponds to a vector for the of points with same xCoord (VERTICAL LINE)
map<int , set<pair<int , int>>> hLines; //keys are ycoords, corresponds to a vector for e points with same yCoord (HORIZONTAL LINE)

int main(){
    freopen("triangles.in" , "r" , stdin);
    freopen("triangles.out" , "w" , stdout);

    //INPUT
    cin >> n; points.resize(n);
    for(int i=0; i<n; i++){
        cin >> points[i].x >> points[i].y;
        vLines[points[i].x].insert({points[i].y , i});
        hLines[points[i].y].insert({points[i].x , i});
    }

    //SOLVE

    //Fill all baseSum values for each point i
    for(auto vline : vLines){
        long long sum = 0;
        for(auto pt = next(vline.second.begin()); pt != vline.second.end(); pt++){
            sum += pt->first - (vline.second.begin())->first;
        }
        points[vline.second.begin()->second].baseSum = sum;

        auto pt = next(vline.second.begin());
        for(int i=1; i<vline.second.size(); i++, pt++){
            points[pt->second].baseSum = points[prev(pt)->second].baseSum + (2*i - vline.second.size())*(pt->first - prev(pt)->first);
        }
    }

    //Fill all heightSum values for each point i
    for(auto hline : hLines){
        long long sum = 0;
        for(auto pt = next(hline.second.begin()); pt != hline.second.end(); pt++){
            sum += pt->first - (hline.second.begin())->first;
        }
        points[hline.second.begin()->second].heightSum = sum;

        auto pt = next(hline.second.begin());
        for(int i=1; i<hline.second.size(); i++, pt++){
            points[pt->second].heightSum = points[prev(pt)->second].heightSum + (2*i - hline.second.size())*(pt->first - prev(pt)->first);
        }
    }

    //calc modsum over all points
    long long modSum = 0;
    for(auto point : points){
        modSum += point.baseSum * point.heightSum;
        if(modSum > MOD) modSum %= MOD;
    }
    cout << modSum << endl;

}
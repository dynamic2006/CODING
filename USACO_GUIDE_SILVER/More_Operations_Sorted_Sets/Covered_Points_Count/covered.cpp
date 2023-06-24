#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("covered.in" , "r" , stdin);

    int n; cin >> n;
    long long num;

    map<long long , int> keyPoints;
    for(int i=0; i<2*n; i+=2){
        cin >> num;
        keyPoints[num]++;
        cin >> num;
        keyPoints[num+1]--;
    }

    vector<long long> coveredPoints(n+1);

    map<long long , int>::const_iterator pt = keyPoints.begin();
    int curOverlap = pt->second; pt++;
    while(pt != keyPoints.end()){
        coveredPoints[curOverlap] += pt->first - prev(pt)->first;
        curOverlap += pt->second; //overlap since last key point
        pt++;
    }

    for(int i=1; i<coveredPoints.size(); i++){
        cout << coveredPoints[i] << " ";
    }
    return 0;
}
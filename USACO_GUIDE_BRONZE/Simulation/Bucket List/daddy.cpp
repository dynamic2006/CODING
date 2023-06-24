#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

struct cowt
{
    int startTime;
    int endTime;
    int numOfBuckets;

    void getInput(){
        cin >> startTime >> endTime >> numOfBuckets;
    }
    void print() {
        cout << startTime << " " << endTime << " " << numOfBuckets << endl;
    }

    void useBuckets(int timeNumber, int& currentCountofBucketInUse){
        if (timeNumber == startTime) {
            currentCountofBucketInUse += numOfBuckets;
        }
        if (timeNumber == endTime) {
            currentCountofBucketInUse -= numOfBuckets;
        }
    }
};

void solve() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out" , "w" , stdout);
    vector<cowt> cowLines;
    stack<char> bucketsInUse;
    int n;
    int maxTime = 0;
    int maxBucketsInUse = 0;
    int currentCountofBucketInUse = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cowt t;
        t.getInput();
        cowLines.push_back(t);
        maxTime = max(maxTime, t.endTime);
    }

    for (int timeNo=0; timeNo<=maxTime; timeNo++) {
        for (size_t j = 0; j < n ; j++)
        {
            cowLines[j].useBuckets(timeNo, currentCountofBucketInUse);
            maxBucketsInUse = max(maxBucketsInUse, currentCountofBucketInUse);
        }
    }
    
    cout << maxBucketsInUse << endl;
}

int main(int argc, char const *argv[])
{
    solve();
    return 0;
}

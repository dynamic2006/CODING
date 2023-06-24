#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> distinct; int n; cin >> n; int x; int num = 1;
    for(int i=0; i<n; i++)
    {
        cin >> x; distinct.push_back(x);
    }

    sort(distinct.begin() , distinct.end());
    
    for(int j=1; j<n; j++)
    {
        if(distinct[j] != distinct[j-1]) {num++;}
    }

    cout << num;
}
#include <iostream>
#include <vector>
using namespace std;

int t; int n; int temp;

int solve()
{
    vector<int> entries(n);
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        cin >> temp;
        entries[i] = temp;
        sum += temp;
    }

    for(int r=n; r>0; r--)
    {
        if(sum % r != 0)
            continue;
        
        int target = sum / r;
        int temp_sum = 0;
        bool found = true;
        for(int i=0; i<n; i++)
        {
            temp_sum += entries[i];
            if(temp_sum == target)
                temp_sum = 0;
            if(temp_sum > target)
            {
                found = false;
                break;
            }
        }
        if(found)
            return (n-r);
    }
}

int main()
{

    // freopen("sleeping.in" , "r" , stdin);
    // freopen("sleeping.out" , "w" , stdout);

    cin >> t;

    for(int i=0; i<t; i++)
    {
        cin >> n;
        cout << solve() << endl;
    }
}
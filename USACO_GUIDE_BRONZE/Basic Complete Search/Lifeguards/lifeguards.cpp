#include <iostream>
using namespace std;

int time_units[1001];
int endpoints[1001];

int main()
{

    freopen("lifeguards.in" , "r" , stdin);
    freopen("lifeguards.out" , "w" , stdout);

    int n; cin >> n;
    int total = 0, max_total = 0;

    for(int i=0; i<2*n; i+=2)
    {
        cin >> endpoints[i] >> endpoints[i+1];
        for(int j=endpoints[i]; j<endpoints[i+1]; j++)
        {
            time_units[j]++;
        }
    }

    for(int i=0; i<2*n; i+=2)
    {
        for(int j=endpoints[i]; j<endpoints[i+1]; j++)
        {
            time_units[j]--;
        }
        for(int k=0; k<1001; k++)
        {
            if(time_units[k] > 0)
                total++;
        }
        if(total > max_total){max_total = total;}
        total = 0;
        for(int j=endpoints[i]; j<endpoints[i+1]; j++)
        {
            time_units[j]++;
        }
    }
    cout << max_total;
}
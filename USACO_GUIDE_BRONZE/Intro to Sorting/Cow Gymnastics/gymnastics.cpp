#include <iostream>
using namespace std;

int arr[10][20];

int main()
{
    freopen("gymnastics.in" , "r" , stdin);
    freopen("gymnastics.out" , "w" , stdout);

    int total = 0;
    int k, n, first, second; cin >> k >> n;
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for(int a=0; a<n-1; a++)
    {
        first = arr[0][a];
        for(int b=a+1; b<n; b++)
        {
            second = arr[0][b];
            bool order = true;
            for(int i=1; i<k; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(arr[i][j] == first)break;
                    if(arr[i][j] == second){order = false; break;}
                }
                if(!order)break;
            }
            if(order){total++;}

        }
    }
    cout << total;
}
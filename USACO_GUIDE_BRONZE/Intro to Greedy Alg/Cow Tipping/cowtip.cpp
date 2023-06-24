#include <iostream>
#include <string>
using namespace std;

string cows[10];

void flip(int a, int b)
{
    for(int row=0; row<=a; row++)
        for(int col=0; col<=b; col++)
            if(cows[row][col] == '0')
                cows[row][col] = '1';
            else{cows[row][col] = '0';}
}

int main()
{
    freopen("cowtip.in" , "r" , stdin);
    freopen("cowtip.out" , "w" , stdout);

    int n; cin >> n;
    int total = 0;

    for(int i=0; i<n; i++)
        cin >> cows[i];
    
    for(int k=n-1; k>=0; k--)
    {
        //this checks horizontals
        for(int i=n-1; i>=0; i--)
        {
            if(cows[i][k] == '1')
            {
                flip(i, k);
                total++;
            }
        }

        //this checks verticals
        for(int j=n-2; j>=0; j--)
        {
            if(cows[k][j] == '1')
            {
                flip(k, j);
                total++;
            }
        }
    }

    cout << total;

}
#include <iostream>
using namespace std;

char spotty[100][100];
char plain[100][100];

int main()
{

    freopen("cownomics.in" , "r" , stdin);
    freopen("cownomics.out" , "w" , stdout);

    int n, m; cin >> n >> m;
    char letter; int total = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> spotty[i][j];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> plain[i][j];
    
    for(int j=0; j<m; j++)
    {
        bool location = true;
        for(int a=0; a<n; a++)
        {
            letter = spotty[a][j];
            for(int b=0; b<n; b++)
            {
                if(plain[b][j] == letter)
                {
                    location = false;
                    break;
                }
            }
            if(!location) break;
        }
        if(location) total++;
    }

    cout << total;
}
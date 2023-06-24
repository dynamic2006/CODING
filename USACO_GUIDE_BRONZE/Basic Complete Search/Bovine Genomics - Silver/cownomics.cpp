#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    freopen("cownomics.in" , "r" , stdin);
    freopen("cownomics.out" , "w" , stdout);

    int n, m; cin >> n >> m;
    string genome;

    vector<vector<int>> spotted(n, vector<int>(m));

    for(int s=0; s<n; s++)
    {
        cin >> genome;
        for(int g=0; g<m; g++)
        {
            if(genome[g] == 'A') spotted[s][g] = 0;
            if(genome[g] == 'T') spotted[s][g] = 1;
            if(genome[g] == 'C') spotted[s][g] = 2;
            if(genome[g] == 'G') spotted[s][g] = 3;
            
        }
        
    }

    vector<vector<int>> plain(n, vector<int>(m));

    for(int p=0; p<n; p++)
    {
        cin >> genome;
        for(int g=0; g<m; g++)
        {
            if(genome[g] == 'A') plain[p][g] = 0;
            if(genome[g] == 'T') plain[p][g] = 1;
            if(genome[g] == 'C') plain[p][g] = 2;
            if(genome[g] == 'G') plain[p][g] = 3;
            
        }
        
    }

    int total = 0;

    for(int x=0; x<m; x++)
    {
        for(int y=x+1; y<m; y++)
        {
            for(int z=y+1; z<m; z++)
            {
                vector<bool> has_spots(64);
                bool good = true;
                for(int i=0; i<n; i++)
                {
                    int idex = 16*spotted[i][x] + 4*spotted[i][y] + spotted[i][z];
                    has_spots[idex] = true;
                }
                for(int j=0; j<n; j++)
                {
                    int jdex = 16*plain[j][x] + 4*plain[j][y] + plain[j][z];
                    if (has_spots[jdex])
                    {
                        good = false;
                        break;
                    }
                }
                total += good;
            }
        }
    }

    cout << total;
}
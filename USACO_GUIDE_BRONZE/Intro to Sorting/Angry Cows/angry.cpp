#include <bits/stdc++.h>
using namespace std;

int explode_right(vector<int>& vecPos, int start)
{
    int total = 0;
    int blast_radius = 1;
    int end = start;

    while(end < vecPos.size() - 1)
    {
        if(vecPos[start] + blast_radius >= vecPos[end+1])
        {
            end++; total++;
        }
        else if(end == start)
            return total;
        else
        {
            start = end;
            blast_radius++;
        }
    }
    return total;

}

int explode_left(vector<int>& vecPos, int start)
{
    int total = 0;
    int blast_radius = 1;
    int end = start;

    while(end > 0)
    {
        if(vecPos[start] - blast_radius <= vecPos[end-1])
        {
            end--; total++;
        }
        else if(end == start)
            return total;
        else
        {
            start = end;
            blast_radius++;
        }
    }
    return total;
}

int main()
{
    freopen("angry.in" , "r" , stdin);
    freopen("angry.out" , "w" , stdout);

    int n; cin >> n;
    vector<int> pos(n);
    
    for(int i=0; i<n; i++)
    {
        cin >> pos[i];
    }
    sort(pos.begin() , pos.end());

    int maximum = 0;
    for(int i=0; i<pos.size();i++)
    {
        maximum = max(maximum, explode_right(pos, i) + explode_left(pos, i) + 1);
    }

    cout << maximum << endl;

}
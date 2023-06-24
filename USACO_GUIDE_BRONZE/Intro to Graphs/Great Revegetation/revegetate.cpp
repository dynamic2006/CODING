#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("revegetate.in" , "r" , stdin);
    freopen("revegetate.out" , "w" , stdout);

    int n, m; cin >> n >> m;
    map<int , set<int>> adj; // adjacency list -- each map key links to a set

    int p1, p2;
    for(int i=0; i<m; i++)
    {
        cin >> p1 >> p2;
        //each pasture grass type must differ from the other "adjacent" ones
        //then every cow has two different grass type options
        adj[p1].insert(p2);
        adj[p2].insert(p1);
    }

    map<int,int> pasture; //stores type of grass for each pasture
    set<int> types;
    //pasture[1] = 1;

    //for each pasture in the adjacency list...
    for(auto x : adj)
    {
        set<int> used_types;

        //if the pasture hasn't already been taken care of previously...
        if(!pasture.count(x.first))
        {
            //go through the adjacent pastures to the current one
            for(auto y : x.second)
            {
                //find which grass types have been used already
                //build the used_types set
                if(pasture.count(y))
                    used_types.insert(pasture[y]);
            }

            for(int i=1; i<=4; i++) //4 types of grass
            {
                if(!used_types.count(i))
                {
                    //sets grass type to be the smallest (first available one)
                    pasture[x.first] = i;
                    break;
                }
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        //set any unrestricted pastures to grass type 1 to minimize answer
        if(!pasture.count(i))
            pasture[i] = 1;
        cout << pasture[i];
    }
    cout << endl;
}
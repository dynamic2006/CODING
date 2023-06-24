#include <bits/stdc++.h>
using namespace std;

struct Cow
{
    int shakes = 0;
    bool infected = false;
};

struct Entry
{
    int time, cowx, cowy;
};

bool compare(Entry a, Entry b)
{
    return(a.time < b.time);
}

int main()
{
    freopen("tracing.in" , "r" , stdin);
    freopen("tracing.out" , "w" , stdout);

    int n; int t; cin >> n >> t;
    vector<Entry> entries(t);
    string final_state; cin >> final_state;
    for(int i=0; i<t; i++)
    {
        cin >> entries[i].time >> entries[i].cowx >> entries[i].cowy;
    }
    sort(entries.begin() , entries.end() , compare);

    int total = 0, min_k = 251, max_k = 0;

    //simulate each cow as patient zero
    for(int i=0; i<n; i++)
    {   
        bool cow_works = false;
        for(int k=0; k<251; k++)
        {
            vector<Cow> cows(n);
            cows[i].infected = true;
            bool k_works = true;
            for(int e=0; e<t; e++)
            {
                if(cows[entries[e].cowx - 1].infected)
                    cows[entries[e].cowx - 1].shakes++;
                if(cows[entries[e].cowy - 1].infected)
                    cows[entries[e].cowy - 1].shakes++;

                if(cows[entries[e].cowx - 1].infected && cows[entries[e].cowx - 1].shakes <= k)
                    cows[entries[e].cowy - 1].infected = true;
                if(cows[entries[e].cowy - 1].infected && cows[entries[e].cowy - 1].shakes <= k)
                    cows[entries[e].cowx - 1].infected = true;    
            }

            for(int j=0; j<n; j++)
            {
                if((cows[j].infected && final_state[j] == '1') || (!cows[j].infected && final_state[j] == '0'))
                    continue;
                else
                {
                    k_works = false;
                    break;
                }
            }

            if(k_works)
            {
                cow_works = true;
                min_k = min(min_k, k);
                max_k = max(max_k, k);
            }
        }

        if(cow_works)
            total++;
    }

    if(max_k == 250)
        cout << total << " " << min_k << " Infinity" << endl;
    else
        cout << total << " " << min_k << " " << max_k << endl;
}

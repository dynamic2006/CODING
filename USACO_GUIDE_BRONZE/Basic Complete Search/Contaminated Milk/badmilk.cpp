#include <bits/stdc++.h>
using namespace std;

struct Entry
{
    int person, milk = -1, time;
};

bool compare(Entry& a, Entry& b)
{
    return (a.time < b.time);
}

int main()
{
    freopen("badmilk.in" , "r" , stdin);
    freopen("badmilk.out" , "w" , stdout);

    int n, m, d, s; cin >> n >> m >> d >> s;
    vector<Entry> script(d+s);
    for(int i=0; i<d; i++)
        cin >> script[i].person >> script[i].milk >> script[i].time;
    for(int i=d; i<d+s; i++)
        cin >> script[i].person >> script[i].time;
    
    sort(script.begin() , script.end() , compare);

    int max_doses = 0;

    for(int milk = 1; milk<=m; milk++)
    {
        vector<bool> possible_sick(n+1);
        bool possible = true;
        vector<Entry>::iterator entry = script.begin();
        while(entry != script.end())
        {
            if(entry->milk == milk)
                possible_sick[entry->person] = true;
            //if a person got sick, but didn't drink the current milk, the current milk isn't bad
            if(entry->milk == -1)
                if(!possible_sick[entry->person])
                {
                    possible = false;
                    break;
                }

            entry++;
        }
        if(possible)
        {
            int total = 0;
            vector<bool>::iterator it = possible_sick.begin();
            while(it != possible_sick.end())
            {
                if(*it){total++;}
                it++;
            }
            max_doses = max(max_doses, total);
        }
    }

    cout << max_doses;

}

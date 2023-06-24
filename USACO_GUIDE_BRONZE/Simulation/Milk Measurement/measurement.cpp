#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Entry
{
    int day, change;
    string cow = "";
};

bool sorter(Entry a, Entry b)
{
    return (a.day < b.day);
}

bool is_max(int a, int b, int c)
{
    return(a == max(a, max(b,c)));
}

int main()
{

    freopen("measurement.in" , "r", stdin);
    freopen("measurement.out" , "w" , stdout);

    int n; cin >> n;
    int temp_day, temp_change; string temp_cow;

    vector<Entry> logbook(n);

    for(int i=0; i< n; i++)
    {
        cin >> temp_day >> temp_cow >> temp_change;
        logbook[i].day = temp_day;
        logbook[i].cow = temp_cow;
        logbook[i].change = temp_change;
    }

    sort(logbook.begin() , logbook.end(), sorter);

    int m = 7, e = 7, b = 7;
    bool m_max = true, e_max = true, b_max = true;
    string name; int num, total = 0;

    for(int i=0; i<n; i++)
    {
        name = logbook[i].cow;
        num = logbook[i].change;
    
        if(name == "Mildred")
        {
            m+=num;
        }
        if(name == "Bessie")
        {
            b+=num;
        }
        if(name == "Elsie")
        {
            e+=num;
        }

        if(m_max != is_max(m,b,e) || e_max != is_max(e,b,m) || b_max != is_max(b, m, e))
            total++;

        m_max = is_max(m,b,e);
        e_max = is_max(e,b,m);
        b_max = is_max(b,m,e);
    }

    cout << total;
}


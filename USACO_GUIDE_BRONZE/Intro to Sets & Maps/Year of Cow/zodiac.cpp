#include <bits/stdc++.h>
using namespace std;

map<string, pair<string, int>> cows;
map<string, int> years;
string zodiacs[12] = {"Ox" , "Tiger" , "Rabbit" , "Dragon" , "Snake" , "Horse" , "Goat" , "Monkey" , "Rooster" , "Dog" , "Pig" , "Rat"};

int main()
{
    // freopen("zodiac.in" , "r" , stdin);
    // freopen("zodiac.out" , "w" , stdout);

    cows["Bessie"] = {"Ox", 0};
    for(int i=0; i<12; i++)
    {
        years[zodiacs[i]] = i;
    }

    int n; cin >> n;
    string new_cow, born, in, relation, year, word, from, old_cow;
    for(int i=0; i<n; i++)
    {
        cin >> new_cow >> born >> in >> relation >> year >> word >> from >> old_cow;

        //filling in cows ages + years
        //find diff of years in a cycle -- positive if old cow comes after new cow
        int diff = years[cows[old_cow].first] - years[year];
        int new_age;

        if(diff > 0)
        {
            new_age = cows[old_cow].second - (diff);
            if(relation == "next")
                new_age += 12;
        }
        else if(diff < 0)
        {
            new_age = cows[old_cow].second - (diff);
            if(relation == "previous")
                new_age -= 12;
        }
        else
        {
            if(relation == "previous")
                new_age = cows[old_cow].second - 12;
            else new_age = cows[old_cow].second + 12;   
        }

        cows[new_cow] = {year , new_age};
    }
    cout << abs(cows["Elsie"].second) << endl;
}
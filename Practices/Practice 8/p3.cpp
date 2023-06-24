#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    unordered_map <string, int> hm;
    unordered_map <string, int>::iterator iter;

    hm["D"] = 40;
    hm["C"] = 30;
    hm["A"] = 10;
    hm["B"] = 20;
    hm["E"] = 50;

    for(iter=hm.begin(); iter!=hm.end(); iter++)
        cout << iter->first << " " << iter->second << endl;
}
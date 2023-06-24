#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    
    // freopen("photoshoot.in" , "r" , stdin);
    // freopen("photoshoot.out" , "w" , stdout);

    int n; cin >> n;
    string cowline; cin >> cowline;
    string new_str = "";

    for(int i=0; i<cowline.size(); i+=2)
    {
        if(cowline[i] == cowline[i+1])
            continue;
        else if(cowline[i] == 'H' && new_str[new_str.size() - 1] != 'A')
            new_str += 'A';
        else if(cowline[i] == 'G' && new_str[new_str.size() - 1] != 'B')
            new_str += 'B';
    }
    if(new_str[new_str.size() - 1] == 'A')
        cout << new_str.size() - 1;
    else
        cout << new_str.size();

}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("multiple.in" , "r" , stdin);
    long long total = 0; string s; cin >> s;
    vector<int> suffix_mod(s.size() + 2, 0);
    map<int, long long> residues; residues[0] = 1;

    int ten_mod = 1;
    for(int i=s.size(); i>=1; i--)
    {
        suffix_mod[i] = ((suffix_mod[i+1]) + (s[i-1] - '0')*(ten_mod %= 2019)) % 2019; //mathy methy modulo meth
        residues[suffix_mod[i]]++; ten_mod*=10; //use map as a prefix array -- sort of 
        //residues stores number of occurences for each suffix modulo (2019)
    }
    for(auto x : residues)
    {
        total += (x.second)*(x.second - 1)/2; //bascially choose 2
    }
    cout << total;
}

//note suffix sums can be more useful than prefix sums sometimes
//maps+combo is a great way to increase efficiency with prefix sums
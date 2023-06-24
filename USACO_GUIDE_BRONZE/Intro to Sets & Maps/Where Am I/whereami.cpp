#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("whereami.in" , "r" , stdin);
    freopen("whereami.out" , "w" , stdout);

    int n; cin >> n;
    string line; cin >> line;

    for(int i=1; i<=n; i++)
    {
        set<string> sequences;
        string temp = "";
        for(int j=0; j<=n-i; j++)
        {  
            for(int k=j; k<j+i; k++)
                temp += line[k];
            sequences.insert(temp);
            temp = "";
        }
        if(sequences.size() == n-i+1)
        {
            cout << i << endl;
            return 0;
        }
            
    }
}
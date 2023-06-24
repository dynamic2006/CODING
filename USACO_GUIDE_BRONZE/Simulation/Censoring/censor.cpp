#include <iostream>
#include <string>
using namespace std;

int main()
{

    freopen("censor.in" , "r" , stdin);
    freopen("censor.out" , "w" , stdout);

    string s = "";
    string t = "";
    string result = "";

    cin >> s >> t; int i = 0; int start = 0;

    while(i < s.size())
    {
        result += s[i];

        start = result.size() - t.size();
        if(start>=0)
        {
            if(result.substr(start , t.size()) == t)
            {
                result.resize(result.size() - t.size());
            }
        }
        i++;
    }

    cout << result << endl;
}
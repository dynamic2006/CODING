#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("b.in" , "r" , stdin);
    int t; cin >> t;
    for(int tc=0; tc<t; tc++){
        string a, b;
        cin >> a; cin >> b;

        int maxSubSeq = 0;
        int subseq = 0, lastidx = -1;
        //brute force this thang
        for(int bi=0; bi<b.size(); bi++){
            if(maxSubSeq == a.size()) break;
            int prevSubSeq = subseq;
            for(int ai=lastidx+1; ai<a.size(); ai++){
                if(a[ai] == b[bi]){
                    lastidx = ai;
                    subseq++;
                    break;
                }
            }
            maxSubSeq = max(maxSubSeq, subseq);
            if(prevSubSeq == subseq){
                subseq = 0;
                lastidx = -1;
            }
        }

        cout << a.size() + b.size() - maxSubSeq << endl;
    }
}
//Note this code DOES NOT pass all test cases
//mainly because the calculations for getting the total are messy
//see solution code on USACO guide for a better way for getting total
//misses 3 out of 10 cases

#include <bits/stdc++.h>
using namespace std;

struct Lifeguard
{
    int start, end, len;
    Lifeguard(){
        start = 0; end = 0; len = 0;
    }
    Lifeguard(int s, int e, int l){
        start = s; end = e; len = l;
    }
};

bool cmp(Lifeguard& a, Lifeguard& b){
    return (a.start < b.start);
}

int main()
{
    freopen("lifeguards.in" , "r" , stdin);
    //freopen("lifeguards.out" , "w" , stdout);

    int n; cin >> n;
    vector<Lifeguard> lifeguards(n+1);
    
    for(int i = 1; i<=n; i++)
    {
        cin >> lifeguards[i].start >> lifeguards[i].end;
        lifeguards[i].len = lifeguards[i].end - lifeguards[i].start;
    }
    sort(lifeguards.begin() , lifeguards.end() , cmp);
    int x = lifeguards[n].end;
    lifeguards.push_back(Lifeguard(x,x,0));
    lifeguards[0].end = lifeguards[1].start;

    //calculating total time covered by all lifeguards
    bool overlap = false;
    bool no_loss = false;
    long long total = 0;
    for(int i = 1; i<=n; i++)
    {   
        int k = lifeguards[i-1].end - lifeguards[i].start;
        if(k<0){k=0;}
        total += lifeguards[i].len - k;
        while(lifeguards[i+1].end < lifeguards[i].end){
            overlap = true;
            no_loss = true;
            i++;
        }
        if(overlap){i--;}
        overlap = false;
    }

    if(no_loss){cout << total; return 0;}

    long long min_alone = total;
    for(int i = 1; i<=n; i++)
    {
        int a = max(lifeguards[i-1].end , lifeguards[i].start);
        int b = min(lifeguards[i+1].start, lifeguards[i].end);
        long long alone = b - a;
        min_alone = min(min_alone, alone);
    }

    cout << total - min_alone;

}


/*

Note for a set up like this:

----------     *---------*     ---------
      -----------------------------

the entirity of one lifeguards time (*) is contained in another's 
so answer is just total og time in this case


so we only need to worry about cases like this:

--------- (i-1)         ---------------- (i+1)
    --------------------------- (i)

in which case:
- take max of [i-1].end and [i].start, let this be a
- take min of [i+1].start and [i].end, let this be b
- then b - a is the alone time for cow i

- for cases like the first one
- the alone time for cow (*) will be negative, so just return total time if min_alone_time < 0

*/
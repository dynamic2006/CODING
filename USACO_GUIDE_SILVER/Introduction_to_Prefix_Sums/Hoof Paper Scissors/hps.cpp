#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("hps.in", "r" , stdin);
    freopen("hps.out" , "w" , stdout);

    int answer = 0;
    int rounds; cin >> rounds;
    vector<int> h(rounds+1), p(rounds+1), s(rounds+1);
    h[0] = 0; p[0] = 0; s[0] = 0;
    
    for(int i=1; i <= rounds; i++)
    {
        h[i] = h[i-1];
        p[i] = p[i-1];
        s[i] = s[i-1];
        char move; cin >> move;
        if(move == 'H')
            p[i]++;
        else if(move == 'P')
            s[i]++;
        else h[i]++;
    }

    for(int i=1; i<=rounds; i++)
    {
        int block1 = max(h[i] , max (p[i] , s[i]));
        int block2 = max(h[rounds] - h[i] , max(p[rounds] - p[i] , s[rounds] - s[i]));
        int total_wins = block1 + block2;
        answer = max(answer, total_wins);
    }
    cout << answer;


}

/*
- This problem combines the gcd and breed counting problems
- need to split up the moves into a left and right block (since 1 switch can be done)
- and there are three categories of moves
*/
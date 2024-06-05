#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("p2.in" , "r" , stdin);

    int c, n;
    cin >> c >> n;
    vector<int> teams(n);
    //create a distances vector
    //size is 1<<c = 2^c for all possible teams of C cows
    //default value of 1000 (very large number)
    //will ultimately contain final min distances
    //for each team i, distances[i] = min distance to any inverse team
    vector<int> distances(1<<c, 1000);
    queue<int> q;

    for(int i=0; i<n; i++){
        string s; cin >> s;
        int binaryRep = 0;
        int binaryInv = 0;
        //g = 1, h = 0
        for(int j=0; j<c; j++){
            binaryRep = 2*binaryRep + (s[j] == 'G');
            binaryInv = 2*binaryInv + (s[j] == 'H');
        }
        teams[i] = binaryRep;
        //since binaryRep is a team, if binaryInv is also a team
        //then binaryInv has min dist of 0 to binaryRep
        distances[binaryInv] = 0;
        q.push(binaryInv);
    }

    //standard bfs
    while(!q.empty()){
        int a = q.front(); q.pop();
        //construct each team that is 1 away from a (adjacent)
        for(int b=0; b<c; b++){
            int ai = a ^ (1<<b); //xor to flip one bit -> ai
            //if team ai hasn't been visited yet
            if(distances[ai] == 1000){
                //push ai to be a processed node of the graph
                q.push(ai);
                //note that a is always a node that has already been processed
                //or a is an inverse team, so distance[a] = 0
                distances[ai] = distances[a] + 1;
            }
        }
    }

    //for each original team, the min distance to any inverse team is x
    //then the max distance to any team is c-x
    for(int i=0; i<n; i++){
        cout << (c - distances[teams[i]]) << endl;
    }

    return 0;
}
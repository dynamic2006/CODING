#include <bits/stdc++.h>
using namespace std;

//vector for keeping track of possible first colors
bool firstColor[10]; //1-indexed

int main(){
    freopen("art.in" , "r" , stdin);
    freopen("art.out" , "w" , stdout);

    int n; cin >> n;
    vector<string> canvas(n);

    for(int i=0; i<n; i++){
        cin >> canvas[i];
        for(int j=0; j<n; j++){
            firstColor[canvas[i][j] - '0'] = true;
        }
    }
    firstColor[0] = false;

    // for(int i=0; i<10; i++){
    //     cout << firstColor[i] <<endl;
    // }
    // return 0;

    //check if only one color -- then ans is one
    int poss = 0;
    for(int i=1; i<10; i++){
        if(firstColor[i]) poss++;
    }
    if(poss <= 1){
        cout << 1 << endl; return 0;
    }

    //otherwise go thru each cell
    //keep track of colors to right, left, up and down of cell
    //if a color repeats to right and left, up and down
    //or in a vertical and horizontal direction
    //then color of cur cell CANNOT be the first color

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            //we are looking at canvas[i][j]

            if(!firstColor[canvas[i][j] - '0']) continue;

            bool valid = true , rightColors[10] , leftColors[10] , vColors[10];

            for(int k=0; k<10; k++){
                rightColors[k] = false;
                leftColors[k] = false;
                vColors[k] = false;
            }

            //search to left
            for(int x=j; x>=0; x--){
                if(canvas[i][x] != canvas[i][j] && canvas[i][x] != '0') leftColors[canvas[i][x] - '0'] = true;
            }

            // for(int i=0; i<10; i++){
            //     cout << firstColor[i] <<endl;
            // }
            // return 0;

            //search to right -- check if any left side colors repeat
            for(int x=j; x<n; x++){
                if(canvas[i][x] != canvas[i][j] && canvas[i][x] != '0'){
                    if(leftColors[canvas[i][x] - '0']){
                        firstColor[canvas[i][j] - '0'] = false;
                        valid = false; break;
                    }
                    else rightColors[canvas[i][x] - '0'] = true;
                }
            }

            // for(int i=0; i<10; i++){
            //     cout << firstColor[i] <<endl;
            // }
            // return 0;

            if(!valid) continue;

            //search up -- check is any horizontal colors repeat
            for(int y=i; y>=0; y--){
                if(canvas[y][j] != canvas[i][j] && canvas[y][j] != '0'){
                    if(leftColors[canvas[y][j] - '0'] || rightColors[canvas[y][j] - '0']){
                        firstColor[canvas[i][j] - '0'] = false;
                        valid = false; break;
                    }
                    else vColors[canvas[y][j] - '0'] = true;
                }
            }

            if(!valid) continue;

            //search down -- if repeat in hor or vert, exit
            for(int y=i; y<n; y++){
                if(canvas[y][j] != canvas[i][j] && canvas[y][j] != '0'){
                    if(rightColors[canvas[y][j] - '0'] || leftColors[canvas[y][j] - '0'] || vColors[canvas[y][j] - '0']){
                        firstColor[canvas[i][j] - '0'] = false;
                        valid = false; break;
                    }
                }
            }

        }
    }

    //for every color in firstColor that is still true, output it
    int ans = 0;
    for(int i=1; i<10; i++){
        if(firstColor[i]){
            ans++;
        }
    }

    cout << ans << endl; return 0;

    
}
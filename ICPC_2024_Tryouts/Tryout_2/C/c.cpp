#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>> regions;
vector<string> grid;
vector<vector<bool>> vis;
bool valid;
int regStars;

void floodfill(int i, int j, int r)
{
    if(vis[i][j]) return;

    vis[i][j] = true;
    if(grid[i][j] == '*'){
        regStars++;
        // cout << "adding star to region found at " << i << " " << j << endl;
    }

    for(int a=i-1; a<=i+1; a++){
        for(int b=j-1; b<=j+1; b++){
            if(a == i && b == j) continue;
            else if(a<0 || b<0 || a>=10 || b>=10) continue;
            else if(regions[a][b] != r) continue;
            floodfill(a, b, r);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    regions = vector<vector<int>>(10, vector<int>(10));
    grid = vector<string>(10);
    vis = vector<vector<bool>>(10, vector<bool>(10, false));

    for(int i=0; i<10; i++){
        string digits; cin >> digits;
        for(int j=0; j<10; j++){
            regions[i][j] = digits[j] - '0';
        }
    }

    for(int i=0; i<10; i++) cin >> grid[i];

    //checks
    valid = true;

    //check 1: rows and cols have 2 stars exactly
    for(int i=0; i<10; i++){
        int starCount = 0;
        for(int j=0; j<10; j++){
            if(grid[i][j] == '*') starCount++;
        }
        if(starCount != 2){
            valid = false;
            // cout << "invalid at row check " << i << endl;
        }
    }

    for(int j=0; j<10; j++){
        int starCount = 0;
        for(int i=0; i<10; i++){
            if(grid[i][j] == '*') starCount++;
        }
        if(starCount != 2){
            valid = false;
            // cout << "invalid at col check" << endl;
        }
    }

    //check 2: not adj stars
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(grid[i][j] == '*'){
                for(int a=i-1; a<=i+1; a++){
                    for(int b=j-1; b<=j+1; b++){
                        if(a == i && b == j) continue;
                        else if(a<0 || b<0 || a>=10 || b>=10) continue;
                        else if(grid[a][b] == '*'){
                            valid = false;
                            // cout << "invalid at adj check" << endl;
                        }
                    }
                }
            }
        }
    }

    //check 3: exactly 2 stars per region
    //floodfill algo
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(!vis[i][j]){
                regStars = 0;
                floodfill(i, j, regions[i][j]);

                if(regStars != 2){
                    valid = false;
                    // cout << "invalid at reg check " << regions[i][j] << " with " << regStars << " stars."<< endl;
                }
            }
        }
    }

    if(valid) cout << "valid" << endl;
    else cout << "invalid" << endl;


}
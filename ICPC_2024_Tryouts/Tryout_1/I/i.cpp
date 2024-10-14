#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<bool>> lit;
vector<string> grid;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.in", "r", stdin);

    int n; cin >> n;
    lit = vector<vector<bool>>(n, vector<bool>(n, false));
    grid = vector<string>(n);
    for(int i=0; i<n; i++) cin >> grid[i];

    bool valid = true;

    //check 1: numbers
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == '.' || grid[i][j] == 'X' || grid[i][j] == '?') continue;
            else{
                int num = grid[i][j] - '0';
                int lightsAround = 0;
                if(i-1 >= 0 && grid[i-1][j] == '?') lightsAround++;
                if(i+1 < n && grid[i+1][j] == '?') lightsAround++;
                if(j-1 >= 0 && grid[i][j-1] == '?') lightsAround++;
                if(j+1 < n && grid[i][j+1] == '?') lightsAround++;
                if(lightsAround != num){
                    valid = false;
                    break;
                }
            }
        }
        if(!valid) break;
    }
    if(!valid){
        cout << 0 << endl;
        return 0;
    }

    //check 2: fill in all light
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == '?'){
                for(int a=i-1; a>=0; a--){
                    if(grid[a][j] == '.') lit[a][j] = true;
                    else if(grid[a][j] == '?'){
                        valid = false;
                        break;
                    }
                    else break;
                }
                for(int a=i+1; a<n; a++){
                    if(grid[a][j] == '.') lit[a][j] = true;
                    else if(grid[a][j] == '?'){
                        valid = false;
                        break;
                    }
                    else break;
                }
                for(int b=j-1; b>=0; b--){
                    if(grid[i][b] == '.') lit[i][b] = true;
                    else if(grid[i][b] == '?'){
                        valid = false;
                        break;
                    }
                    else break;
                }
                for(int b=j+1; b<n; b++){
                    if(grid[i][b] == '.') lit[i][b] = true;
                    else if(grid[i][b] == '?'){
                        valid = false;
                        break;
                    }
                    else break;
                }
            }
        }
        if(!valid) break;
    }
    if(!valid){
        cout << 0 << endl;
        return 0;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == '.' && lit[i][j] == false){
                valid = false;
                break;
            }
        }
        if(!valid) break;
    }
    if(!valid) cout << 0 << endl;
    else cout << 1 << endl;
}
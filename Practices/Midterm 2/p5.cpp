#include <iostream>
using namespace std;

void search(char field[10][11], int x, int y, int N, int M, char fill){
    
    if(x<0 || y<0 || x>=N || y>=M || field[x][y]!='L')
        return;

    field[x][y] = fill;

    for(int i=-1; i<2; i++){
        for(int j=-1; j<2; j++){
            search(field, x+i, y+j, N, M, fill);
        }
    }
}

int solve_it(char field[10][11], int N, int M){
    int count = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(field[i][j] == 'L'){
                count++;
                search(field,i,j,N,M,count+'0');
            }
        }
    }
    return count;
}

int main(){
    char field[10][11] = {
        "..........",
        "LLL.......",
        "L.L.......",
        ".L........",
        "....LL....",
        ".........L",
        "....L.L.L.",
        "L...LLLLL.",
        "L....LL...",
        "L....L....",
    };

    for(int q=0;q<10;q++){
        cout << field[q] << endl;
    }

    cout << "There are " << solve_it(field,10,10) << " lakes" << endl;

    for(int q=0;q<10;q++){
        cout << field[q] << endl;
    }
}
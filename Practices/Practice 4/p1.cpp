#include <iostream>
using namespace std;

void foo(){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            cout << i << j << endl;
        }
    }
}

int main() {
    foo();
}
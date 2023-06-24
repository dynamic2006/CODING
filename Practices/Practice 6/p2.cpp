#include <iostream>
using namespace std;

int countX(int n){
    int counter = 0;
    for(int i=1;i<n;i*=2){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                counter++;
            }
        }
    }
    return counter;
}

int main() {
    cout << countX(8) << endl;
}
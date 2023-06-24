#include <iostream>
using namespace std;

int countY(int n){
    int counter =0;
    for(int i=1;i<n;i*=2){
        for(int j=1;j<n;j*=2){
            for(int k=1;k<n;k*=2){
                counter++;
            }
        }
    }
    return counter;
}

int main() {
    cout << countY(8) << endl;
}
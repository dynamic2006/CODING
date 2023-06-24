#include <iostream>
using namespace std;

int outputQ(int n){
    int counter = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            counter++;
            break;
        }
    }
    return counter;
}

int main(){
    cout << outputQ(10) << endl;
}
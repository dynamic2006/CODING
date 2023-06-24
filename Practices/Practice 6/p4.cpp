#include <iostream>
#include <cmath>
using namespace std;

int countZ(int n){
    int counter = 0;
    int increment = 1, step = 1;
    while(step<n){
        step = step + increment;
        increment++;
        counter++;
    }
    return counter;
}

int main() {
    for(int i=0; i<=30; i++){
        cout << i << " " << countZ(i) << " log:" << (round(log(i)) * 2) << endl;
    }
}
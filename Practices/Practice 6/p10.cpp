#include <iostream>
#include <algorithm>
using namespace std;

void ShellSort(int Arr[], int n){
    bool atLeastOneSwap;
    for(int delta = n/2; delta>0; delta/=2){
        do{
            atLeastOneSwap = false;
            for(int i=0;(i+delta)<n;i++){
                if(Arr[i]>Arr[i+delta]){
                    swap(Arr[i],Arr[delta+i]);
                    atLeastOneSwap = true;
                }
            }
        }while(atLeastOneSwap);
    }
}

int main() {
    int values[12] = {4,7,1,5,3,2,0,8,6,9,11,10};

    ShellSort(values, 12);

    for(int i=0;i<12;i++){
        cout << values[i] << " ";
    }
    cout << endl;
}
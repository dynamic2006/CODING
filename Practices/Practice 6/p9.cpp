#include <iostream>
#include <algorithm>
using namespace std;

void bubbleSort(int Arr[], int n, int stop){
    int start = 0;
    bool atLeastOneSwap;

    do{
        atLeastOneSwap = false;
        for(int j=0; j<(n-1);j++){
            if(Arr[j] > Arr[j+1]){
                swap(Arr[j],Arr[j+1]);
                atLeastOneSwap = true;
            }
        }
        start = start + atLeastOneSwap;
        if(start == stop){
            return;
        }
    }while(atLeastOneSwap);
}

int main() {
    int values[12] = {4,7,1,5,3,2,0,8,6,9,11,10};

    bubbleSort(values, 12, 3);

    for(int i=0;i<12;i++){
        cout << values[i] << " ";
    }
    cout << endl; 
}
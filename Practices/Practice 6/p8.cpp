#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(int A[], int n, int stop){
    int start = 0;
    for(int s=2; s<=n;s++){
        int sortMe = A[s-1];
        int i=s-2;
        while(i>=0 && sortMe < A[i]){
            A[i+1] = A[i];
            --i;
        }
        A[i+1] = sortMe;
        start++;
        if(start == stop){
            return;
        }
    }
}

int main() {
    int values[12] = {4,7,1,5,3,2,0,8,6,9,11,10};

    insertionSort(values, 12, 3);

    for(int i=0;i<12;i++){
        cout << values[i] << " ";
    }
    cout << endl; 
}
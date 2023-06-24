#include <iostream>
#include <algorithm>
using namespace std;

void selectionSort(int A[], int n, int stop){
    int start = 0;

    for(int i=0;i<n;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(A[j] < A[minIndex])
                minIndex = j;
        }
        swap(A[i], A[minIndex]);

        start++;

        if(start == stop){
            return;
        }
    }
}

int main() {
    int values[12] = {4,7,1,5,3,2,0,8,6,9,11,10};

    selectionSort(values, 12, 3);

    for(int i=0;i<12;i++){
        cout << values[i] << " ";
    }
    cout << endl;
}
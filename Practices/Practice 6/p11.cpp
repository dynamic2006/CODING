#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int a[]) {
    for (int i=0; i<12; i++) {
        cout << a[i] << (i==11?"":",");
    }
    cout << endl;
}
int Partition(int a[], int lowIndex, int highIndex){
    int pivotIndex = lowIndex;
    int pivotValue = a[lowIndex];
    do{
        while(lowIndex<=highIndex && a[lowIndex]<=pivotValue)
            lowIndex++;
        while(a[highIndex]>pivotValue)
            highIndex--;
        if(lowIndex<highIndex) {
            swap(a[lowIndex],a[highIndex]);
            printArray(a);
        }
    }while(lowIndex<highIndex);

    swap(a[pivotIndex], a[highIndex]);
    printArray(a);
    pivotIndex = highIndex;
    return(pivotIndex);
}

void QuickSort(int Array[], int First, int Last, string partitionDepth){
    if(Last-First>=1){
        int PivotIndex;
        PivotIndex = Partition(Array,First,Last);
        cout << "Partition: " << partitionDepth << " First:" << First << " Last:" << Last << " PivotIndex:" << PivotIndex << endl;
        QuickSort(Array,First,PivotIndex-1, partitionDepth + ".First");
        QuickSort(Array,PivotIndex+1,Last, partitionDepth + ".Second");
    }
}

int main() {
    int values[12] = {4,7,1,5,3,2,0,8,6,9,11,10};

    QuickSort(values, 0, 11, "Root");

    for(int i=0;i<12;i++){
        cout << values[i] << " ";
    }
    cout << endl;
}
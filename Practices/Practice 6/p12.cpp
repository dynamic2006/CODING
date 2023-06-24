#include <iostream>
using namespace std;

int array_num = 12;

void printArray(int a[]) {
    for (int i=0; i<array_num; i++) {
        cout << a[i] << (i==array_num-1?"":",");
    }
    cout << endl;
}

void merge(int data[], int n1, int n2){
    int i=0, j=0, k=0;
    int* temp = new int[n1+n2];
    int* secondHalf = data + n1;

    while(i<n1 || j<n2){
        if(i == n1)
            temp[k++] = secondHalf[j++];
        else if(j == n2)
            temp[k++] = data[i++];
        else if(data[i] < secondHalf[j])
            temp[k++] = data[i++];
        else
            temp[k++] = secondHalf[j++];
    }
    for(i=0;i<(n1+n2);i++)
        data[i] = temp[i];
    delete[] temp;
}

void MergeSort(int Arr[], int left, int right){
    if(left<right){
        int middle = left +(right-left)/2;
        MergeSort(Arr,left,middle);
        MergeSort(Arr,middle+1,right);
        
        cout << "Array Before Merge: Left:" << left << " Middle: " << middle << " Right: " << right << endl;
        printArray(Arr);
        merge(Arr+left, middle-left+1, right-middle);
        cout << "After Merge: ";
        printArray(Arr);
    }
}

void Merger(int arr1[], int arr2[], int n1, int n2){
    int i=0, j=0, k=0;
    int total = n1+n2;
    int* temp = new int[total];

    while(i+j < total){
        if(i==n1){
            temp[k++] = arr2[j++];
        }
        else if(j==n2){
            temp[k++] = arr1[i++];
        }
        else if(arr1[i]<arr2[j]){
            temp[k++] = arr1[i++];
        }
        else{
            temp[k++] = arr2[j++];
        }
    }
    for(int h=0; h<(n1+n2); h++){
        cout << *(temp+h) << " ";
    }

    delete[] temp;
}

int main() {
    int values[12] = {4,7,1,5,3,2,0,8,6,9,11,10};
    //int values[array_num] = {4,7,1,5,3};
    int arr1[4] = {2,6,8,10};
    int arr2[6] = {2,3,6,9,11,13};

    Merger(arr1, arr2, 4, 6);




//     MergeSort(values, 0, array_num-1);

//     for(int i=0;i<array_num;i++){
//         cout << values[i] << " ";
//     }
//     cout << endl;
}
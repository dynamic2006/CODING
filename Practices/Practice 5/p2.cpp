#include <iostream>
using namespace std;

int sum(int* begin, int* end){
    cout << "Use int sum()" << endl;
    int total = *begin++;
    while(begin != end){
        total += *begin;
        begin++;
    }
    return total;
}

template <typename T>
T sum(T* begin, T* end){
    cout << "Use T sum()" << endl;
    T total = *begin++;
    while(begin != end){
        total += *begin;
        begin++;
    }
    return total;
}

int main() {
    double arr[] = {0.5 , 1.5 , 2.5 , 3.5};
    int values[] = {1 , 2 , 3 , 4};
    cout << "Sum of arr[] is " << sum(&arr[0], &arr[4]) << endl;
    cout << "Sum of values[] is " << sum(values, values+4) << endl;
}
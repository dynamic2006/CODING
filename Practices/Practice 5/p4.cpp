#include <iostream>
using namespace std;

template <typename T>
struct pairs {T min_value, max_value;};

template <typename T>
pairs<T> min_max(T* begin, T* end){
    pairs<T> p;
    p.min_value = p.max_value = *begin++;
    while(begin != end){
        if(*begin > p.max_value){
            p.max_value = *begin;
        }
        if(*begin < p.min_value){
            p.min_value = *begin;
        }
        begin++;
    }
    return p;
}

int main() {
    double arr[] = {5.5 , 4.5 , 3.5 , 2.5 , 1.5};
    int values[] = {1 , 2 , 3 , 4 , -1 , 5};

    pairs<double> dp;
    pairs<int> ip;

    dp = min_max(arr, arr+5);
    ip = min_max(values, values+6);

    cout << "min of arr[] is: " << dp.min_value << ", max of arr[] is: " << dp.max_value << endl;
    cout << "min of values[] is: " << ip.min_value << ", max of values[] is: " << ip.max_value << endl;

}
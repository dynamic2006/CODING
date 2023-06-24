#include <iostream>
using namespace std;

int Fib(int N)
{
    if(N == 0 || N == 1)
        return 1;
    return Fib(N-1) + Fib(N-2);
}

int Fib2(int N)
{
    int* arr = new int[N+1];

    arr[0] = 1;
    arr[1] = 1;
    for(int i=2;i<=N;i++)
        arr[i] = arr[i-1] + arr[i-2];
    int value = arr[N];

    delete[] arr;
    return value;
}
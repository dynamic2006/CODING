#include <iostream>
using namespace std;

bool isPrimeNumber2(int number){
    for(int i=2; i*i < number; i++){
        if(number % i == 0){
            return false;
        }
    }
    return true;
}

bool isPrimeNumber(int number, int i=2){
    if(i*i > number){
        return true;
    }
    if(!(number % i)){
        return false;
    }
    isPrimeNumber(number, i+1);
}

int main(){
    int value;
    cin >> value;
    if(isPrimeNumber(value) && isPrimeNumber2(value)){
        cout << value << " is a prime number." << endl;
    }
    else{
        cout << value << " is not a prime number." << endl;
    }
}
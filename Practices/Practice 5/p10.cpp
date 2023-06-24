#include <iostream>
using namespace std;

template <typename T>
class myVector {
    public:
        myVector(){
            capacity = 1;
            length = 0;
            arr = new T[capacity];
        }
        ~myVector(){
            if(arr != nullptr)
                delete [] arr;
        }

        T at(int idx){
            return arr[idx];
        }
        void push_back(const T& value);
        void clear(){
            if (arr != nullptr)
                delete[] arr;
            arr = nullptr;
        }
    
    private:
        T* arr;
        int length;
        int capacity;
};

template <typename T>
void myVector<T>::push_back(const T& value){
    if(length == capacity){
        capacity*=2;
        T* new_storage = new T[capacity];
        for(int i=0; i<length; i++){
            new_storage[i] = arr[i];
        }

        T* temp = arr;
        arr = new_storage;
        delete[] temp;
    }
    arr[length++] = value;
}

int main() {
    myVector<int> mv;

    for(int i=0;i<5;i++){
        mv.push_back(i);
    }

    for(int i=0;i<5;i++){
        cout << mv.at(i) << " ";
    }
    cout << endl;
}
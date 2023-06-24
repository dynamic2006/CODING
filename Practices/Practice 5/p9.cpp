#include <iostream>
using namespace std;

template <typename T>
class myQueue{
    public:
        myQueue(int cap=5) : capacity(cap), head(-1), tail(-1) {
            if(cap <= 0){
                cout << "Error: Capacity <= 0!" << endl;
                exit(1);
            }
            arr = new T[capacity];
        }
        ~myQueue(){delete[] arr;}

        inline bool isFull() const{return((tail+1) % capacity == head);}
        inline bool empty() const{return (head == -1);}

        void push(const T& value);
        void pop();
        T front() const;

    private:
    T* arr;
    int head, tail;
    int capacity;
};

template <typename T>
T myQueue<T>::front() const {
    if(empty()){
        cout << "Error: Front() failed because Queue is empty!!" << endl;
        exit(1);
    }
    return arr[head];
}

template <typename T>
void myQueue<T>::push(const T& value) {
    if (isFull()){
        cout << "Error: Push() failed because Queue is Full!" << endl;
        return;
    }
    tail = (tail+1) % capacity;
    arr[tail] = value;
    if(head == -1){
        head = tail;
    }
}

template <typename T>
void myQueue<T>::pop() {
    if(empty()){
        cout << "Error: Pop() failed because Queue is empty!!" << endl;
        return;
    }
    if(head == tail){head = tail = -1;}
    else{head = (head+1) % capacity;}
}

int main() {
    myQueue<double> mq;

    for(int i=0;i<6;i++){
        mq.push(i+0.5);
    }

    for(int i=0;i<5;i++){
        cout << mq.front() << endl;
        mq.pop();
    }
}
#include <iostream>
using namespace std;

class myQueue{
    public:
        myQueue(int cap=5) : capacity(cap), head(-1), tail(-1) {
            if(cap <= 0){
                cout << "Error: Capacity <= 0!" << endl;
                exit(1);
            }
            arr = new int[capacity];
        }
        ~myQueue(){delete[] arr;}

        inline bool isFull() const{return((tail+1) % capacity == head);}
        inline bool empty() const{return (head == -1);}

        void push(const int& value);
        void pop();
        int front() const;

    private:
    int* arr;
    int head, tail;
    int capacity;
};

int myQueue::front() const {
    if(empty()){
        cout << "Error: Front() failed because Queue is empty!!" << endl;
        exit(1);
    }
    return arr[head];
}

void myQueue::push(const int& value) {
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

void myQueue::pop() {
    if(empty()){
        cout << "Error: Pop() failed because Queue is empty!!" << endl;
        return;
    }
    if(head == tail){head = tail = -1;}
    else{head = (head+1) % capacity;}
}

int main() {
    myQueue mq;

    for(int i=0;i<6;i++){
        mq.push(i);
    }

    for(int i=0;i<5;i++){
        cout << mq.front() << endl;
        mq.pop();
    }
}
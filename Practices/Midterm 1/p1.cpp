#include <iostream>
#include <cassert>
using namespace std;

class LinkedList{
    public:
        LinkedList(): head(nullptr){}
        ~LinkedList();
        void addToList(int value); // Append to the end of the linked list
        void reverse(); // Reverse the linked list
        void output();
        bool findNthFromLast1(int N, int& value);
        bool findNthFromLast2(int N, int& value);
    private:
        struct Node{
            int num;
            Node* next;
            Node():next(nullptr){}
        };
        Node* head;
};

void LinkedList::output(){
    Node* ptr = head;
    cout << "The elements in the list are: ";
    while(ptr != nullptr){
        cout << ptr->num << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

LinkedList::~LinkedList(){
    Node* ptr = head;
    Node* toBeDeleted = nullptr;
    while(ptr != nullptr){
        toBeDeleted = ptr;
        ptr = ptr->next;
        delete toBeDeleted;
    }
    cout << "Deletion complete" << endl;
}

void LinkedList::addToList(int value){
    Node* current = new Node(); current->num = value;
    if (head == nullptr){
        head = current;
        return;
    }

    Node* ptr = head;
    while(ptr->next != nullptr){
        ptr = ptr->next;
    }
    ptr->next = current;

    return;

}

void LinkedList::reverse() {
    Node *nextNode = nullptr, *prevNode = nullptr, *current = head;
    while(current != nullptr){
        nextNode = current->next;
        current->next = prevNode;
        prevNode = current;
        current = nextNode;
    }
    head = prevNode;
}

bool LinkedList::findNthFromLast1(int N, int& value){
    if (N<=0){
        return false;
    }

    reverse();
    Node* ptr = head;
    for (int i=1; ptr != nullptr, i<N; i++){
        ptr = ptr->next;
    }
    reverse();

    if(ptr == nullptr){
        return false;
    }
    else{
        value = ptr->num;
        return true;
    }
}

bool LinkedList::findNthFromLast2(int N, int& value){
    if (N<=0){
        return false;
    }

    Node* ptr = head;

    // first scan thru
    int total = 0;
    while(ptr != nullptr){
        total++;
        ptr = ptr->next;
    }

    if(total<N){
        return false;
    }

    //second scan to find correct Node
    ptr = head;
    for (int i=0; ptr != nullptr, i<(total-N); i++){
        ptr = ptr->next;
    }
    value = ptr->num;
    return true;

}

int main(){
    int value = 999;
    LinkedList list;

    for(int i=1;i<=10;i++){
        list.addToList(i);
    }

    // list.output();
    // list.reverse();
    // list.output();

    assert(!list.findNthFromLast2(0,value) && value == 999);
    assert(!list.findNthFromLast1(11,value) && value == 999);
    assert(list.findNthFromLast2(1,value) && value == 10);
    assert(list.findNthFromLast1(2,value) && value == 9);
    assert(list.findNthFromLast2(10,value) && value == 1);

    // LinkedList list;
    // for(int i=1; i<10; i++){
    //     list.addToList(i);
    // }

    
}
#include <iostream>
using namespace std;

class LinkedList{
    public:
        LinkedList(): head(nullptr){}
        ~LinkedList();
        void append(int value);
        void print() const;
        void printReverse() const;
        void reverse();
        int sum() const;
    
    private:
        struct Node
        {
            int num;
            Node* next;
        };
        Node* head;

        void printReverseHelper(const Node* p) const;
        Node* reverseHelper(Node* current, Node* previous);
        int sumHelper(const Node* p) const;
        void removeNodes(Node* p);
        
};

void LinkedList::append(int value){
    Node* current = new Node;
    current->num = value;
    current->next = nullptr;
    if(head == nullptr){
        head = current;
    }
    else{
        Node* ptr = head;
        while(ptr->next != nullptr){
            ptr = ptr->next;
        }
        ptr->next = current;
    }
}

void LinkedList::print() const{
    for(const Node* ptr = head; ptr!=nullptr; ptr = ptr->next){
        cout << ptr->num << " ";
    }
    cout << endl;
}

void LinkedList::printReverse() const{
    printReverseHelper(head);
    cout << endl;
}

void LinkedList::printReverseHelper(const Node* p) const{
    if(p == nullptr)
        return;
    printReverseHelper(p->next);
    cout << p->num << " ";
}

void LinkedList::reverse(){
    head = reverseHelper(head,nullptr);
}

LinkedList::Node* LinkedList::reverseHelper(Node* current, Node* previous){
    if(current == nullptr){
        return previous;
    }
    Node* last_node = reverseHelper(current->next, current);
    current->next = previous;
    return last_node;
}

int LinkedList::sum() const{
    return sumHelper(head);
}

int LinkedList::sumHelper(const Node* p) const{
    if(p == nullptr){
        return 0;
    }
    int sum = p->num;
    sum += sumHelper(p->next);
    return sum;
}

LinkedList::~LinkedList(){
    removeNodes(head);
}

void LinkedList::removeNodes(Node* p){
    if(p == nullptr)
        return;
    removeNodes(p->next);
    delete p;
}

int main(){
    LinkedList list;
    cout << list.sum() << endl;
    int values[4] = {30,10,40,20};

    for(int i=0; i<4; i++){
        list.append(values[i]);
    }
    list.print();
    cout << list.sum() << endl;

    list.printReverse();
    list.print();

    list.reverse();
    list.print();
}
#include <iostream>
using namespace std;

class Stack {
    public:
        Stack(){
            head = nullptr;
        }
        Stack(const Stack& s);

        ~Stack();

        void push(int n);
        void pop();
        int top() const;
        bool empty() const;
        void printContent();
        Stack& operator=(const Stack& s);
    
    private:
        struct Node{
            Node* next;
            int value;
            Node(int v, Node* n):value(v), next(n) {} // There is no default constructor!
        };
        Node* head;
};

Stack::~Stack() { //deletes starting from head
    while(head != nullptr){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
void Stack::printContent() { //deletes starting from head
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->value << endl;
        temp = temp->next;
    }
}


void Stack::push(int n) { //stack, so insert items at start
    head = new Node(n, head); //you want to point the new head's next to the address of the old head
}

int Stack::top() const {
    if(empty()){
        cout << "Stack is empty!!" << endl;
        exit(1);
    }
    else{
        return head->value;
    }
}

bool Stack::empty() const {
    if (head == nullptr){
        return true;
    }
    else{
        return false;
    }
}

void Stack::pop() {
    if(empty()){
        cout << "Stack is empty!!" << endl;
        return;
    }
    else{
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

Stack::Stack(const Stack& s) { //ask dad to check
    if(s.head == nullptr){
        head = nullptr;
        return;
    }
    this->head = new Node(s.head->value, nullptr);

    Node* prev = this->head;
    Node* ptr = s.head->next;

    while(ptr != nullptr){
        Node* current = new Node(ptr->value,nullptr);
        prev->next = current;
        prev = prev->next; 
        ptr = ptr->next;
    }
    
}

Stack& Stack::operator=(const Stack& s) { //check with dad
    if(s.head == nullptr){
        head = nullptr;
        return* this;
    }
    this->head = new Node(s.head->value, nullptr);

    Node* prev = this->head;
    Node* ptr = s.head->next;

    while(ptr != nullptr){
        Node* current = new Node(ptr->value,nullptr);
        prev->next = current;
        prev = prev->next; 
        ptr = ptr->next;
    }
    return *this;
}

int main() {
    Stack A;
    for(int i=0;i<5;i++){
        A.push(i);
    }
    Stack B(A);
    A.printContent();
    cout << "**************" <<endl ;
    B.printContent();
    Stack C;
    B = A;
    cout << "**************" <<endl ;
    B.printContent();
    cout << "**************" <<endl ;
    while(!C.empty()){
        cout << C.top() << endl;
        C.pop();
    }
    cout << "*************" << endl;
    C.printContent();
}
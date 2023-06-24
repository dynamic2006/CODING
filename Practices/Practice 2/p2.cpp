#include <iostream>
#include <cassert>

using namespace std;

class LinkedList{
    public:
        LinkedList(): head(nullptr){}
        ~LinkedList(){
            Node* temp;
            while (head != nullptr){
                temp = head;
                head = head->next;
                delete temp;
            }
        }

        void append(int value){ // Append to the end of linked list
            Node* current = new Node (value, nullptr);
            if (head == nullptr){
                head = current;
            }
            else{
                Node* ptr = head;
                while (ptr->next != nullptr){
                    ptr = ptr->next;
                }
                ptr->next = current;
            }
        }
        
        int JosephusCircle(int N);

        int JosephusCircle2(int N);

    private:
        struct Node{
            int num;
            Node* next;
            Node(int n, Node* ptr): num(n),next(ptr){}
        };

        Node* head;
};

int LinkedList::JosephusCircle(int N) {
    
    Node* ptr = head;
    Node* prev = nullptr;
    int count;
    while(head->next != nullptr){
        for(count=1; count<N; count++){
            prev = ptr;
            ptr = ptr->next;
        }
        if(ptr == nullptr){
            ptr = head;
        }

        Node* temp = ptr;

        if(head == ptr){
            head = ptr->next;
        }
        else{
            prev->next = ptr->next;
        }
        ptr = ptr->next;

        if(ptr == nullptr){
            ptr=head;
        }
        delete temp;
    }
    return head->num;
}

int LinkedList::JosephusCircle2(int N) {

    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    tail->next = head;
    
    Node* ptr = head;
    Node* prev = nullptr;

    int count = 1;

    while(ptr->next != ptr){
        prev = ptr;
        ptr = ptr->next;
        count++;
        if (count == N){
            prev->next = ptr->next;
            delete ptr;
            count = 1;
            ptr = prev->next; // need to reassign ptr
        }
        
    }
    head = ptr; head->next = nullptr; // head next points to a random thing, so set it to null
    return head->num;
}

int main() {

    int i, N;

    for(N=1; N<=7; N++){
        LinkedList circle;

        for(i=1;i<=N;i++){
            circle.append(i); // Append Number 1 thru N to the Linked List
        }

        cout << "Number " << circle.JosephusCircle2(2); // Every 2nd person is eaten

        cout << " is the last person standing." << endl;
    }
}
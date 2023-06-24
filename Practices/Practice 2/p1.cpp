#include <iostream>
using namespace std;

struct Node {
    Node(int c, int e): coef(c), exp(e), next(nullptr) {}
    int coef, exp;
    Node* next;
};

class poly{
    public:
        poly():head(nullptr) {}
        ~poly();
        void addNewTerm(int c, int e);
        void display();
    private:
    Node* head;
};

poly::~poly() {
    Node* ptr = head;
    while (ptr != nullptr){
        Node* temp = ptr->next;
        delete ptr;
        ptr = temp;
    }
    head = nullptr;
}

void poly::addNewTerm(int c, int e) {
    Node* current = new Node(c,e);
    if (head == nullptr){
        head = current; // so at some point, head gets attribute next
    }
    else{
        Node* ptr = head;
        while (ptr->next != nullptr)
            ptr = ptr-> next;
        ptr->next = current;
    }
}

void poly::display() {
    if (head == nullptr){
        cout << "No polynomial terms were entered!!" << endl;
        return;
    }

    cout << head->coef << "*X^" << head->exp;

    Node* ptr = head->next;

    while(ptr != nullptr){
        if(ptr->coef > 0)
            cout << "+";
        
        cout << ptr->coef << "*X^" << ptr->exp;

        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    int choice,c,e;
    poly p;

    do{
        cout << "Please select an option:" << endl;
        cout << "1) Add a new polynomial term." << endl;
        cout << "2) Display current polynomials." << endl;
        cout << "3) Quit." << endl;

        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Please enter a coefficient followed by an exponent:";
                cin >> c >> e; // 3 2 means 3x^2
                p.addNewTerm(c,e);
                break;
            case 2:
                p.display();
                break;
        }
    }while(choice != 3);
}
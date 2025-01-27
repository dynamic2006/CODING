#include "Sequence.h"
#include <iostream>
using namespace std;

Sequence::Sequence()
{
    setup();
}

Sequence::Sequence(Sequence &other)
{
    setup();
    for(int i=0; i<other.size(); i++){
        ItemType v; other.get(i, v);
        insert(i, v);
    }
}

Sequence::~Sequence()
{
    while(head->next != tail){
        deleteNode(head->next);
    }
    delete head;
    delete tail;
}

Sequence& Sequence::operator=(const Sequence &other)
{
    if(this == &other) return *this;

    while(head->next != tail) deleteNode(head->next);

    for(int i=0; i<other.size(); i++){
        ItemType v; other.get(i, v);
        insert(i, v);
    }
    return *this;
    
}

//Public functions

bool Sequence::empty() const
{
    return !n;
}

int Sequence::size() const
{
    return n;
}

int Sequence::insert(int pos, const ItemType &value)
{
    if(pos < 0 || pos > size()) return -1;
    Node* temp = getNodeAt(pos);
    addNode(temp->prev, temp, value);
    return pos;
}

//changed this, make sure it works properly
int Sequence::insert(const ItemType &value)
{
    int pos = 0;
    Node* temp = head->next;
    while(temp != tail && value > temp->val){
        pos++; temp = temp->next;
    }
    addNode(temp->prev, temp, value);
    return pos;
}

bool Sequence::erase(int pos)
{
    if(pos < 0 || pos > size()) return false;
    Node* temp = getNodeAt(pos);
    deleteNode(temp);
    return true;
}

int Sequence::remove(const ItemType &value)
{
    int deletions = 0;
    Node* temp = head->next;
    while(temp != tail){
        if(temp->val == value){
            temp = temp->next;
            deleteNode(temp->prev);
            deletions++;
        }
        else temp = temp->next;
    }
    return deletions;
}

bool Sequence::get(int pos, ItemType &value) const
{
    if(0 <= pos && pos < size()){
        Node* temp = getNodeAt(pos);
        value = temp->val;
        return true;
    }
    return false;
}

bool Sequence::set(int pos, const ItemType &value)
{
    if(0 <= pos && pos < size()){
        Node* temp = getNodeAt(pos);
        temp->val = value;
        return true;
    }
    return false;
}

//check if ternary operator allowed
int Sequence::find(const ItemType &value) const
{
    int pos = 0;
    Node* temp = head->next;
    while(temp != tail && temp->val != value){
        pos++; temp = temp->next;
    }
    return pos == n ? -1 : pos;
}

//check this again
void Sequence::swap(Sequence &other)
{
    if(this == &other) return;

    Node* tempHead = this->head;
    this->head = other.head;
    other.head = tempHead;
    this->head->next->prev = this->head;
    other.head->next->prev = other.head;

    Node* tempTail = this->tail;
    this->tail = other.tail;
    other.tail = tempTail;
    this->tail->prev->next = this->tail;
    other.tail->prev->next = other.tail;

    int tn = this->n;
    this->n = other.n;
    other.n = tn;

}

//Private Functions

Sequence::Node* Sequence::getNodeAt(int pos) const
{
    //note this goes up to tail, so it may return tail
    if(pos < 0 || pos > n) return nullptr;
    Node* temp = head->next;
    for(int i=0; i<pos; i++) temp = temp->next;
    return temp;
}

// CAUTION!!! CHECK THAT NODE*& a syntax is correct -- we want to update the node
// so we pass the node pointer by reference -- there should be a hw that discussed this
void Sequence::addNode(Node*& a, Node*& b, const ItemType &value)
{
    Node* cur = new Node();
    cur->val = value;
    cur->prev = a;
    cur->next = b;

    a->next = cur;
    b->prev = cur;
    n++;
}

void Sequence::deleteNode(Node* cur)
{
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur;
    n--;
}

void Sequence::setup()
{
    head = new Node();
    tail = new Node();
    head->next = tail;
    head->prev = nullptr;
    tail->next = nullptr;
    tail->prev = head;
    //Note: head and tail values not initialized -- look into this
    head->val = 2;
    tail->val = 1;
    n = 0;
}

//Sequence Algorithms

int subsequence(const Sequence &seq1, const Sequence &seq2)
{
    for(int i=0; i<seq1.size(); i++){
        int ti = i;
        bool found = true;
        for(int j=0; j<seq2.size(); j++){
            ItemType v1, v2;
            seq1.get(ti, v1);
            seq2.get(j, v2);
            if(ti >= seq1.size() || v1 != v2){
                found = false;
                break;
            }
            ti++;
        }
        if(found) return i;
    }
    return -1;

}

void zipper(const Sequence &seq1, const Sequence &seq2, Sequence &result)
{
    int ptr1 = 0, ptr2 = 0;
    int curPos = 0;
    ItemType curValue;
    while(ptr1 < seq1.size() || ptr2 < seq2.size()){
        if(ptr1 < seq1.size()){
            seq1.get(ptr1++, curValue);
            result.insert(curPos++, curValue);
        }
        if(ptr2 < seq2.size()){
            seq2.get(ptr2++, curValue);
            result.insert(curPos++, curValue);
        }   
    }
}

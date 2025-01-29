#include "Sequence.h"

//constructor
Sequence::Sequence()
{
    setup();
}

//copy constructor
Sequence::Sequence(const Sequence &other)
{
    setup(); //setup like normal
    //for each node in other, make a copy for this one
    for(int i=0; i<other.size(); i++){
        ItemType v; other.get(i, v);
        insert(i, v);
    }
}

//destructor
Sequence::~Sequence()
{
    //when head->next is tail
    //only head and tail nodes lef
    while(head->next != tail){
        deleteNode(head->next); //delete this node
    }
    //now just clean up head and tail
    delete head;
    delete tail;
}

//assignment operator
Sequence& Sequence::operator=(const Sequence &other)
{
    if(this == &other) return *this; //to prevent undefined behavior

    while(head->next != tail) deleteNode(head->next); //clean up current seq

    //copy over each element in other seq to this one
    for(int i=0; i<other.size(); i++){
        ItemType v; other.get(i, v);
        insert(i, v);
    }
    return *this;
}

//Public Member Functions

//return is this sequence is empty
bool Sequence::empty() const
{
    return !n; //if n=0, then !n is true
}

//returns size of this sequence
int Sequence::size() const
{
    return n;
}

//inserts a node at given position pos with given value
int Sequence::insert(int pos, const ItemType &value)
{
    if(pos < 0 || pos > size()) return -1; //invalid position
    Node* temp = getNodeAt(pos); //get pointer to target pos
    addNode(temp->prev, temp, value); //add node at this pos
    return pos;
}

//inserts a node at first position pos such that value <= the current value at that pos
//returns the position that the node was inserted at (end if value > all other node values)
int Sequence::insert(const ItemType &value)
{
    int pos = 0;
    Node* temp = head->next;
    //while not found a node such that value <= node's value
    while(temp != tail && value > temp->val){
        pos++; temp = temp->next; //increment
    }
    addNode(temp->prev, temp, value); //add node at target position
    return pos;
}

//erases the item at pos from the sequence
bool Sequence::erase(int pos)
{
    if(pos < 0 || pos >= size()) return false; //invalid pos
    //for valid pos, retrieve and delete node at pos
    Node* temp = getNodeAt(pos);
    deleteNode(temp);
    return true;
}

//removes all occurences of value from the sequence
int Sequence::remove(const ItemType &value)
{
    int deletions = 0; //tracks number of deletions
    Node* temp = head->next;
    //iterate over linked list
    while(temp != tail){
        if(temp->val == value){
            //if target value found
            //increment temp->next to prevent undefined behavior
            //delete previous node and increment deletions
            temp = temp->next;
            deleteNode(temp->prev);
            deletions++;
        }
        else temp = temp->next; //if this isn't equal to value
    }
    return deletions; //return number of deletions
}

//gets the value at pos and stores it in given value
bool Sequence::get(int pos, ItemType &value) const
{
    if(0 <= pos && pos < size()){
        Node* temp = getNodeAt(pos);
        value = temp->val;
        return true;
    }
    return false; //if not valid pos
}

//sets the value at pos to be given value
bool Sequence::set(int pos, const ItemType &value)
{
    if(0 <= pos && pos < size()){
        Node* temp = getNodeAt(pos);
        temp->val = value;
        return true;
    }
    return false; //if not valid pos
}

//finds first occurence of value in the sequence
//returns the position pos of first occurence
//or -1 if value isn't in the sequence
int Sequence::find(const ItemType &value) const
{
    int pos = 0;
    Node* temp = head->next;
    //iterate until you find a node with value equal to target value
    while(temp != tail && temp->val != value){
        pos++; temp = temp->next;
    }
    return pos == n ? -1 : pos; //returns -1 if value not found, else returns pos
}

//swaps two sequences
void Sequence::swap(Sequence &other)
{
    if(this == &other) return; //to prevent undefined behavior

    //swap heads
    Node* tempHead = this->head;
    this->head = other.head;
    other.head = tempHead;
    //correct the prev pointers for the nodes after heads
    this->head->next->prev = this->head;
    other.head->next->prev = other.head;

    //swap tails
    Node* tempTail = this->tail;
    this->tail = other.tail;
    other.tail = tempTail;
    //correct the next pointers for the nodes before tails
    this->tail->prev->next = this->tail;
    other.tail->prev->next = other.tail;

    //swap sizes n
    int tn = this->n;
    this->n = other.n;
    other.n = tn;

}

//Private Functions

//returns a pointer to the node at position pos
Sequence::Node* Sequence::getNodeAt(int pos) const
{
    //note this goes up to tail, so it may return tail
    if(pos < 0 || pos > n) return nullptr; //invalid pos
    Node* temp = head->next;
    //iterate until you get to the node at pos
    for(int i=0; i<pos; i++) temp = temp->next;
    return temp; //return a pointer to this node
}

//helper function to add node after node a and before node b in sequence
void Sequence::addNode(Node* a, Node* b, const ItemType &value)
{
    //create new node and set its data
    Node* cur = new Node();
    cur->val = value;
    cur->prev = a;
    cur->next = b;

    //correct a's next pointer and b's prev pointer
    //they should both now point to cur instead
    a->next = cur;
    b->prev = cur;
    n++; //increase size
}

//helper function to delete node given a pointer cur to the node
void Sequence::deleteNode(Node* cur)
{
    //correct the next and prev pointers for the nodes adjacent to cur
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur; //delete data pointed to by cur
    n--; //decrease size
}

//setup a default Sequence
void Sequence::setup()
{
    //initalize dummy node pointers head and tail
    head = new Node();
    tail = new Node();
    head->next = tail;
    head->prev = nullptr; //nothing before head
    tail->next = nullptr; //nothing after tail
    tail->prev = head;
    //don't set head and tail values
    //they will never be accessed
    n = 0; //list is empty
}

//Sequence Algorithms

//returns starting pos of first occurence of seq2 as a subsequence of seq1
int subsequence(const Sequence &seq1, const Sequence &seq2)
{
    if(seq2.empty()) return -1; //seq2 must not be empty
    //iterate through each possible starting pos in seq1
    for(int i=0; i<seq1.size(); i++){
        int ti = i; //branch off with ti to test this as a subsequence
        bool found = true; //assume a subsequence is possible to be found starting here
        //iterate through each j in seq2 to check is subsequence exists
        for(int j=0; j<seq2.size(); j++){
            ItemType v1, v2;
            seq1.get(ti, v1);
            seq2.get(j, v2);
            //if ti is out of bounds or values mismatch
            //then subsequence not possible to be found here
            //try next starting pos
            if(ti >= seq1.size() || v1 != v2){
                found = false;
                break;
            }
            ti++; //check next corresponding values of ti and j
        }
        if(found) return i; //if found a subsequence, return the pos i
    }
    return -1; //if never found a subsequence, return -1

}

//stores all values form seq1 and seq2 in result, in an alternating manner starting with seq1
void zipper(const Sequence &seq1, const Sequence &seq2, Sequence &result)
{
    Sequence tempRes; //to handle aliasing

    int ptr1 = 0, ptr2 = 0; //to track positions in seq1 and seq2
    ItemType curValue; //for get functions
    //while items are left in either reference seq1 or seq2
    while(ptr1 < seq1.size() || ptr2 < seq2.size()){
        //if not reached end of seq1, insert next element from it into tempRes
        if(ptr1 < seq1.size()){
            seq1.get(ptr1++, curValue);
            tempRes.insert(tempRes.size(), curValue);
        }
        //if not reached end of seq2, insert next element form it into tempRes
        if(ptr2 < seq2.size()){
            seq2.get(ptr2++, curValue);
            tempRes.insert(tempRes.size(), curValue);
        }   
    }
    result = tempRes; //set result to tempRes
}

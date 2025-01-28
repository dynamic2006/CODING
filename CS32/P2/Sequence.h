#ifndef SEQUENCE_INCLUDED
#define SEQUENCE_INCLUDED

#include <string>
using ItemType = std::string;

class Sequence
{
    public:
        Sequence();
        Sequence(const Sequence& other);
        ~Sequence();
        Sequence& operator=(const Sequence& other);

        bool empty() const;
        int size() const;
        int insert(int pos, const ItemType& value);
        int insert(const ItemType& value);
        bool erase(int pos);
        int remove(const ItemType& value);
        bool get(int pos, ItemType& value) const;
        bool set(int pos, const ItemType& value);
        int find(const ItemType& value) const;
        void swap(Sequence& other);
    
    private:
        struct Node{
            ItemType val;
            Node* prev;
            Node* next;
        };
        Node* head;
        Node* tail;
        int n;

        Node* getNodeAt(int pos) const;
        void addNode(Node* a, Node* b, const ItemType &value);
        void deleteNode(Node* cur);
        void setup();
};

int subsequence(const Sequence& seq1, const Sequence& seq2);

void zipper(const Sequence& seq1, const Sequence& seq2, Sequence& result);

#endif //SEQUENCE_INCLUDED
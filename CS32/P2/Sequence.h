#ifndef SEQUENCE_INCLUDED
#define SEQUENCE_INCLUDED

using ItemType = int;

class Sequence
{
    public:
        Sequence();
        Sequence(Sequence& other);
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
        void addNode(Node* &a, Node* &b, const ItemType &value);
        void deleteNode(Node*& cur);
        void setup();
};

#endif //SEQUENCE_INCLUDED
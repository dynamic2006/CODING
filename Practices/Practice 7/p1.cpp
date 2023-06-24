#include <iostream>
#include <queue>
using namespace std;

struct Node{
    Node(const int& myVal){
        value = myVal;
        left = right = nullptr;
    }
    int value;
    Node *left, *right;
};

class BinarySearchTree{
    public:
        BinarySearchTree() {m_root = nullptr;}
        ~BinarySearchTree() {FreeTree(m_root);}
        Node* getRoot() {return m_root;}

        void insert(const int value);
        void preorder(Node* ptr);
        void inorder(Node* ptr);
        void postorder(Node* ptr);
        void levelorder();
        void juju_count(int value);
        int juju_total(Node* ptr);
        int GetMin(Node* pRoot);
        int GetMax(Node* pRoot);
        bool Search(int V, Node* ptr);

    private:
        Node* m_root;
        void FreeTree(Node* cur);
};

void BinarySearchTree::FreeTree(Node* cur){
    if(cur == nullptr)
        return;
    FreeTree(cur->left);
    FreeTree(cur->right);
    delete cur;
}

void BinarySearchTree::insert(const int value){
    if(m_root == nullptr){
        m_root = new Node(value);
        return;
    }
    Node* cur = m_root;
    for(;;){
        if(value == cur->value)
            return;
        if(value < cur->value){
            if(cur->left != nullptr)
                cur = cur->left;
            else{
                cur->left = new Node(value);
                return;
            }
        }
        else if(value > cur->value){
            if(cur->right != nullptr)
                cur = cur->right;
            else{
                cur->right = new Node(value);
                return;
            }
        }
    }
}

void BinarySearchTree::preorder(Node* ptr){
    if(ptr == nullptr)
        return;
    cout << ptr->value << " ";
    preorder(ptr->left);
    preorder(ptr->right);
}

void BinarySearchTree::inorder(Node* ptr){
    if(ptr == nullptr)
        return;
    inorder(ptr->left);
    cout << ptr->value << " ";
    inorder(ptr->right);
}

void BinarySearchTree::postorder(Node* ptr){
    if(ptr == nullptr)
        return;
    postorder(ptr->left);
    postorder(ptr->right);
    cout << ptr->value << " ";
}

bool BinarySearchTree::Search(int V, Node* ptr){
    if(ptr == nullptr)
        return false;
    if(V == ptr->value)
        return true;
    else if(V < ptr->value)
        return Search(V, ptr->left);
    else
        return Search(V, ptr->right);
}

void BinarySearchTree::levelorder(){
    if(m_root == nullptr) return;
    queue<Node*> q;
    q.push(m_root);
    while(!q.empty()){
        Node* visted_node = q.front();
        q.pop();
        if(visted_node->left != nullptr)
            q.push(visted_node->left);
        if(visted_node->right != nullptr)
            q.push(visted_node->right);
        
        cout << visted_node->value << " ";
    }
}

int BinarySearchTree::GetMin(Node* pRoot){
    if(pRoot == nullptr)
        return(-1);
    while (pRoot->left != nullptr)
    {
        pRoot = pRoot->left;
    }
    return pRoot->value;
    
}

int BinarySearchTree::GetMax(Node* pRoot){
    if(pRoot == nullptr)
        return(-1);
    while(pRoot->right != nullptr)
        pRoot = pRoot->right;
    return pRoot->value;
}

void BinarySearchTree::juju_count(int value){
    Node* ptr = m_root;

    //find node of value
    while(ptr->value != value){
        if(value < ptr->value)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    cout << "Nodes to Left: " << juju_total(ptr->left) << endl;
    cout << "Nodes to Right: " << juju_total(ptr->right) << endl;
}

int BinarySearchTree::juju_total(Node* ptr){

    if(ptr == nullptr)
        return 0;

    if(ptr->left == nullptr && ptr->right == nullptr)
        return 1;

    return (juju_total(ptr->left) + juju_total(ptr->right)+1);
    
}

int main(){
    BinarySearchTree BST;
    BST.insert(5); BST.insert(3); BST.insert(7);
    for(int i=0;i<=10;i+=2)
        BST.insert(i); //Insert 0 2 4 6 8 10
    

    BST.juju_count(-1);
    // BST.preorder(BST.getRoot());
    // cout << endl;
    // BST.inorder(BST.getRoot());
    // cout << endl;
    // BST.postorder(BST.getRoot());
    // cout << endl;
    // BST.levelorder(); cout << endl;
    // cout << endl;
    // cout << "Minimal value is: " << BST.GetMin(BST.getRoot()) << endl;
    // cout << "Maximal value is: " << BST.GetMax(BST.getRoot()) << endl;
}
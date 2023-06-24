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
        int GetMin(Node* pRoot);
        int GetMax(Node* pRoot);
        bool Search(int V, Node* ptr);

        // new functions for problem 7.3
        int size(Node* ptr);
        int height(Node* ptr);
        int numOfLeafNodes(Node* ptr);
        int numOfNonLeafNodes(Node* ptr);
        int sumOfAllNodes(Node* ptr);
        bool hasPathSum(Node* ptr, int sum);
        void reflectBinaryTree(Node* current);

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

int BinarySearchTree::size(Node* ptr){
    if(ptr == nullptr)
        return 0;
    return(size(ptr->left) + size(ptr->right) + 1);
}

int BinarySearchTree::sumOfAllNodes(Node* ptr){
    if(ptr == nullptr)
        return 0;
    return(sumOfAllNodes(ptr->left) + sumOfAllNodes(ptr->right) + ptr->value);
}

int BinarySearchTree::height(Node* ptr){
    if(ptr == nullptr)
        return 0;
    
    int left_height = height(ptr->left) + 1;
    int right_height = height(ptr->right) + 1;
    
    if(left_height > right_height)
        return left_height;
    else 
        return right_height;
}

int BinarySearchTree::numOfLeafNodes(Node* ptr){
    if(ptr == nullptr)
        return 0;
    if(ptr->right == nullptr && ptr->left == nullptr)
        return 1;
    
    return(numOfLeafNodes(ptr->left) + numOfLeafNodes(ptr->right));
}

int BinarySearchTree::numOfNonLeafNodes(Node* ptr){
    if(ptr == nullptr || ptr->right == nullptr && ptr->left == nullptr)
        return 0;
    return(numOfNonLeafNodes(ptr->left) + numOfNonLeafNodes(ptr->right) + 1);
}

bool BinarySearchTree::hasPathSum(Node* ptr, int sum){
    if(ptr == nullptr && sum == 0)
        return true;
    if(ptr == nullptr && sum != 0)
        return false;
    return(hasPathSum(ptr->left,sum-ptr->value) || hasPathSum(ptr->right, sum-ptr->value));
}

void BinarySearchTree::reflectBinaryTree(Node* current){
    Node* temp;
    if(current != nullptr){
        reflectBinaryTree(current->left);
        reflectBinaryTree(current->right);
        temp = current->left;
        current->left = current->right;
        current->right = temp;
    }
}

bool isReflection(Node* curr1, Node* curr2){

    if(curr1 == nullptr && curr2 == nullptr)
        return true;
    if(curr1 && curr2){
        return(isReflection(curr1->left, curr2->right) && isReflection(curr1->right, curr2->left) && curr1->value == curr2->value);
    }
    else
        return false;
}

int main(){

    BinarySearchTree BST_A, BST_B;
    
    BST_A.insert(5); BST_A.insert(3); BST_A.insert(7);
    for(int i=0;i<=10;i+=2)
        BST_A.insert(i); //Insert 0,2,4,6,8,10
    
    BST_B.insert(5); BST_B.insert(3); BST_B.insert(7);
    for(int i=0;i<=10;i+=2)
        BST_B.insert(i); //Insert 0,2,4,6,8,10
    BST_B.reflectBinaryTree(BST_B.getRoot());

    if(isReflection(BST_A.getRoot(), BST_B.getRoot()))
        cout << "BST_A is the reflection of BST_B!" << endl;
    else
        cout << "BST_A is NOT the reflection of BST_B!" << endl;

    

    //----------------------------------------------------------------
    // BinarySearchTree BST;

    // BST.insert(5); BST.insert(3); BST.insert(7);
    // for(int i=0;i<=10;i+=2)
    //     BST.insert(i); //Insert 0,2,4,6,8,10
    
    // BST.reflectBinaryTree(BST.getRoot());
    // BST.levelorder(); cout << endl;
    // BST.preorder(BST.getRoot()); cout << endl;

    //-----------------------------------------------------------------

    // cout << "Size of BST is: " << BST.size(BST.getRoot()) << endl;
    // cout << "Height of BST is: " << BST.height(BST.getRoot()) << endl;
    // cout << "There are " << BST.numOfLeafNodes(BST.getRoot()) << " leaf nodes" << endl;
    // cout << "There are " << BST.numOfNonLeafNodes(BST.getRoot()) << " non-leaf nodes" << endl;
    // cout << "Sum of all nodes is: " << BST.sumOfAllNodes(BST.getRoot()) << endl;

    // if(BST.hasPathSum(BST.getRoot(), 4))
    //     cout << "There is a path sum of 4" << endl;
    // if(BST.hasPathSum(BST.getRoot(), 18))
    //     cout << "There is a path sum of 18" << endl;

}
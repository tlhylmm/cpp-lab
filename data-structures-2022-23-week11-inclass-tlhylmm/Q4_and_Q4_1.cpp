#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Calculate height
int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

// New node creation
Node *newNode(int key)
{
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

// Rotate right
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    return x;
}

// Rotate left
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    return y;
}

// Get the balance factor of each node
int getBalanceFactor(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) -
           height(N->right);
}

// Insert a node
Node *insertNode(Node *node, int key)
{
    // Find the correct postion and insert the node
    if (node == NULL)
        return (newNode(key));
    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else
        return node;

    // Update the balance factor of each node and
    // balance the tree
    node->height = 1 + max(height(node->left),
                           height(node->right));
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1)
    {
        if (key < node->left->key)
        {
            return rightRotate(node);
        }
        else if (key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if (balanceFactor < -1)
    {
        if (key > node->right->key)
        {
            return leftRotate(node);
        }
        else if (key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
    return node;
}


// Print the tree
void printTree(Node *root, string indent, bool last)
{
    if (root != nullptr)
    {
        cout << indent;
        if (last)
        {
            cout << "R----";
            indent += "   ";
        }
        else
        {
            cout << "L----";
            indent += "|  ";
        }
        cout << root->key << endl;
        printTree(root->left, indent, false);
        printTree(root->right, indent, true);
    }
}

void preOrderTraverse(Node* root){
    //directly return if the tree is empty:
    if(root == NULL) return;

    //make recursive calls to children from left to right
    //current is first
    cout << root->key << " "; 
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

void inOrderTraverse(Node* root){
    //directly return if the tree is empty:
    if(root == NULL) return;

    //make recursive calls to children from left to right
    //current is in middle
    inOrderTraverse(root->left);
    cout << root->key << " "; 
    inOrderTraverse(root->right);
}

void postOrderTraverse(Node* root){
    //directly return if the tree is empty:
    if(root == NULL) return;

    //make recursive calls to children from left to right
    //current is last
    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    cout << root->key << " "; 
}

void menu(Node* root){
    int input;

    cout << "[1] Insert Element Into the Tree"
        << "\n[2] Show Balanced AVL Tree"
        << "\n[3] InOrder Traversal"
        << "\n[4] PreOrder Traversal"
        << "\n[5] PostOrder Traversal"
        << "\n[6] Exit"
        << "\nEnter Your Choice: ";
    cin >> input;

    switch(input){
        case 1:
            int key;
            cout << "Enter the Value: ";
            cin >> key;
            root = insertNode(root, key);
            break;
        case 2:
            printTree(root, "", true);
            break;
        case 3:
            inOrderTraverse(root);
            break;
        case 4:
            preOrderTraverse(root);
            break;
        case 5:
            postOrderTraverse(root);
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Wrong entry. Try again." << endl;
            system("pause");
            system("cls");
            menu(root);
    }
    cout << endl;
    menu(root);

}

int main()
{
    Node *root = NULL;
    menu(root);

    //for question 4.1 getBalanceFactor()
    //function is given above

    return 0;
}
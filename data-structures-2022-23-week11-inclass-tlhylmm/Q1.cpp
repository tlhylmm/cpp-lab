#include <iostream>
#include <queue>
using namespace std;

struct  BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    
    //constructor
    BinaryTreeNode(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

BinaryTreeNode* insertNode(BinaryTreeNode* root, int data)
{
    //if tree is empty, data will be root
    if (root == NULL) return new BinaryTreeNode(data);

    if (data > root->data)
        root->right = insertNode(root->right, data);
    else
        root->left = insertNode(root->left, data);
    return root;
}

void preOrderTraverse(BinaryTreeNode* root){
    //directly return if the tree is empty:
    if(root == NULL) return;

    //make recursive calls to children from left to right
    //current is first
    cout << root->data << " "; 
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

void inOrderTraverse(BinaryTreeNode* root){
    //directly return if the tree is empty:
    if(root == NULL) return;

    //make recursive calls to children from left to right
    //current is in middle
    inOrderTraverse(root->left);
    cout << root->data << " "; 
    inOrderTraverse(root->right);
}

void postOrderTraverse(BinaryTreeNode* root){
    //directly return if the tree is empty:
    if(root == NULL) return;

    //make recursive calls to children from left to right
    //current is last
    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    cout << root->data << " "; 
}

void menu(BinaryTreeNode* root){
    int input;

    cout << "1. Insert Elements"
        << "\n2. Preorder"
        << "\n3. Inorder"
        << "\n4. Postorder"
        << "\n5. Exit"
        << "\nEnter Your Choice: ";
    cin >> input;

    switch (input){
        case 1:
            int data;
            cout << "Enter the Value: ";
            cin >> data;
            root = insertNode(root, data);
            break;
    
        case 2:
            preOrderTraverse(root);
            break;
    
        case 3:
            inOrderTraverse(root);
            break;
    
        case 4:
            postOrderTraverse(root);
            break;
    
        case 5:
            exit(0);
    
        default:
            cout << "Wrong entry. Try again." << endl;
            system("pause");
            system("cls");
            menu(root);
    }
    cout << endl;
    menu(root);
}

int main(){
    BinaryTreeNode* root = NULL;
    menu(root);

    return 0;
}
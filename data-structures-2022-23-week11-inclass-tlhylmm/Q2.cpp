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

void inOrderTraverse(BinaryTreeNode* root){
    //directly return if the tree is empty:
    if(root == NULL) return;

    //make recursive calls to children from left to right
    //current is in middle
    inOrderTraverse(root->left);
    cout << root->data << " "; 
    inOrderTraverse(root->right);
}

int main(){
    BinaryTreeNode* root1 = NULL;
    root1 = insertNode(root1, 5);
    root1 = insertNode(root1, 3);
    root1 = insertNode(root1, 7);
    root1 = insertNode(root1, 2);
    root1 = insertNode(root1, 4);
    root1 = insertNode(root1, 6);
    root1 = insertNode(root1, 8);

    BinaryTreeNode* root2 = NULL;

    root2 = insertNode(root2, 5);
    root2 = insertNode(root2, 7);
    root2 = insertNode(root2, 8);
    root2 = insertNode(root2, 9);

    inOrderTraverse(root1);
    cout << endl;
    inOrderTraverse(root2);

    return 0;
}
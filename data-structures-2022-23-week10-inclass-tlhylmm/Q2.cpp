//Main idea is same as the previous question.
//Code blocks for placing left and right children
//needs to be switched.

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

//level order insertion function:
BinaryTreeNode* insertNode(BinaryTreeNode* root, int data){
    //if tree is empty, data will be root
    if(root == NULL){
        root = new BinaryTreeNode(data);
        return root;
    }

    //search level by level using queue until empty space
    //encountered:

    //create the queue and push the root
    queue<BinaryTreeNode*> q;
    q.push(root);

    // start placing the elements
    while(!q.empty()){
        //take the root as temp and remove from queue
        BinaryTreeNode* temp = q.front();
        q.pop();

        //start from the right to left, if there is a child,
        //push it to the queue; if there is no child (which
        //means it is equal to NULL), place the element to
        //that position:
        if(temp->right != NULL){
            q.push(temp->right);
        }
        else{
            temp->right = new BinaryTreeNode(data);
            return root;
        }

        if(temp->left != NULL){
            q.push(temp->left);
        }
        else{
            temp->left = new BinaryTreeNode(data);
            return root;
        }
    }
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


int main(){
    //create empty root node:
    BinaryTreeNode* root = NULL;

    //use insertNode() to fill the tree:
    root = insertNode(root, 4);
    root = insertNode(root, 6);
    root = insertNode(root, 12);
    root = insertNode(root, 45);
    root = insertNode(root, 7);
    root = insertNode(root, 1);
    cout << "preorder traversal option 1: ";
    preOrderTraverse(root);
    cout << "\nInorder traversal option 1: ";
    inOrderTraverse(root);
    cout << "\nPostorder traversal option 1: ";
    postOrderTraverse(root);
    return 0;
}
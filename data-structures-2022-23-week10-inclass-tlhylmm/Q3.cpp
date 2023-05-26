#include <iostream>
#include <queue>
using namespace std;

struct BSTNode{
    int data;
    BSTNode* left;
    BSTNode* right;

    //constructor
    BSTNode(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

BSTNode* insertNode(BSTNode* node, int data){
    //parameter named "node" will hold the node's pointers.
    //first, it will hold the root of the tree
    //then it will hold the addresses of children

    //if tree is empty, data will be root
    if(node == NULL){
        node = new BSTNode(data);
        return node;
    }

    //move to next nodes while comparing
    //if data is smaller than curret move to left
    if(data < node->data){
        node->left = insertNode(node->left, data); 
    }
    //if data is bigger than curret move to right
    else if(data > node->data){
        node->right = insertNode(node->right, data);
    }

    //return the node for recursion
    return node;
}


void preOrderTraverse(BSTNode* root){
    //directly return if the tree is empty:
    if(root == NULL) return;

    //make recursive calls to children from left to right
    //current is first
    cout << root->data << ", "; 
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

void breadthFirstSearch(BSTNode* root){
    if(root == NULL) return;

    queue<BSTNode*> q;
    q.push(root);

    while(!q.empty()){
        BSTNode* temp = q.front();
        q.pop();
        cout << temp->data << ", ";

        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }

}


int main(){
    //try for preOrder Traversal
    BSTNode* root1 = NULL;

    root1 = insertNode(root1, 10);
    root1 = insertNode(root1, 5);
    root1 = insertNode(root1, 1);
    root1 = insertNode(root1, 7);
    root1 = insertNode(root1, 40);
    root1 = insertNode(root1, 50);

    cout << "Preoder traversal result: ";
    preOrderTraverse(root1);

    //try for BFS Traversal
    BSTNode* root2 = NULL;

    root2 = insertNode(root2, 7);
    root2 = insertNode(root2, 4);
    root2 = insertNode(root2, 12);
    root2 = insertNode(root2, 3);
    root2 = insertNode(root2, 6);
    root2 = insertNode(root2, 8);
    root2 = insertNode(root2, 1);
    root2 = insertNode(root2, 5);
    root2 = insertNode(root2, 10);

    cout << "\nBFS traversal result ";
    breadthFirstSearch(root2);

    return 0;
}
#include <iostream>
using namespace std;
#define SIZE 3 //change path size here

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

// to find the starting node of the path
BinaryTreeNode* find(BinaryTreeNode* root, int key) {
	// since this is a binary tree, node's are ordered
	BinaryTreeNode* itr = root; //start from the root
	
	while(true){ // start searching
		// if the given key equals to current node's key  
		// return the current node:
		if(itr->data == key) return itr;
		// go to right if it's bigger:
		else if(key > itr->data) itr = itr->right;
		// go to left if it'S smaller: 
		else if(key < itr->data) itr = itr->left;
		// return NULL if key is not found:
		else return NULL;
	}
}

bool checkMainPath(BinaryTreeNode* start, int arr[SIZE]){
    BinaryTreeNode* itr = start;
    for(int i = 1; i < SIZE; i++){
        // if the next element is on the left, move to left
        if(itr->left->data == arr[i]){
            itr = itr->left;
        }
        // if the next element is on the right, move to right
        else if(itr->right->data == arr[i]){
            itr = itr->right;
        }
        // if the next element of array cannot be found
        // in any child, return false because it is not
        // a main path:
        else return false;
    }

    return true;
}


int main(){
    // the plan is to store the nodes that will be
    // visited in an array and in order. then use 
    // find() function to find the starting node in the tree.
    // after that, we need to check it's left and right children
    // while we are moving to next item in array

    /* e.g:
                        5
                      /  \
                     /    \
                    /      \
                   3        7
                  / \      / \
                 /   \    /   \
                2     4  6     8
    */ 
   // and let our path will be 5,3,4; which is a main path
   // 5-3-4 will be stored in an array:

    int arr[SIZE] = {5, 3, 4};

    //create tree:
    BinaryTreeNode* root = new BinaryTreeNode(5);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 2);
    root = insertNode(root, 4);
    root = insertNode(root, 6);
    root = insertNode(root, 8);

    // find the first node of the array and store it
    // in a pointer called "start":
    BinaryTreeNode* start = find(root, arr[0]);

    // then send the starting node and array to 
    // checkMainPath() function. function will check
    // if the array elements fit to the tree's order:

    if(checkMainPath(start, arr))
        cout << "It is a main path." << endl;
    else
        cout << "It is NOT a main path" << endl;
    return 0;
}
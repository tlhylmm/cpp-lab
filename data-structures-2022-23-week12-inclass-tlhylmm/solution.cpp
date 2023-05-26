#include <iostream>
using namespace std;

class node
{
public:
    int key;
    node *left, *right;
};

node *TreeNode(int key)
{
    node *Node = new node();
    Node->key = key;
    Node->left = Node->right = NULL;
    return (Node);
}

node *rightRotate(node *x)
{
    node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// If the key is present in the tree, this function moves it to the root.
// If the key is not present, it returns the last item accessed by root.
// This function modifies the tree and returns the modified root.
node *splay(node *root, int key)
{
    // Root is NULL or key is present at root.
    if (root == NULL || root->key == key)
        return root;

    // Key lies in left subtree!
    if (root->key > key)
    {
        // Key is not in tree, we are done
        if (root->left == NULL)
            return root;

        // Zig-Zig (Left Left)
        if (root->left->key > key)
        {
            // First, recursively bring the key as the root of left-left.
            root->left->left = splay(root->left->left, key);

            // Do the first rotation for the root, followed by the second rotation.
            root = rightRotate(root);
        }
        else if (root->left->key < key) // Zig-Zag (Left Right)
        {
            //  First, recursively bring the key as the root of left-right.
            root->left->right = splay(root->left->right, key);

            // Do first rotation for root->left
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }

        // Do second rotation for root
        return (root->left == NULL) ? root : rightRotate(root);
    }
    // Key lies in right subtree
    else
    {
        if (root->right == NULL)
            return root;

        // Zag-Zig (Right Left)
        if (root->right->key > key)
        {
            // Bring the key as root of right-left
            root->right->left = splay(root->right->left, key);

            // Do first rotation for root->right
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        // Zag-Zag (Right Right)
        else if (root->right->key < key)
        {
            // Bring the key as root of right-right and do first rotation
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }

        // Do second rotation for root
        return (root->right == NULL) ? root : leftRotate(root);
    }
}

// The search function for Splay Tree. Note that this function returns the new root of the splay-tree.
// If a key is present in the tree, then it is moved to the root.
node *bstSearch(node *root, int key)
{
    return splay(root, key);
}

void preOrderTraverse(node* root){
    //directly return if the tree is empty:
    if(root == NULL) return;

    //make recursive calls to children from left to right
    //current is first
    cout << root->key << " "; 
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

void inOrderTraverse(node* root){
    //directly return if the tree is empty:
    if(root == NULL) return;

    //make recursive calls to children from left to right
    //current is in middle
    inOrderTraverse(root->left);
    cout << root->key << " "; 
    inOrderTraverse(root->right);
}

void postOrderTraverse(node* root){
    //directly return if the tree is empty:
    if(root == NULL) return;

    //make recursive calls to children from left to right
    //current is last
    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    cout << root->key << " "; 
}

node* subtree_min(node* root) {
	node* itr = root;
	// go to leftmost:
	while(itr->left != NULL)
		itr = itr->left;

	// return the leftmost node
	return itr;
}

///-----------------------------------------------
/// Returns the maximum key in the ThreadedBST
/// Return a pointer to the node that holds the key
/// If the key is not found, return NULL
/// 
node* subtree_max(node* root) {
	node* itr = root;
	// go to rightmost
	while(itr->right != NULL)
		itr = itr->right;

	// return the rightmost node 
	return itr;
}

// Driver Code
int main()
{
    node *root = TreeNode(100);
    root->left = TreeNode(50);
    root->right = TreeNode(200);
    root->left->left = TreeNode(40);
    root->left->left->left = TreeNode(30);
    root->left->left->left->left = TreeNode(20);

    root = bstSearch(root, 20);
    preOrderTraverse(root);
    return 0;
}
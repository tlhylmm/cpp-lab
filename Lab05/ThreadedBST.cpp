// 1521 2021 1114 - Talha Yılmam
// 1521 2020 1076 - Ahmet Kuddusi Albayrak

#include "ThreadedBST.h"

///-----------------------------------------------
/// Erases all nodes in the tree
/// (A slight modification has been made)
/// (In order to avoid infinite recursion)
void ThreadedBST::eraseTreeNodes(BSTNode* node) {
	if (node == NULL) return;
	if (node->rightLinkType == CHILD) eraseTreeNodes(node->right);
	if (node->leftLinkType == CHILD) eraseTreeNodes(node->left);
	delete node;
} //end-eraseTreeNodes

///-----------------------------------------------
/// Adds a given key to the BST
/// 
void ThreadedBST::add(int key) {
	/* 
	 * There are 3 cases when we try to insert a 
	 * add a note to the tree:
	 * 
	 * 1- Adding root to empty tree:
	 *    Set new node as root, left and right
	 *    pointers will be NULL.
	 * 2- Add node as left child
	 *    It means node is smaller than parent,
	 *    so it's right pointer will directly 
	 *    point to parent and it's left pointer
	 *    will point to parent's left pointer.
	 *    And parent's leftLinkType will turn
	 *    to CHILD from THREAD
	 * 3- Add node as right child
	 *    It means node is bigger than parent,
	 *    so it's left pointer will directly 
	 *    point to parent and it's left pointer
	 *    will point to parent's right pointer
	 *    And parent's rightLinkType will turn
	 *    to CHILD from THREAD
	 */

	// create a new node with the given key value
	BSTNode* newNode = new BSTNode(key);

	// start from the root and iterate through the
	// tree to find correct place or match:
	BSTNode* itr = root;
	BSTNode* parent = NULL; //will hold the parent node
	while(itr != NULL){

		// if node already exists on tree
		// return immediately
		if(key == itr->key) return;
		// if key is smaller than node
		// go to left
		parent = itr; //set parent as current node
		if (key < itr->key){
			// check if node has a left child
			// if it does, keep moving left
			if(itr->leftLinkType == CHILD)
				itr = itr->left;
			else 
				break;	
		}
		// if key is bigger than node
		// go to right
		else{
			// check if node has a right child
			// if it does, keep moving right
			if(itr->rightLinkType == CHILD)
				itr = itr->right;
			else
				break;
		}
	}

	// place the new node in correct place

	// if there are no nodes in tree:
	if(parent == NULL)	
		root = newNode; //set newNode as root

	// if newNode is smaller than parent node
	// apply case 2 (explained above)
	else if(key < parent->key){
		newNode->left = parent->left;
		newNode->right = parent;
		parent->left = newNode;
		parent->leftLinkType = CHILD;
	}

	// if newNode is bigger than parent node
	// apply case 3 (explained above)
	else{
		newNode->right = parent->right;
		newNode->left = parent;
		parent->right = newNode;
		parent->rightLinkType = CHILD;
	}

} // end-add

///-----------------------------------------------
/// Removes a given key from the BST (if it exists)
/// 
void ThreadedBST::remove(int key) {
    BSTNode* itr = root;
	BSTNode* parent = root;

	// if root is empty, return:
	if (itr == NULL)
		return;

	// find the node with the given key:
	while (1) {
		// go to right if key is bigger than current node:
		if (key > itr->key) {
			// if reached end, return:
			if (itr->rightLinkType == THREAD) return;
			
			parent = itr; // update parent			
			itr = itr->right; // move to right
		}
		// go to left if key is smaller than current node:
		else if (key < itr->key) {
			// if reached end, return:
			if (itr->leftLinkType == THREAD) return;		

			parent = itr; // update the parent			
			itr = itr->left; // move to the left
		}
		// exit loop if node with the given key is found:
		else {
			break;
		}
	}

	// reconfigure the tree:
	BSTNode* temp = itr;

	// if the node to be removed has children, update nodes:
	if (itr->rightLinkType != THREAD && itr->leftLinkType != THREAD) {
		parent = itr; // update parent
		// move to left, go to rightmost
		temp = itr->left;
		while(temp->rightLinkType != THREAD) {
			parent = temp;
			temp = temp->right;
		}
		itr->key = temp->key;
	}

	// reconfigure the tree for deletion:
	// update the left part:
	if (parent->key >= temp->key) {
		if (temp->rightLinkType== THREAD && temp->leftLinkType == THREAD) {
			parent->left = temp->left;
			parent->leftLinkType = THREAD;
		}
		else if (temp->rightLinkType == THREAD) {
			// move to left:
			BSTNode* max = temp->left;
			// get the biggest node from subtree:
			while (max->rightLinkType != THREAD) {
				max = max->right;
			}			
			// connect the leaf to the parent:
			max->right = parent;
			parent->left = temp->left;
		}
		else {
			// move to right:
			BSTNode* min = temp->right;
			// get the smallest node from subtree:
			while (min->leftLinkType!= THREAD) {
				min = min->left;			
			}
			// connect the leaf to the parent:
			min->left = temp->left; 
			parent->left = temp->right;
		}
	}
	// update the right part:
	else {
		if(temp->rightLinkType == THREAD && temp->leftLinkType == THREAD) {
			parent->right = temp->right;
			parent->rightLinkType = THREAD;
		}
		else if(temp->rightLinkType == THREAD) {
			// move to left:
			BSTNode* max = temp->left;
			// get the biggest node from subtree:
			while(max->rightLinkType != THREAD) {
				max = max->right;
			}
			// connect the leaf to the parent:
			max->right = temp->right;
			parent->right = temp->left;
		}
		else {
			// move to right:
			BSTNode* min = temp->right;
			// get the smallest node from subtree:
			while (min->leftLinkType != THREAD) {
				min = min->left;
			}
			// connect the leaf to the parent:
			min->left = parent;
			parent->right = temp->right;
		}
	}
} // end-remove

///-----------------------------------------------
/// Searches a given key in the ThreadedBST
/// Return a pointer to the node that holds the key
/// If the key is not found, return NULL
/// 
BSTNode *ThreadedBST::find(int key) {
	// since this is a binary tree, node's are ordered

	BSTNode* itr = root; //start from the root
	
	while(true){ // start searching
		// if the given key equals to current node's key  
		// return the current node:
		if(itr->key == key) return itr;
		// go to right if it's bigger:
		else if(key > itr->key) itr = itr->right;
		// go to left if it'S smaller: 
		else if(key < itr->key) itr = itr->left;
		// return NULL if key is not found:
		else return NULL;
	}
} // end-find

///-----------------------------------------------
/// Returns the minimum key in the ThreadedBST
/// Return a pointer to the node that holds the key
/// If the key is not found, return NULL
/// 
BSTNode* ThreadedBST::min() {
	BSTNode* itr = root;
	// go to leftmost:
	while(itr->left != NULL)
		itr = itr->left;

	// return the leftmost node
	return itr;
} // end-min

///-----------------------------------------------
/// Returns the maximum key in the ThreadedBST
/// Return a pointer to the node that holds the key
/// If the key is not found, return NULL
/// 
BSTNode* ThreadedBST::max() {
	BSTNode* itr = root;
	// go to rightmost
	while(itr->right != NULL)
		itr = itr->right;

	// return the rightmost node 
	return itr;
} // end-max

///-----------------------------------------------
/// Given a valid pointer to a node in ThreadedBST,
/// returns a pointer to the node that contains the inorder predecessor
/// If the inorder predecessor does not exist, returns NULL
/// 
BSTNode* ThreadedBST::previous(BSTNode* node) {
	// since we already record if a node
	// keeps the successor or predecessor
	// we can check it's property and return
	// if it points to predecessor or successor:

	// search in the tree doesn't needed since
	// we can directly access the node's address
	// and start from there

	BSTNode* parent = node; // hold the parent node
	BSTNode* itr = node;

	// there are 2 cases:

	// 1- if node's left already holds the predecessor
	//    or NULL (which means leftLinkType being THREAD)
	//    move to left and return
	if(itr->leftLinkType == THREAD)
		return itr->left;

	// 2- if node's left points to a child, move to the left 
	//    and then go to rightmost node. stop when node's right
	//    points to the parent and then return it
	else{
		itr = itr->left; // move to left
		while (itr->right != parent) { // go to rightmost
			itr = itr->right;
		}

		return itr;
	}
} // end-previous

///-----------------------------------------------
/// Given a valid pointer to a node in the ThreadedBST,
/// returns a pointer to the node that contains the inorder successor
/// If the inorder successor does not exist, returns NULL
/// 
BSTNode* ThreadedBST::next(BSTNode* node) {
	// since we already record if a node
	// keeps the successor or predecessor
	// we can check it's property and return
	// if it points to predecessor or successor:

	// search in the tree doesn't needed since
	// we can directly access the node's address
	// and start from there

	BSTNode* parent = node; // hold the parent node
	BSTNode* itr = node;

	// there are 2 cases:

	// 1- if node's right already holds the successor
	//    or NULL (which means rightLinkType being THREAD)
	//    move to right and return

	if (itr->rightLinkType == THREAD)
		return itr->right;
	
	// 2- if node's right points to a child, move to the right 
	//    and then go to leftmost node. stop when node's left
	//    points to the parent and then return it

	else {
		itr = itr->right; // move to right
		while (itr->left != parent) { // go to leftmost
			itr = itr->left;
		}

		return itr;
	}
	
} // end-next
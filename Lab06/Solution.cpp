#include "WordFreq.h"
#include <vector>
#include <fstream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#define Height(p) ((p) == NULL? -1:(p)->height)

using namespace std;

struct AVLNode {
	WordFreq* key;
	int height;
	AVLNode* right;
	AVLNode* left;

	//constructor
	AVLNode(WordFreq* key) {
		this->key = key;
		key->freq = 1; // new added words frequency will be one
		left = right = NULL;
		height = 0;
	}
};


vector<WordFreq> GetMostFrequentKWords(string filename, int k) {
	vector<WordFreq> final; //will hold the most frequent k words
	vector<WordFreq*> myVect; //will be used in calculations
	
	AVLNode* root = NULL;
	
	int maxFrequency = 1; //will hold the most repeated item's frequency
	
	/* this boolean will be used to determine if the taken string already 
	 * exists in the vector, it won't be readded to the vector and it's 
	 * frequency will be incremented.
	 */
	bool encountered = false;

	//read the text file:
	fstream readFile; 
	readFile.open(filename);
	string temp; //will hold each word of the text

	while (readFile >> temp) { //take each word
		// convert all characters to lowercase:
		for (char *p = &temp[0]; *p; ++p) {
		    *p = tolower(*p);
		}

		int l = 0;
		for (int i = 0; i < temp.length(); i++) {

			if (temp[i] >= 'a' && temp[i] <= 'z') {

				temp[l] = temp[i];
				l++;
			}
		}
		temp.erase(l);

		//if word's length is shorter than 3, move to next word
		if (temp.length() < 3) continue;

		//	Operations that are done in here are taken from
		//	given AVL implementation in classroom and modified.
		/*	Ordering and rebalancing the tree will be done by
	 	*	the words frequency.
	 	*
	 	*	Checking for an existing node will be done by
	 	*	comparing string's letters.
	 	*/
		WordFreq* w = new WordFreq(temp);
		stack <AVLNode*> S;
		// AVL tree
		AVLNode* q = NULL;
		AVLNode* p = root;
		while (p){ //check if the word already exists in the tree
			S.push(p);
			q = p;
			//if a matching word found:
			if (p->key->word == w->word) {
				p->key->freq = p->key->freq++;
				if (p->key->freq > maxFrequency) { maxFrequency = p->key->freq; }
				encountered = true;
				break;
			}
			//if a matching word not found, keep moving
			else if (w->word < p->key->word){ 
				p = p->left; 
				encountered = false;
			}
			else if (w->word > p->key->word){ 
				p = p->right;
				encountered = false;
			}
		}
		if (!encountered){
			myVect.push_back(w);
			AVLNode* node = new AVLNode(w);
			if (root == NULL) root = node;
			else if (w->word < q->key->word) q->left = node;
			else if (w->word > q->key->word)  q->right = node;
		}
		// Balance
		while (!S.empty()){
			AVLNode* p = S.top(); S.pop();
			AVLNode* parent = NULL;
			int hl = Height(p->left);
			int hr = Height(p->right);
			p->height = 1 + max(hl, hr);
			int balance_factor = hl - hr;
			if (balance_factor >= -1 && balance_factor <= 1) continue;
			if (!S.empty()) parent = S.top();
			if (balance_factor == 2){
				AVLNode* l = p->left;
				hl = Height(l->left);
				hr = Height(l->right);
				balance_factor = hl - hr;
				if (balance_factor == 0 || balance_factor == 1) {
					p->left = l->right;
					l->right = p;
					p->height = 1 + max(Height(p->left), Height(p->right));
					l->height = 1 + max(Height(l->left), Height(l->right));
					if (parent == NULL)
						root = l;
					else
					{
						if (p == parent->left) parent->left = l;
						else parent->right = l;
					}
				}
				else {
					AVLNode* x = l->right;
					l->right = x->left;
					x->left = l;
					p->left = x->right;
					x->right = p;
					p->height = 1 + max(Height(p->left), Height(p->right));
					l->height = 1 + max(Height(l->left), Height(l->right));
					x->height = 1 + max(Height(x->left), Height(x->right));
					if (parent == NULL)
						root = x;
					else
					{
						if (p == parent->left) parent->left = x;
						else parent->right = x;
					}
				}
			}
			else {
				AVLNode* r = p->right;
				hl = Height(r->left);
				hr = Height(r->right);
				balance_factor = hl - hr;
				if (balance_factor == 0 || balance_factor == -1) {
					p->right = r->left;
					r->left = p;
					p->height = 1 + max(Height(p->left), Height(p->right));
					r->height = 1 + max(Height(r->left), Height(r->right));
					if (parent == NULL)
						root = r;
					else
					{
						if (p == parent->left) parent->left = r;
						else parent->right = r;
					}
				}
				else {
					AVLNode* x = r->left;
					r->left = x->right;
					x->right = r;
					p->right = x->left;
					x->left = p;
					p->height = 1 + max(Height(p->left), Height(p->right));
					r->height = 1 + max(Height(r->left), Height(r->right));
					x->height = 1 + max(Height(x->left), Height(x->right));
					if (parent == NULL)
						root = x;
					else
					{
						if (p == parent->left) parent->left = x;
						else parent->right = x;
					}
				}
			}
		}
	}

	readFile.close(); //close the text file

	//a vector that will hold the words:
	map<int, vector<std::string>> wordMap;

	for (const auto& entry : myVect) {
	    wordMap[entry->freq].push_back(entry->word);
	}

	//sort the words in alphabetical order
	for (auto& entry : wordMap) {
	    sort(entry.second.begin(), entry.second.end());
	}

	int x = 0;
	for (auto it = wordMap.rbegin(); it != wordMap.rend(); ++it) {
	    for (const auto& word : it->second) {
	        WordFreq f(word); //build new wordFreq from word
	        f.freq = it->first; //and get the frequency to member

	        final.push_back(f); //push it to the result vector
	        ++x; //raise the counter

	        if (x == k) break; //if reached given word count, stop
	    }

	    if (x == k) break; //if reached given word count, stop
	}

	return final;
}
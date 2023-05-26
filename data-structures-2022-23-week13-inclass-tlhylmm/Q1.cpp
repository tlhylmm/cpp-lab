#include <iostream>
#include <cstring>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    struct TrieNode* child[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct Trie {
    TrieNode* root;

    Trie() {
        root = new TrieNode;
        root->isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            root->child[i] = nullptr;
        }
    }

    void insert(string key) {
        TrieNode* current = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (current->child[index] == nullptr) {
                current->child[index] = new TrieNode[sizeof(TrieNode)];
                // Initialize the new TrieNode object
                current->child[index]->isEndOfWord = false;
                for (int j = 0; j < ALPHABET_SIZE; j++) {
                    current->child[index]->child[j] = nullptr;
                }
            }
            current = current->child[index];
        }
        current->isEndOfWord = true;
    }


    bool search(string key) {
        TrieNode* current = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (current->child[index] == nullptr) {
                return false;
            }
            current = current->child[index];
        }
        return current->isEndOfWord;
    }

    bool hasPrefix(string prefix) {
        TrieNode* current = root;
        for (int i = 0; i < prefix.length(); i++) {
            int index = prefix[i] - 'a';
            if (current->child[index] == nullptr) {
                return false;
            }
            current = current->child[index];
        }
        return true;
    }

    void deleteKey(string key) {
        deleteHelper(root,root,-1, key, 0);
    }


    void deleteHelper(TrieNode* current, TrieNode* parent, int childIndex, string key, int depth) {
        if (current == nullptr) {
            return;
        }

        if (depth == key.length()) {
            // If the current node is a leaf node, mark it as not the end of a word
            if (isLeafNode(current)) {
                current->isEndOfWord = false;
            }

            // If the current node has no children, delete it and set the child pointer of the parent node to null
            if (hasNoChildren(current)) {
                delete current;
                parent->child[childIndex] = nullptr;
            }
            return;
        }

        int index = key[depth] - 'a';
        deleteHelper(current->child[index], current, index, key, depth + 1);

        // If the current node has no children and is not the end of a word, delete it and set the child pointer of the parent node to null
        if (hasNoChildren(current) && !current->isEndOfWord) {
            delete current;
            parent->child[childIndex] = nullptr;
        }
    }


  bool isLeafNode(TrieNode* node) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
      if (node->child[i] != nullptr) {
        return false;
      }
    }
    return true;
  }

  bool hasNoChildren(TrieNode* node) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
      if (node->child[i] != nullptr) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Trie trie;
  trie.insert("hello");
  trie.insert("world");
  trie.insert("hi");
  trie.insert("hey");
  trie.insert("howdy");
  cout << trie.search("hello") << endl; // prints 1
  cout << trie.search("hell") << endl; // prints 0
  cout << trie.hasPrefix("he") << endl; // prints 1
  trie.deleteKey("hey");
  cout << trie.search("hey") << endl; // prints 0
  return 0;
}


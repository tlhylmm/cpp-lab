#include <iostream>
#include <unordered_map>
using namespace std;

const int table_size = 200;

struct hashTableEntry {
    int k;
    int v;
};

class hashMapTable {
private:
    unordered_map<int, int> table;

public:
    hashMapTable() {
        // Initialize the hash table
        table.reserve(table_size);
    }

    int hashFunc(int key) {
        return key % table_size;
    }

    void Insert(int key, int value) {
        // Insert element at the key
        table[key] = value;
    }

    void SearchKey(int key) {
        // Search element at the key
        if (table.find(key) != table.end()) {
            cout << "Value at key " << key << ": " << table[key] << endl;
        } else {
            cout << "Key not found" << endl;
        }
    }

    void Remove(int key) {
        // Remove element at the key
        table.erase(key);
    }

    ~hashMapTable() {
        // Destroy the objects created by the constructor
        table.clear();
    }
};

int main() {
    hashMapTable h;

    while (true) {
        cout << "1.Insert element into the table" << endl;
        cout << "2.Search element from the key" << endl;
        cout << "3.Delete element at a key" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 4) {
            break;
        }

        switch(choice) {
            case 1: {
                int element, key;
                cout << "Enter element to be inserted: ";
                cin >> element;
                cout << "Enter key at which element to be inserted: ";
                cin >> key;
                h.Insert(key, element);
                break;
            }
            case 2: {
                int key;
                cout << "Enter key of the element to be searched: ";
                cin >> key;
                h.SearchKey(key);
                break;
            }
            case 3: {
                int key;
                cout << "Enter key of the element to be deleted: ";
                cin >> key;
                h.Remove(key);
                break;
            }
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }

    return 0;
}

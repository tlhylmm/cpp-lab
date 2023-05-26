#include <iostream>
using namespace std;

int main() {
    int C[5], i, j, d = 0, counter = 0, temp;
    int X[5] = { 0 }; //temporary array to mark duplicate item indexes as 1
    for (i = 0; i < 5; i++) {
        cout << "Please enter element " << i + 1 << " of the array: ";
        cin >> C[i];
    }
    cout << "\n";
    for (i = 0; i < 5; i++) { //printing array values with indexes
        cout << "Index: " << i << " Value: " << C[i] << endl;

    }
    cout << "\nDuplicate pairs:\n";
    for (i = 0; i < 5; i++) { //nested loop to find duplicate elements
        for (j = i + 1; j < 5; j++) {
            if (C[i] == C[j]) {
                cout << "Indexes: " << i << "-" << j << " Value: " << C[j] << "\n";
                d = 1; //d will be 1 if there is a duplicate in list
            }
        }
    }
    if (d == 0) { cout << "None\n"; }
    /* To find the unique elements, we create a temporary array X filled with 0.
       Then we will pick two elements and compare them and if they are the same,
       we will flag the index in X as 1.
       We create a loop to pick the first item. If the first item's flag is 0,
       we proceed to pick the second item and compare them. If they are the same
       flag their X indexes as 1. After we are done looping through second item,
       we increase the counter by 1.
       With this method, we can skip the duplicates from previous comparation
       and count the unique items easily.
       */
    for (i = 0; i < 5; i++) {
        if (X[i] == 0) {
            for (j = i + 1; j < 5; j++) {
                if (C[i] == C[j]) {
                    X[i] = 1;
                    X[j] = 1;
                }
            }
            counter++;
        }
    }
    cout << "\nNumber of unique elements: " << counter << " (duplicates counted once if exists)\n";
    for (i = 0; i < 5; i++) { //using bubble sort
        for (j = i + 1; j < 5; j++) {
            if (C[i] > C[j]) {
                temp = C[j];
                C[j] = C[i];
                C[i] = temp;
            }
        }
    }
    cout << "\nMinimum element: " << C[0] << "\n";
    cout << "Maximum element: " << C[4] << "\n\n";
    system("pause");
}
#include <iostream>
using namespace std;
//first, change all the zeros with -1. count the number of -1's and extract it
//from 10, so that we can find the number of values which are different than 10
//than create a temporary array with the size of different ones and store them
//inside. then refill the array a with firstly these numbers and then -1's
int main() {
    int a[10] = { 2, 0, 0, 1, 4, 9, 0, 5, 0, 7 };
    int counter = 0, j = 0;
    for (int i = 0; i < 10; i++) { //change zeros with -1
        if (a[i] == 0) {
            a[i] = -1;
        }
    }
    int temp[6]; // 10 - zeros(4) = values different than 0 (6 in this case)
    for (int i = 0; i < 10; i++) {
        if (a[i] != -1) { //store the number in temp array if it is not zero
            temp[j] = a[i];
            j++;
        }
    }
    for (int i = 0; i < 6; i++) { //refilling the array a with values
        a[i] = temp[i];
    }
    for (int i = 6; i < 10; i++) { //refilling the rest with -1 
        a[i] = -1;
    }
    for (int i = 0; i < 10; i++) { //printing the array
        cout << a[i] << " ";
    }
    cout << endl;
    system("pause");
}
#include <iostream>
using namespace std;
#define direction 1 //1 is left and 2 is right
#define N 2 //how many times it will be shifted

void main()
{

    int a[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int temp[N], x = N, y = 0; //temporary numbers and arrays
    if (direction == 1) { //if direction is left
        for (int i = 0; i < N; i++) { //save the first N numbers to temporary array
            temp[i] = a[i];
        }
        for (int i = N; i < 9; i++) { //shift the numbers to the left
            a[x - 2] = a[x];
            x++;
        }
        for (int i = 9 - N; i < 9; i++) { //update the last N numbers with values in temp array
            a[i] = temp[y];
            y++;
        }
        for (int i = 0; i < 9; i++) { //print final version of the array
            cout << a[i] << " ";
        }
        cout << endl;
    }
    if (direction == 2) { //if direction is right
        for (int i = 9 - N; i < 9; i++) { //save the last N numbers to temporary array
            temp[y] = a[i];
            y++;
        }
        for (int i = 8 - N; i >= 0; i--) { //shift the numbers to the right
            a[i + 2] = a[i];
        }
        for (int i = 0; i < N; i++) { //update the first N numbers with values in temp array
            a[i] = temp[i];
        }
        for (int i = 0; i < 9; i++) { //print final version of the array
            cout << a[i] << " ";
        }
        cout << endl;
    }
    system("pause");
}
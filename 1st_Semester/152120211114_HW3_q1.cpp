#include <iostream>

using namespace std;
//prototypes
void print_without_pointer (int A[][5]);
void print_with_pointer(int *A);
void print_with_pointer2(int *A);
void change_odd(int *A);
void change_even(int *A);

int main()
{
    //define 2D array
    int A[3][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    //calling functions
    print_without_pointer(A);
    cout << endl;
    print_with_pointer(A[0]);
    cout << endl;
    print_with_pointer2(A[0]);
    change_odd(A[0]); //changing odd numbers to 0
    cout << endl;
    print_without_pointer(A); //printing array to see changes
    cout << endl;
    change_even(A[0]); //changing even numbers to 1
    cout << endl; //printing array to see changes
    print_without_pointer(A);
    system("pause");
}

void print_without_pointer (int A[][5]){
    for(int i = 0; i < 3; i++){ //nested loop for accessing 2D array
        for(int j = 0; j < 5; j++){
            cout << "Element at A[" << i << "]" << "[" << j << "]: " << A[i][j]
            << " Address: " << &A[i][j] << endl;
        }
    }
}
//from now on, all nested loops will use (A + ((i*column) + j)) to access array

void print_with_pointer (int *A){
    for(int i = 0; i < 3; i++){ //nested loop for printing the elements
        for(int j = 0; j < 5; j++){
            cout << "Element at A[" << i << "]" << "[" << j << "]: " << *(A + ( (i*5) + j))
            << " Address: " << (A + ((i*5) + j)) << endl; 
        }
    }
}

void print_with_pointer2(int *A){
    for(int i = 0; i < 15; i++){
        //"i" will be used to do pointer arithmetic (to add array A)
        cout << "Element in A: " << *(A + i) << " Address: " << A + i << endl;
    }
} 

void change_odd(int *A){
    //using only 1 for loop since it is easy to work on
    for(int i = 0; i < 15; i++){ //"i" will be used to do pointer arithmetic
        if( *(A + i) % 2 == 1){ //do modulo operation to find if it is odd
            *(A +i) = 0; //change value to zero if it is odd
        }
    }
}

void change_even(int *A){
    //using only 1 for loop since it is easy to work on
    /* there are two ways to change even numbers after changing the odd: we can
    change our loop to start from 1 instead of 0 and increase the i value by 2.
    this way we can loop through only the 2nd, 4th, 6th, 8th items and so on... 
    but question wants us to check the array items one by one and then find 
    even numbers. 0 % 2 = 0. so we have to pass the zeros we changed before.
    So we add && operator and also check if the value is NOT ZERO */
    for(int i = 1; i < 15; i+=2){ //"i" will be used to do pointer arithmetic
        if( *(A + i) % 2 == 0 && *(A + i) != 0){ //modulo and not zero check
            *(A +i) = 1; //change value to one if it is even
        }
    }
}
#include <iostream>
#define row 4
#define column 4


using namespace std;
void replace(int *ptr);

int main()
{
    int arr[row][column] = {0}; //create array
    int *ptr = &arr[0][0]; //pointing the first element
    replace(ptr); //calling function
    for (int i = 0; i < row; i++){ //nested loop to print elements
        for (int j = 0; j < column; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    } 
    system("pause");
}

void replace(int *ptr) 
{
    //use row minus one and column minus one to fill inside with 1's
    //using ptr + ((i * row) + j) formula
    for (int i = 1; i < (row - 1); i++){ 
        for (int j = 1; j < (column - 1); j++){
            *(ptr + ((i * row) + j)) = 1;
            
        }
    }   
}

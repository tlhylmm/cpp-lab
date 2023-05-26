#include <iostream>
#define length 10
using namespace std;
void replaceZero2MinusOne(int *ptr); //prototype


int main()
{
    int A[length] = {2, 0, 0, 1, 4, 9, 0, 5, 0, 7};
    int *ptr = &A[0]; //
    //looping the function "length" times to catch the missed zeros
    for(int j = 0; j < length + 1; j++){
        replaceZero2MinusOne(ptr);
    }
    //loop the print the array elements after change
    for(int j = 0; j < length; j++)
    {
        cout << *(ptr + j) << " ";
    }
    system("pause");
}

void replaceZero2MinusOne(int *ptr)
{
    for (int i = 0; i < length; i++){ //loop to find zeros
        if( *(ptr + i) == 0){
			//loop to start from the zero and move all the numbers to right
            for(int j = i; j < (length - 1); j++){
                *(ptr + j) = *(ptr + j + 1); //move numbers to right
            }
            *(ptr + (length - 1)) = -1; //make the last number zero
        }
    }
}
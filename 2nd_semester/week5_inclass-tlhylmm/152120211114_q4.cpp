#include <iostream>

using namespace std;

int findCommon(int *a, int *b){
    int common = 0; //this will store the number of common elements
    for(int i = 0; i < 5; i++){ //for loop to go through the array elements
        if(a[i] == b[i]){ common++;} //one line condition for increasing the counter if common item found
    }
    return(common); //return the number of common items.
}

int main()
{
    int a[5] = {10, 20, 30, 40, 50}; //first array
    int b[5] = {99, 20, 99, 40, 50}; //second array
    //calling the function in cout since it has a return.
    cout << "Array a and b have " << findCommon(a,b) << " common items" << endl;
    
    system("pause");
}
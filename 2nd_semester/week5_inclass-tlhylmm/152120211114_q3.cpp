#include <iostream>

using namespace std;
int findValue(int *arr, int index ){
    return(arr[index]); //return the (index)'th element of the array
}

void sumOfArray(int *arr, int *result){
    for(int i = 0; i < 5; i++ ){ //looping for the elements of array
        *result += arr[i]; //summing up the array elements to result
    }
    /* we can also use return(*result); but the question wants us to print
    the variable "result" in the main function. our function starts with void
    and doesn't contain return just because of this reason. */
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50}; //define the array (sum is 150)
    int index, result = 0; //initialize result to 0
    cout << "Which index would you like to acces? ";
    cin >> index; //taking input for the index
    cout << "Element in the " << index << ". index is " << findValue(arr, index) << endl;  //calling findValue function
    sumOfArray(arr, &result); //calling sumOfArray function
    cout << "Sum of the array elements is " << result << endl;
    /* first we called function sumOfArray to modify the "result" value and
    then we printed the "result" in main function. Because question wants us
    to do so. It would also be fine to use return(*result); in the function and
    then just printing the function in cout. */
    system("pause");
}
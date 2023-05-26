#include <iostream>
#include <string>
using namespace std;

int main(){
    int* pSize = new int; //define dynamic size ()
    //pSize can be also defined in stack without pointer
    int* arr = new int[*pSize]; //define array with dynamic size
    cout << "Please enter the size of array: ";
    cin >> *pSize; //get size dynamically
    
    //fill the array:
    for(int i = 0; i < *pSize; i++){
        arr[i] = i;
    }
    
    //print the array:
    cout << "Array: " << endl;
    for(int i = 0; i < *pSize; i++ ){
        cout << "\t" << i << ". element: " << i << endl;        
    }
    
    //delete pointer
    delete pSize; 
    delete [] arr;
    return 0;
}
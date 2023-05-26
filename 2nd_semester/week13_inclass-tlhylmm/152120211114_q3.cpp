#include <iostream>
#include <string>
using namespace std;

int main(){
    //get size of array:
    int size;
    cout << "How many lessons will you enter? ";
    cin >> size;

    //declare an array in heap:
    string* ptrArray = new string[size];

    //fill the array: 
    for(int i = 0; i < size; i++){
        cout << "Enter " << i + 1 << ". lesson name: "; //using i+1 to look better 
        cin >> ws; //clear input buffer
        getline(cin, ptrArray[i]);
    }

    cout << endl;

    //print the results:
    for(int i = 0; i < size; i++){
        cout << "The string " << i << ". index value is: " << ptrArray[i] << endl;        
    }

    return 0;
}
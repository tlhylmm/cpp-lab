#include <iostream>
#include <iomanip> //to set the precision
#include <string>
using namespace std;

int main(){
    //get the size of array
    int size;
    cout << "Enter total number of students: ";
    cin >> size;
    cout << endl;

    //create array in heap:
    float* ptrArray = new float[size];

    //take inputs from user to fill array
    cout << "Enter GPA of students." << endl;
    for(int i = 0; i < size; i++){
        cout << "Student " << i + 1 << ": ";
        cin >> ptrArray[i];
    }

    cout << endl;

    //print the array elements:
    cout << "Displaying GPA of students." << endl;
    for(int i = 0; i < size; i++){
        cout << fixed << showpoint; //set the digits after floating point
        cout << setprecision(2);
        cout << "Student " << i + 1 << ": " << ptrArray[i] << endl;
    }

    return 0;
}
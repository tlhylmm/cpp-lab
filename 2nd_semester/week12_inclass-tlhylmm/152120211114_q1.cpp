#include <iostream>
#include <string>
using namespace std;

int main(){
    int* pInt = new int;
    float* pFloat = new float;
    char* pChar = new char;
    string* pString = new string;

    //input buffer needs to be cleaned to not cause any trouble
    //while taking string and char input from the user
    cout << "Enter the value of integer: ";
    cin >> *pInt; 
    cout << "Enter the value of float: ";
    cin >> *pFloat; 
    cout << "Enter the value of char: ";
    cin >> ws; //to clear the input buffer
    cin >> *pChar; 
    cout << "Enter the value of string: ";
    cin >> ws; //to clear the input buffer
    getline(cin, *pString); //using getline to not cause trouble when " " is given

    cout << "\nValues belonging to types:"
        << "\nThe value of integer: " << *pInt 
        << "\nThe value of float: " << *pFloat 
        << "\nThe value of char: " << *pChar 
        << "\nThe value of string: " << *pString << endl; 

    delete pInt;
    delete pFloat;
    delete pChar;
    delete pString;

    return 0;
}
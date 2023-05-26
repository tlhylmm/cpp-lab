#include <iostream>
#include <string>
using namespace std;

int swap(string*  first, string* last){
    string temp; //use temporary string to store the first
    
    //update the values:
    temp = *first;
    *first = *last;
    *last = temp;
}

int main(){
    string text1, text2;

    //get inputs:
    cout << "Please enter your first string: ";
    getline(cin, text1);
    cout << "Please enter your second string: ";
    cin >> ws; //clear input buffer
    getline(cin, text2);
    cout << endl;

    //print the unchanged values:
    cout << "First: " << text1 << endl;
    cout << "Second: " << text2 << endl;

    swap(&text1, &text2); //call the function
    cout << endl;

    //print values after swapping:
    cout << "First: " << text1 << endl;
    cout << "Second: " << text2 << endl;

    return 0;
}
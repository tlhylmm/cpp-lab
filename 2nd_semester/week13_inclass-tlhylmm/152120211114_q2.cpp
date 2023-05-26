#include <iostream>
#include <string>
using namespace std;

int main(){
    string array[10];

    //get 10 inputs and fill the array:
    for(int i = 0; i < 10; i++){
        cout << "Enter " << i + 1 << ". lesson name: "; //using i+1 to look better 
        cin >> ws; //clear input buffer
        getline(cin, array[i]);
    }

    cout << endl;

    //print the results:
    for(int i = 0; i < 10; i++){
        cout << "The string " << i << ". index value is: " << array[i] << endl;        
    }

    return 0;
}
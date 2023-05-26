#include <iostream>
#include <string>
using namespace std;

int main(){
    string myString;
    cout << "Please type your string (Seperate each word with one space): "; 
    getline(cin, myString); //using getline since cin breaks the line if space is given
    for(int i = 0; i < myString.size(); i++){
        if(i == 0){
            myString[i] = toupper(myString[i]); //capitalize first letter
        } 
        else if (myString[i] == ' '){
            myString[i+1] = toupper(myString[i+1]); //capitalize next letter if space is found
        } 
    }
    cout << myString << endl;
    system("pause");
}

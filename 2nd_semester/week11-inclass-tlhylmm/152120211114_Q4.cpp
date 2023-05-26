#include <iostream>
#include <string>
using namespace std;
// this program is coded to work even if the first encountered letter is g instead of e

int main(){
    string myString;
    int counter = 0; //counter will keep the distanced e-g's
    cout << "Please type your word (lowercase only): ";
    getline(cin, myString); //using getline since cin breaks the line if space is given
    for(int i = 0; i < myString.size(); i++){
        //check if the second next letter is "g" if "e" is found
        if(myString[i] == 'e' && myString[i+2] == 'g'){counter++;}
        //check if the second next letter is "e" if "g" is found
        else if(myString[i] == 'g' && myString[i+2] == 'e'){counter++;}
    }
    cout << myString << "-> " << counter << endl;
    system("pause");
}
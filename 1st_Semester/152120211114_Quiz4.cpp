#include <iostream>
using namespace std;
int main(){
    string myString = "Hello? 7 ThiS* SaMple+5  SeNtenCES";
    int uppercase = 0, lowercase = 0, digit = 0, special = 0; //initialize counters
    for(int i = 0; i < myString.size(); i++){ //looping through the letters
        if(myString[i] == ' '){
            continue; //pass the blank spaces
        }
        else{ //checking which range is the letter in then raising the counters
            if(myString[i] >= 'A' && myString[i] <= 'Z' ){uppercase++;}
            else if(myString[i] >= 'a' && myString[i] <= 'z'){lowercase++;}
            else if(myString[i] >= '0' && myString[i] <= '9'){digit++;}
            else{special++;}
        }
    }
    cout << "Your string: " << myString;
    cout << "\nUppercase: " << uppercase 
        << "\nLowercase: " << lowercase
        << "\nDigit: " << digit
        << "\nSpecial: " << special << "\n\n";
    system("pause");
}
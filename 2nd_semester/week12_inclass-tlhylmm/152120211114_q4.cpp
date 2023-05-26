#include <iostream>
#include <string>
using namespace std;

int main(){
    string word;
    int flag = 0; //will turn to 1 if it's palindrome    
    cout << "Please enter a string without spaces: ";
    cin >> word;

    
    if(word.size() % 2 == 0){ //if word has an even number of letters
        for(int i = 0; i < (word.size() / 2); i++){ //go until middle
            if(word[i] == word[word.size() - (i + 1)]){
                flag = 1; //flag 1 if letters match
            }
            else{flag = 0;} //flag 0 if any non-matching letters found
        }
    }
    else{ //if word has an odd number of letters
        for(int i = 0; i < ((word.size() - 1) / 2); i++){ //go until middle
            if(word[i] == word[word.size() - (i + 1)]){
                flag = 1; //flag 1 if letters match
            }
            else{flag = 0;} //flag 0 if any non-matching letters found
        }
    }

    if(flag == 1){cout << word << " is a palindrome" << endl;}
    else{cout << word << " is not a palindrome" << endl;}

    return 0;
}
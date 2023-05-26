#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    //open file in write mode:
    ofstream file;
    file.open("data.txt");

    //fill the file:
    file << "Name1$Surname1$15\n"
    << "$Name2$Surname2$23\n"
    << "$Name3$Surname3$45";

    file.close();

    //open file in read mode:
    ifstream file_;
    file_.open("data.txt");


    //print info:
    string word;
    int wordIndex = 0; //will keep the index of words in each line
    while(getline(file_, word, '$')){
        if(wordIndex == 0){
            cout << "Name: " << word;
            wordIndex++;
        }
        else if(wordIndex == 1){
            cout << " Surname: " << word;
            wordIndex++;
        }
        else if(wordIndex == 2){
            cout << " Age: ";
            if(stoi(word) > 18){cout << "Adult";}
            else{cout << "Child";}
            cout << endl;
            wordIndex = 0;
        }
    }

    return 0;
}
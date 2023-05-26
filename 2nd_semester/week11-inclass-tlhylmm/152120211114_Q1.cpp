#include <iostream>
#include <string>
using namespace std;

int main(){
    string word;
    cout << "Plase type your word: "; 
    getline(cin, word); //using getline since cin breaks the line if space is given
    cout << "Original string: " << word;
    cout << "\nReverse string: ";
    for(int i = word.size(); i >= 0; i--){
        cout << word[i]; //printing letters starting from the end
    }
    cout << endl;
    system("pause");
}

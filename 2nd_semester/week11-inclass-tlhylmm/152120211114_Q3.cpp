#include <iostream>
#include <string>
using namespace std;

int main(){
    string myString;
    int start, end, counter = 0, longest = 0; 
    /*"start" and "end" will keep the starting and ending locations of words
     *"longest" will keep the length of the current longest word
     *"counter" will raise until a space is found.
     *if a space is found. compare the current length with the longest,
     *save the location of the word if it is longer
     */
    cout << "Please type your string: ";
    getline(cin, myString); //using getline since cin breaks the line if space is given
    myString = myString + ' '; //adding a space to the end for our loop to work properly
    for(int i = 0; i < myString.size(); i++){
        if(myString[i] != ' '){   
            counter++;
        }
        else if(myString[i] = ' '){
            if(counter > longest){ //if a new longer word found, do below:
                longest = counter; //update the longest word length
                end = i - 1; //end of the word is at behind the space
                start = end - (counter - 1); //start of the word = (end - number of letters)
            }
            counter = 0; //reset the counter
        }
    }
    for(int i = start; i <= end; i++){
        cout << myString[i];

    }
    cout << endl;
    system("pause");
}
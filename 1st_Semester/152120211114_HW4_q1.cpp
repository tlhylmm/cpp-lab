#include <iostream>
#include <string>
using namespace std;

/* The function findRepeatingLetters lists all the repeating letters
 * Just like the instructions say:
 * !! It doesn't return anything !!
 * !! Result is printed in main function !! (using pointer)
 * 
 * But since the instructions don't say anything about printing 
 * inside the function, i also added the code to print the repeated
 * letters in each word. 
 * IF YOU DON'T WANT THE FUNCTION TO PRINT REPEATED LETTERS FOR EACH WORD:
 * PLEASE DELETE THE LINES 89 TO 99. THE FUNCTION WILL STILL WORK FINE 
 * 
 * How it works:
 * 
 * There are 2 arrays with the size of alphabet which is 26 (index 1 is "a" and index 25 is "z" )
 * 
 * + alphabet[26] will keep the repeat frequencies of each letter (0 if used once)
 *   example: in word "abbc", a and c will be 0 but b will be 2
 * 
 * + used[26] will keep which letters are used in that word
 *   example: in word "abbc"; a, b and c will be 1 and the rest will be 0
 * 
 * -> "A" and "a" don't have the same ASCII code. So lower every character.
 * 
 * -> Look for space (' ') in a string and set the end point to it when found
 * 
 * -> Start from the beginning of the word and scan until the space.
 *    Use 2 loops. Outside loop will keep a letter while the inside loop
 *    starts from the right of that letter and looks for the same letter.
 * 
 * -> If a repeated letter is found and it is not used before, it will update the frequency array.
 *    And it will update the used[] array since the letter will be used before
 */

void findRepeatingLetters(string sentence, string* maxWord){
    cout << endl;
    sentence = sentence + ' '; //add space to end in order for our loop to work properly
    int length = sentence.size();
    int start = 0; //will keep the each starting index of the words
    int currentCounter = 0, maxCounter = 0;
    string currentWord;

    //since A != a in terms of code, we need to lower every letter:
    for(int i = 0; i < length; i++){sentence[i] = tolower(sentence[i]);}

    for(int i = 0; i < length; i++){ //loop to find space
        if(sentence[i] == ' '){ //finding a space means there is a word behind
            //reset current values:
            int alphabet[26] = {0}; //will store repetitions of letters
            int used[26] = {0}; //will be 1 if the letter used in the word
            currentCounter = 0;
            currentWord = "";

            //loop through word:
            for(int j = start; j < i; j++){ 
                currentWord += sentence[j]; //fill the currentWord with current letters
                for(int k = j + 1; k < i; k++){ //this loop starts from the right of previous letter
                    if(sentence[k] == sentence [j]){
                        if(used[sentence[k] - 97] == 0){ //if the letter never used in a word before
                            alphabet[sentence[k] - 97]++; //raise it's value
                        }
                    }
                    if(k == i - 1){used[sentence[j] - 97] = 1;} //turn the used letter into 1
                }
                
            }
            start = i + 1; //move the starting point right next to space

            //add the original letter to repeated ones (+1):
            for(int x = 0; x < 26; x++){
                if(alphabet[x] > 0){alphabet[x]++;}
            }

            //count the number of repeated letters:
            for(int x = 0; x < 26; x++){
                currentCounter += alphabet[x];
            }

            //if a higher repetition found:
            if(currentCounter > maxCounter){ 
                //update max values:
                maxCounter = currentCounter;
                *maxWord = currentWord;
            }

            //print each word and the repeated letters:
            int flag = 0;
            cout << currentWord << ": ";
            for(int x = 0; x < 26; x++){
                if(alphabet[x] > 0){
                    cout << (char)(x + 97) << " repeats " << alphabet[x] << " times. ";
                    flag = 1; //put a flag if there is a repeated letter
                }
            }
            if(flag == 0){cout << "-";}
            cout << endl;
            
        }
    }
    cout << endl;
}

int main(){
    string sentence, maxWord;
    cout << "Please enter the string: ";
    getline(cin, sentence);
    findRepeatingLetters(sentence, &maxWord);
    cout << "The word \"" << maxWord << "\" has the highest number of repeated letters." 
        << "\n(If there is more than 1 word with the same maximum repeated letter count, this code will output the first one.)\n" << endl; 

    system("pause");
    return 0;
}
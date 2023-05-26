#include <iostream>
#include <list>
#include <iterator>
using namespace std;

bool checkPalindrome(string str){
    list<char> myList;

    // fill the list with string's letters:
    int len = str.length();
    for(int i = 0; i < len; i++){
        myList.push_back(str[i]);
    }

    int size = myList.size();
    int counter;

    // set the iterator's counter depending on the size is even or odd
    if(size % 2 == 0){
        counter = size / 2;
    }
    else{
        counter = (size + 1) / 2;
    }

    for(int i = 0; i < counter; i++){
        if(myList.size() == 1){ // break if only one element left in list
            break;
        }
        else if(myList.front() != myList.back()){ // check if begin and end the same
            return false;
        }
        else{ // keep deleting elements from beginning and end
            myList.pop_back();
            myList.pop_front();
        }
    }
    return true;
}

int main(){
    string str01 = "tenet";
    string str02 = "test";
    string str03 = "rotator";
    
    cout << "str01 Palindrome: " << checkPalindrome(str01) << endl;
    cout << "str02 Palindrome: " << checkPalindrome(str02) << endl;
    cout << "str03 Palindrome: " << checkPalindrome(str03) << endl;

    system("pause");
    return 0;
}
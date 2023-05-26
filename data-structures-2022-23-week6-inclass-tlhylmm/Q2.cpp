#include <iostream>
#include <list>
#include <iterator>
using namespace std;

bool checkPalindrome(list<int> myList){
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
    list<int> myList1 = {1, 2, 3, 4, 4, 3, 2, 1}; //palindrome
    list<int> myList2 = {1, 2, 3, 4, 5, 4, 3, 2, 1}; //palindrome
    list<int> myList3 = {1, 6, 5, 6, 2, 1, 3, 5}; //not a palindrome

    cout << "myList1 Palindrome: " << checkPalindrome(myList1) << endl;
    cout << "myList2 Palindrome: " << checkPalindrome(myList2) << endl;
    cout << "myList3 Palindrome: " << checkPalindrome(myList3) << endl;

    return 0;
}

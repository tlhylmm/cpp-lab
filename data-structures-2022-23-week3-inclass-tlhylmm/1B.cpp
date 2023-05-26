#include <iostream>
using namespace std;

// for number = n, our function's while loop will work n times
// e.g: for number = 5, our loop will start from 5 and add the current number
// to the sum while decrementing the number until it reaches 0
// our function's repeating calculation is dependent on the given number
// so the complexity is O(n)

int sumFunc(int num){
    int sum = 0;
    while(num > 0){
        sum += num;        
        num--;
    }
    return sum;
}

int main(){
    int num;
    cout << "Enter the number of consecutive positive integers (starting from 1): ";
    cin >> num;

    cout << "The sum is: " << sumFunc(num);

    return 0;
}
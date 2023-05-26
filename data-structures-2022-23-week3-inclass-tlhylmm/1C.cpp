#include <iostream>
using namespace std;

// for number = n, our function's do-while loop will work n times
// e.g: for number = 3, our loop will start from 3 and add the current number
// to the sum while decrementing the number until it reaches 0
// our function's repeating calculation is dependent on the given number
// so the complexity is O(n)

int sumFunc(int num){
    int sum = 0;
    do{
        sum += num;
        num--;
    }
    while(num > 0);
    return sum;
}

int main(){
    int num;
    cout << "Enter the number of consecutive positive integers (starting from 1): ";
    cin >> num;

    cout << "The sum is: " << sumFunc(num);

    return 0;
}
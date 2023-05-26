#include <iostream>
using namespace std;

// our function will be called n times (from n to 1)
// so the complexity is O(n)

int factorial(int num){
    if (num == 1){
        return num;
    }
    return num * factorial(num - 1);
}

int main(){
    int num;
    cout << "Input a number: ";
    cin >> num;
    cout << "The factorial of " << num << " is: " << factorial(num);
    return 0;
}
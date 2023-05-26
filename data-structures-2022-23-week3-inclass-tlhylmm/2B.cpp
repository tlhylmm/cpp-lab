#include <iostream>
using namespace std;

// our function will be called n times (from n to 1)
// so the complexity is O(n)

int sumFunc(int n){
    if (n == 1){
        return n;
    }
    return n + sumFunc(n - 1);
}

int main(){
    int n = 5;  // change the number "n" from here
    cout << "The sum of numbers from 1 to " << n << ": " << sumFunc(n);
    return 0;
}
#include <iostream>
using namespace std;

// for number n, function will be called n times (from n to 1)
// our complexity is O(n)

int fibonacci(int i){
    if ((i == 1) || (i == 0)){
        return i;
    }
    return (fibonacci(i - 1) + fibonacci(i - 2));
}

int main(){
    int counter;
    cout << "Enter the number of terms of series: ";
    cin >> counter;
    for (int i = 0; i < counter; i++){
        cout << fibonacci(i) << " ";
    }
    return 0;
}
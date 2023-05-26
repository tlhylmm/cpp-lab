#include <iostream>

using namespace std;

void factorial(int *n, int *r){ //function takes the values of addresses
    for(int i = 1; i <= *n; i++){
        *r = *r * i; //modifying the value at the address of r
    }
}

int main()
{
    int n, r;
    r = 1; //initial value of result is one
    cout << "Enter the number: ";
    cin >> n;
    factorial(&n,&r); //sending addresses to function in order to modify it
    cout << "Factorial of " << n << " is: " << r << endl;
    system("pause");
}




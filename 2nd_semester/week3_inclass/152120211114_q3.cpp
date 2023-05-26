#include <iostream>

using namespace std;
void swapper(int *value1, int *value2){
    int temp; //temp variable to store temporarily while swapping
    temp = *value1; //temp gets the value of first address 
    *value1 = *value2; //value1 swaps values with value2
    *value2 = temp; //value2 gets the first number
}


int main()
{
    int a, b;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;
    cout << endl;
    swapper(&a,&b); //passing the addresses to function
    cout << "First number: " << a << endl;
    cout << "Second number: " << b << endl;
    system("pause");
}
#include <iostream>

using namespace std;

int main()
{
    int m = 29;
    int *ab = &m;
    cout << "Now ab is assigned with the address of m" << endl;
    cout << "Address of pointer ab: " << ab << endl;
    cout << "Content of pointer ab: " << *ab << endl;
    m = 34;
    cout << "\nThe value m is assigned to " << m << " now" << endl;
    cout << "Address of pointer ab: " << ab << endl;
    cout << "Content of pointer ab: " << *ab << endl;
    *ab = 7;
    cout << "\nThe pointer variable ab is assigned with the value " << *ab << " now" << endl;
    cout << "Address of m: " << &m << endl;
    cout << "Value of m: " << m << endl;
    
    system("pause");
}
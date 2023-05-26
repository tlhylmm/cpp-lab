#include <iostream>

using namespace std;

int main()
{
    int a, b;
    int* ptrA = &a, * ptrB = &b;
    cout << "Please enter integer a: ";
    cin >> a;
    cout << "Please enter integer b: ";
    cin >> b;
    cout << endl;
	cout << "Value of a: " << a << endl;
	cout << "Value of b: " << b << endl;
    cout << "ptrA stores the value of a = " << *ptrA << endl;
    cout << "ptrB stores the value of b = " << *ptrB << endl;
    cout << endl;
    system("pause");
}
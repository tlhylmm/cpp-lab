#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int *p = &a;
    int **pp = &p;
    cout << "address of a: " << &a << endl;
    cout << "address of p: " << &p << endl;
    cout << "address of pp: " << &pp << endl;
    cout << "\nvalue stored at a: " << a << endl;
    cout << "value stored at p: " << p << endl;
    cout << "value stored at pp: " << pp << endl;
    cout << "\na reference to: " << a << endl;
    cout << "p reference to: " << *p << endl;
    cout << "pp reference to: " << **pp << endl;
    
    system("pause");
}




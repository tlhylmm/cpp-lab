#include <iostream>

using namespace std;

int main()
{
    int a = 10, b, o;
    int* z = &a;
    cout << "z stores the address of a = " << z << endl;
    cout << "*z stores the value of a = " << *z << endl;
    cout << "&a is the address of a = " << &a << endl;
    cout << "&b stores the address of b = " << &b << endl;
    cout << "&o stores the address of o = " << &o << endl;
    cout << "&z stores the address of z = " << &z << endl;
    cout << endl;

    system("pause");
}
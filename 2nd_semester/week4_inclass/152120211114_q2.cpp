#include <iostream>
#include <iomanip> //to import setprecision function
using namespace std;

int main()
{
    int m = 300;
    float fx = 300.600006; //setprecision(6) is used to determine the number of decimal digits 
    char cht = 'z';
    int* pm = &m;
    float* pfx = &fx;
    char* pcht = &cht;
    cout << "Using & operator:" << endl;
    cout << "------------------------------" << endl;
    cout << "address of m = " << &m << endl;
    cout << "address of fx = " << &fx << endl;
    cout << "address of cht = " << (void*)&cht << endl;
    cout << "\nUsing & and * operator:" << endl;
    cout << "------------------------------" << endl;
    cout << "value at the address of m = " << *&m << endl;
    cout << "value at the address of fx = " << *&fx << fixed << setprecision(6) << endl; 
    cout << "value at the address of cht = " << *&cht << endl;
    cout << "\nUsing only pointer variable:" << endl;
    cout << "------------------------------" << endl;
    cout << "address of m = " << pm << endl;
    cout << "address of fx = " << pfx << endl;
    cout << "address of cht = " << (void*)pcht << endl;
    cout << "\nUsing only pointer operator:" << endl;
    cout << "------------------------------" << endl;
    cout << "value at the address of m = " << *pm << endl;
    cout << "value at the address of fx = " << *pfx << setprecision(6) << endl;
    cout << "value at the address of cht = " << *pcht << endl;

    system("pause");
}




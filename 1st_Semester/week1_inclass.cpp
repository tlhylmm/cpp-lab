#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    cout.fixed;
    cout.precision(41);
    double xn, n;
    cout << "Please enter n value: ";
    cin >> n;
    xn = pow(1 + (1 / n), n);
    cout << "Final value: " << xn << "\n";


    system("pause");
}

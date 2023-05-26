#include <iostream>

using namespace std;
//since the problem says both x and y is dependent on each other. and not just
//y is dependent on x. we need to point both integers to a single value so that
//they can change both.
int main()
{
    int temp = 100, z = 100;
    int *x = &temp, *y = &temp; //both x and y will change if temp will change
    cout << "Value of x: " << *x << endl;
    cout << "Value of y: " << *y << endl;
    cout << "Value of z: " << z << endl;
    temp = 50; //changing both x and y
    cout << endl;
    cout << "New value of x: " << *x << endl;
    cout << "New value of y: " << *y << endl;
    cout << "New value of z: " << z << endl;

    system("pause");
}

/* if y is dependent on x, the code below should also work:

#include <iostream>

using namespace std;
int main()
{
    int x = 100, z = 100;
    int *y = &x;
    cout << "Value of x: " << x << endl;
    cout << "Value of y: " << *y << endl;
    cout << "Value of z: " << z << endl;
    x = 50; //changing both x and y
    cout << endl;
    cout << "New value of x: " << x << endl;
    cout << "New value of y: " << *y << endl;
    cout << "New value of z: " << z << endl;

    system("pause");
}

*/
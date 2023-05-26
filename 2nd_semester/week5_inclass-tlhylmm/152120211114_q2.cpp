#include <iostream>

using namespace std;

int main()
{
    int a[5], temp; //temp will store values before given to input
    int *p = a, *r = &a[4];
    // (p + i) in loops means (0+i)th element of the array
    for (int i = 0; i < 5; i++){
        cout << "Please enter value for element " << i + 1 << ": ";
        cin >> temp; //storing values in a temp variable
        *(p + i) = temp; //change the (0+i)th element to value of temp
    }
    cout << "Elements of array: ";
    for(int i = 0; i < 5; i++){
        cout << *(p + i) << " "; //increasing the address by 4 bytes in each loop
    }
    cout << "\nIn reverse order: ";
    for(int i = 0; i < 5; i++){
        cout << *(r - i) << " "; //decreasing the address by 4 bytes in each loop
    }
     
    system("pause");
}
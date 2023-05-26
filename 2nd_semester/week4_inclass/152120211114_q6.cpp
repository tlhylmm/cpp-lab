#include <iostream>

using namespace std;

void check(int* n, int* count) { //taking values of addresses as parameters
    while (*n >= 1) { //loop until the whole n number shifts right to the decimal point
        *n = *n / 10; //divide by 10 to shift right of the decimal point
        *count += 1; //raise the counter in every shift
    }

}

int main()
{
    int n, count = 0;
    cout << "Please enter your number to calculate the length of it: ";
    cin >> n;
    cout << "The length of " << n << " is: ";
    check(&n, &count); //sending addresses to function
    cout << count << endl;

    system("pause");
}




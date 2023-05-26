#include <iostream>

using namespace std;
void check(int* n, int* sum) { //taking values of adresses as parameters
    if (*n > *sum) { //if n is greater than sum
        *sum += *n;
        cout << "Sum = " << *sum << endl;
    }
    else { //if n is less than sum
        *sum -= *n;
        cout << "Sum = " << *sum << endl;
    }
}

int main()
{
    int n, max = 50, sum = 0;
    cout << "Max = " << max << " , Sum = " << sum << endl;
    while (sum < max) { //loop until reaching the max
        cout << "N = ";
        cin >> n;
        check(&n, &sum); //sending addresses to function
    }
    cout << "(exceeded 50)" << endl;
    cout << "End..." << endl;

    system("pause");
}
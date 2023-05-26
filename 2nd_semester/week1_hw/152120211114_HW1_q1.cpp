#include <iostream>
using namespace std;

int main() {
	cout.fixed;
	cout.precision(15);
	double a[100];
	int i;
	double result;
	a[0]=1, a[1]=1;
	for (i = 0; i < 97; i++ ) {
		a[i + 2] = a[i + 1] + a[i];
	}
	result = a[99] / a[98];
	cout << result;
}
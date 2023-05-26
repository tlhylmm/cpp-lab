#include <iostream>
using namespace std;

int main() {
	int a[12] = { 1, 2, 2, 8, 4, 4, 6, 6, 6, 8, 4, 9 };
	int i, j, length = 1, counter = 1;
	for (i = 0; i < 12; i++) {
		for (j = i + 1; j < 12; j++) {
			if (a[i] == a[j]) { //compare the current and next array item
				counter++; //raise the counter if they are the same
			}
			else { //if they are not the same
				if (length < counter) { //look if counter is bigger than the length
					length = counter; //update the length if counter is bigger
				}
				counter = 1; //reset the counter
				break;
			}
		}
	}
	cout << "Max subarray length: " << length << endl;

	system("pause");
}
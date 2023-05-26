#include <iostream>
#include <string>
using namespace std;

/* Every product has 4 properties
 * So we can make an 2D array like [number of products][4 features]
 *
 * This means element will contain (number of products)*(4) elements.
 * We can create an array with the size of that.
 * 
 * We can use pointer arithmetics to reach that element
 * using the "(row * n) + column" formula where n is the
 * number of our product, row is the total number of products
 * and column is 4 (since every product has 4 features).
 */

int main(){
    //get the number of products:
    int productNum;
    cout << "Please enter the how many product in the market: ";
    cin >> productNum;

    //declare an array in heap:
    string* product = new string[productNum * 4];

    //fill the info about products:
    for(int i = 0; i < productNum; i++){
        cout << endl;
        cout << i + 1 << ". Product:" << endl;

        cout << "Enter the name: ";
        cin >> ws; //clear input buffer
        getline(cin, *(product + (4*i) + 0) );

        cout << "Enter the brand: ";
        cin >> ws; //clear input buffer
        getline(cin, *(product + (4*i) + 1) );

        cout << "Enter the expiration date: ";
        cin >> ws; //clear input buffer
        getline(cin, *(product + (4*i) + 2) );

        cout << "Enter the price: ";
        cin >> ws; //clear input buffer
        getline(cin, *(product + (4*i) + 3) );
    }

    cout << endl;

    //print the info about products:
    for(int i = 0; i < productNum; i++){
        cout << i + 1 << ". Product ->"
            << " Name: " << *(product + (4*i) + 0)
            << " Brand: " << *(product + (4*i) + 1)
            << " Expiration Date: " << *(product + (4*i) + 2)
            << " Price: " << *(product + (4*i) + 3) << endl;      
    }

    return 0;
}
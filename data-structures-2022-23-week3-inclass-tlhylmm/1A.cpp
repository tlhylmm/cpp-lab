#include <iostream>
using namespace std;

// while counting down, each number is visited once so the complexity is O(n)

int countdown(int num){
    for(int i = num; i >= 0; i--){
        cout << i << " ";
    }
}

int main(){
    int n;
    cout << "Enter the n: ";
    cin >> n;
    countdown(n);
    return 0;
}
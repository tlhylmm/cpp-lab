#include <iostream>
using namespace std;

// our function will repeat until the given limit (50 in this case)
// repetition is depentend on the given number so the complexity is O(n)

int counter(int num){
    if (num == 51){
        return 0;
    }
    cout << num << " ";
    counter(num + 1);
}

int main(){
    counter(1);
    return 0;
}
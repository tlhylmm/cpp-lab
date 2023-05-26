#include <iostream>
#include <string>
using namespace std;

int main(){
    /* The plan is to split the string in half
     * when two odd numbers found next to each other
     * then put a '-' in between them for example:
     * number: 444413444
     * first half: 44441
     * second half: 34444
     * our new string = first half + '-' + second half 
     */ 

    string nums, firstPart, secondPart; 
    int x, y;

    //take series of numbers from user:
    cout << "Input: ";
    getline(cin, nums);

    //search for two odd numbers:
    //loop until (last - 1)th item since we will use i + 1
    int length = nums.size();
    for(int i = 0; i < length - 1; i++){
        x = nums[i] - '0'; //convert character to integer
        y = nums[i + 1] - '0'; //convert character to integer
        if(x % 2 == 1 && y % 2 == 1){
            //split the string into two parts from there:
            for(int j = 0; j <= i; j++){
                firstPart +=  nums[j];
            }
            for(int j = i + 1; j < nums.size(); j++){
                secondPart += nums[j];
            }
            //update the string with puttin a '-' between them:
            nums = firstPart + '-' + secondPart;
        }        
    }

    //print results:
    cout << "Results: " << nums << endl;



    return 0;
}
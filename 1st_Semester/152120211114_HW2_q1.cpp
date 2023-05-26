#include <iostream>

using namespace std;

void numberOfRemainingStairs(int* remainstair, int* count) { //taking values of addresses as parameters
    if (*remainstair / 5 >= 1) { //firstly, look if there are 5 stairs or not
        *remainstair -= 5; //decrease the remaining stairs by 5
        cout << "Move 5 stairs up. Remaining: " << *remainstair << endl;
        *count += 1;
    }
    else if (*remainstair / 2 >= 1) { // secondly, look if there are 2 stairs or not
        *remainstair -= 2; //decrease the remaining stairs by 2
        cout << "Move 2 stairs up. Remaining: " << *remainstair << endl;
        *count += 1;
    }
    else {
        *remainstair -= 1; //climb one by one if none of the above is present
        cout << "Move 1 stairs up. Remaining: " << *remainstair << endl;
        *count += 1;
    }
}

int main()
{
    int N = 18, remainstair, count = 0; //N is the number of total stairs
    remainstair = N; //remaining stairs are equal to N in the beginning
    cout << "Climbing " << N << " ladders:\n" << endl;
    while (remainstair > 0) {
        cout << "Step-" << count + 1 << " => "; //count+1 because we start from zero
        numberOfRemainingStairs(&remainstair, &count); //sending addresses to function
    }
    /*even if we printed count+1 above. In the end, "count" variable stores the
    correct number of steps. Since our function increases "count" by 1 in the end,
    we can print directly the "count" value down below: */
    cout << "\nYou reached the top of the ladder in " << count << " steps." << endl;

    system("pause");
}




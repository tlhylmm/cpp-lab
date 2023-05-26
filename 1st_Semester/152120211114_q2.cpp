#include <iostream>

using namespace std;
void calculateResult(int *ptrGrades,string *ptrResults);

int main()
{
    int grades[5];
    string results[5];
    int *ptrGrades = &grades[0]; // pointing the beginnings of arrays
    string *ptrResults = &results[0]; //
    // "i" in loops down below will be used for pointer arithmetics
    for (int i = 0; i < 5; i++){ //loop to take inputs from the user
        cout << "Please enter the grade of " << i + 1 << ". Student: ";
        cin >> *(ptrGrades + i);
    }
    cout << endl;
    calculateResult(ptrGrades, ptrResults); //calling function
    for (int i = 0; i < 5; i++){ //loop to print grades and results
		//using "i" to do pointer arithmetics
        cout << "Student " << i + 1 << ": " << *(ptrGrades + i)
            << " (" << *(ptrResults + i) << ")";  
        // conditions to FAIL or PASS
        if( *(ptrResults + i) == "FF" ){cout << "FAIL" << endl;}
        else { cout << "PASS" << endl;}
    }
    cout << endl;
    system("pause");
}

    void calculateResult(int *ptrGrades, string *ptrResults){
        for (int i = 0; i < 5; i++){
			//conditions to check marks
            if ( *(ptrGrades + i) <= 100 && *(ptrGrades + i) >= 80){ *(ptrResults + i) = "AA";}
            else if ( *(ptrGrades + i) <= 79 && *(ptrGrades + i) >= 70){ *(ptrResults + i) = "BB";}
            else if ( *(ptrGrades + i) <= 69 && *(ptrGrades + i) >= 50){ *(ptrResults + i) = "CC";}
            else { *(ptrResults + i) = "FF";}
        }
    }   



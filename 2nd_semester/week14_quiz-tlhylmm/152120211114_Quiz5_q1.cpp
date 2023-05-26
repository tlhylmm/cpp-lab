#include <iostream>
#include <string>
using namespace std;

typedef struct student{
    string name;
    string surname;
    string class_;
    string lesson1;
    string lesson2;
    string lesson3;
    string lesson4;
    string lesson5;
};

int main(){
    //define size variable and take input:
    int size;
    cout << "Please enter how many student are in the school: ";
    cin >> size;

    //declare student type array in heap
    student* array = new student[size];
    
    cout << endl;

    //fill the members for each array element:
    for(int i = 0; i < size; i++){
        cout << i + 1 << ". Student:" << endl;

        cout << "Enter the name: ";
        cin >> ws; //clear input buffer
        getline(cin, array[i].name);

        cout << "Enter the surname: ";
        cin >> ws; //clear input buffer
        getline(cin, array[i].surname);

        cout << "Enter the class: ";
        cin >> ws; //clear input buffer
        getline(cin, array[i].class_);

        cout << "Enter the lesson 1: ";
        cin >> ws; //clear input buffer
        getline(cin, array[i].lesson1);

        cout << "Enter the lesson 2: ";
        cin >> ws; //clear input buffer
        getline(cin, array[i].lesson2);

        cout << "Enter the lesson 3: ";
        cin >> ws; //clear input buffer
        getline(cin, array[i].lesson3);

        cout << "Enter the lesson 4: ";
        cin >> ws; //clear input buffer
        getline(cin, array[i].lesson4);

        cout << "Enter the lesson 5: ";
        cin >> ws; //clear input buffer
        getline(cin, array[i].lesson5);
    }

    cout << endl;

    //print the info about students:
    for(int i = 0; i < size; i++){
        cout << i + 1 << ". Student Name: " << array[i].name
            << ", Surname: " << array[i].surname
            << ", Class: " << array[i].class_ << endl;
        cout << "1. Lesson: " << array[i].lesson1 << endl;
        cout << "2. Lesson: " << array[i].lesson2 << endl;
        cout << "3. Lesson: " << array[i].lesson3 << endl;
        cout << "4. Lesson: " << array[i].lesson4 << endl;
        cout << "5. Lesson: " << array[i].lesson5 << endl;
    }

    return 0;
}
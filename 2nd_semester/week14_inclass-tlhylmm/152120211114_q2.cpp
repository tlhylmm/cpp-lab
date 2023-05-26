#include <iostream>
#include <string>
using namespace std;

typedef struct Person{
    double height;
    double salary;
    int age;
    string name;
    string surname;
    string city;
};

int main(){
    //declare Person type variable and pointer:
    Person person1;
    Person* ptr = &person1;

    //get inputs:
    // (*ptr).member can be also used instead of ptr-> member
    cout << "Enter your name: ";
    cin >> ws; //clear input buffer
    getline(cin, ptr->name);
    cout << "Enter your surname: ";
    cin >> ws; //clear input buffer
    getline(cin, ptr->surname);
    cout << "Enter your age: ";
    cin >> ws; //clear input buffer
    cin >> ptr->age;
    cout << "Enter your height: ";
    cin >> ws; //clear input buffer
    cin >> ptr->height;
    cout << "Enter your salary: ";
    cin >> ws; //clear input buffer
    cin >> ptr->salary;
    cout << "Enter your city: ";
    cin >> ws; //clear input buffer
    getline(cin, ptr->city);

    cout << endl;

    //print informations:
    cout << "Your name is: " << (*ptr).name << endl;
    cout << "Your surname is: " << (*ptr).surname << endl;
    cout << "Your age is: " << (*ptr).age << endl;
    cout << "Your height is: " << (*ptr).height << endl;
    cout << "Your salary is: " << (*ptr).salary << endl;
    cout << "Your city is: " << (*ptr).city << endl;

    return 0;
}
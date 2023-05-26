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
    //declare Person type variable:
    Person person1;

    //get inputs:
    cout << "Enter your name: ";
    cin >> ws; //clear input buffer
    getline(cin, person1.name);
    cout << "Enter your surname: ";
    cin >> ws; //clear input buffer
    getline(cin, person1.surname);
    cout << "Enter your age: ";
    cin >> ws; //clear input buffer
    cin >> person1.age;
    cout << "Enter your height: ";
    cin >> ws; //clear input buffer
    cin >> person1.height;
    cout << "Enter your salary: ";
    cin >> ws; //clear input buffer
    cin >> person1.salary;
    cout << "Enter your city: ";
    cin >> ws; //clear input buffer
    getline(cin, person1.city);

    cout << endl;

    //print informations:
    cout << "Your name is: " << person1.name << endl;
    cout << "Your surname is: " << person1.surname << endl;
    cout << "Your age is: " << person1.age << endl;
    cout << "Your height is: " << person1.height << endl;
    cout << "Your salary is: " << person1.salary << endl;
    cout << "Your city is: " << person1.city << endl;

    return 0;
}
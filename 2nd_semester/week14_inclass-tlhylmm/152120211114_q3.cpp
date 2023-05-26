#include <iostream>
#define PI 3.14
using namespace std;

typedef struct Circle{
    double radius;
    double area;
    double circumference;
};

void setCircleProperties(Circle* circle1){
    //calculate properties:
    circle1->area = PI * circle1->radius * circle1->radius;
    circle1->circumference = 2 * PI * circle1->radius;
}

int main(){
    //declare circle variable:
    Circle circle1;
    cout << "All inputs and resuls will be in centimeters." << endl;
    cout << "Enter the radius: ";
    cin >> ws; //clear input buffer
    cin >> circle1.radius;
    setCircleProperties(&circle1);

    //print results
    cout << "Radius: " << circle1.radius << endl;
    cout << "Area: " << circle1.area << endl;
    cout << "Circumference: " << circle1.circumference << endl;

    return 0;
}
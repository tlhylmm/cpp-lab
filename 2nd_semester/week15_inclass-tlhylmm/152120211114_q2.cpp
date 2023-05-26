#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    ofstream q2file;
    q2file.open("q2data.txt", ios::app);

    //fill the file with lines:
    q2file << "test line1\n"
        << "test line2\n"
        << "test line3\n"
        << "test line4\n"
        << "test line5" << endl;
    q2file.close();

    //open file in read mode:
    string line;
    ifstream q2read;
    q2read.open("q2data.txt");
    
    //count the number of lines:
    int size = 0;
    while(getline(q2read, line)){
        size++;
    }
    q2read.close();
    
    //create an array:
    string* array = new string[size];

    ifstream q2read_;
    q2read_.open("q2data.txt");

    //fill the array:
    int index = 0;
    while(getline(q2read_, line)){
        array[index] = line;
        index++;
    }

    //print the array elements:
    for(int i = 0; i < size; i++){
        cout << "Line is " << array[i] << endl;
    }

    q2read_.close();
    return 0;
}

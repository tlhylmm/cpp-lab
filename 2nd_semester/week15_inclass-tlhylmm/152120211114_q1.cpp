#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
    string name, surname;

    //create file in write, append mode:
    ofstream file;
    file.open("data.txt", ios::app);    
    
    for(int i = 0; i < 5; i++){
        //take five inputs:
        cout << "For " << i + 1 << ". Person:\n"
            << "Enter name: ";
        cin >> ws; //clear input buffer
        getline(cin, name);
        cout << "Enter surname: ";
        cin >> ws; //clear input buffer
        getline(cin, surname);

        //write into file:
        file << name << " " << surname << endl;
    }
    file.close(); //close file

    //open the file in read mode:
    ifstream readFile; 
    readFile.open("data.txt");

    //print the data:
    int i = 1;
    while(readFile >> name >> surname){
        cout << i << ". Person name is " << name << endl;
        cout << i << ". Person surname is " << surname << endl;
        i++; 
    }
    return 0;
}
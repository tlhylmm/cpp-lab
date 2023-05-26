#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct Course{
    string classID;
    string name;
    int capacity;
    int* studentID = new int[capacity];
};

int main(){
    //open file in write mode:
    ofstream q3file;
    q3file.open("Course.txt");

    q3file << "B401 Math 45 1045 1046 1047\n" 
        << "B402 OOP 85  1072 1020 1034 1032 1043" << endl;
    q3file.close();

    //open file in readmode:
    ifstream q3file_;
    q3file_.open(("Course.txt"));
    
    //count the number of courses:
    string line;
    int size = 0;
    while(getline(q3file_, line)){
        size++;
    }

    //create array:
    Course* Sources = new Course [size];


    
    string word;
    int index = 0;
    int studentIndex = 0;
    int counter = 0; //will count words in each line
    while(getline(q3file_, line)){
        stringstream ss(line); //using stream to break words
        while((ss >> word)){
            if(counter == 0){Sources[index].classID = word;}
            else if(counter == 1){Sources[index].name = word;}
            else if(counter == 2){Sources[index].capacity = stoi(word);}
            else {
                Sources[index].studentID[studentIndex] = stoi(word);
                studentIndex++;
            }
            counter++;
        }
        index++;
        counter = 0; //reset counter
    }

    //print values:
    for(int i = 0; i < size; i++){
        cout << Sources[i].classID << " "
            << Sources[i].name << " "
            << Sources[i].capacity << " ";
        for(int j = 0; j < Sources[i].capacity; j++){
            if(Sources[i].studentID[j] != 0){
                cout << Sources[i].studentID[j] << " ";
            }
            else{break;}
        }
        cout << endl;
    }
}
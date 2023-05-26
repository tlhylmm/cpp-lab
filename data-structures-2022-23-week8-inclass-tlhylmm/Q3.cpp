#include <iostream>
#include <vector>
#include <iterator>
#include <queue>
#include <algorithm> //for sorting
using namespace std;

int main(){
    queue<int> q;
    int size;
    cout << "Please Enter the number of elements : ";
    cin >> size;

    //get queue elements:
    cout << "Please enter elements in queue" << endl;
    int input;
    for(int i = 0; i < size; i++){
        cin >> input;
        q.push(input);
        cout << endl;
    }

    //original queue
    queue<int> temp01 = q;
    cout << "Original Queue" << endl;
    while(!temp01.empty()){
        cout << temp01.front() << " ";
        temp01.pop();
    }

    //fill the vector with queue elements and sort
    vector<int> v;
    while(!q.empty()){
        v.push_back(q.front());
        q.pop();
    }

    //sort
    sort(v.begin(), v.end());
    
    //fill the queue again
    for(auto j = v.begin(); j != v.end(); j++){
        q.push(*j);
    }

    //sorted queue
    cout << "\n\nSorted Queue" << endl;
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
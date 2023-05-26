#include <iostream>
#include <stack>
using namespace std;

// creating a print function to keep the elements in stack
void printStack(stack<int> st){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}
 
void sortStack(stack<int> st){
    // create another stack
    stack<int> _st;

    //iterate through st and and compare elements

    /* Take one element from the st and pop it
     * Compare the taken element with the _st's last element (While not empty).
     * If it is smaller, empty the whole _st while filling the st and push the
     * smallest element to the _st as first entry. 
     * Repeat untill all sorted (this means st will be empty)
     */

    int temp;
    while(!st.empty()){
        // take one element from st:
        temp = st.top();
        st.pop();
        // compare with the _st's last element
        while(!_st.empty() && _st.top() > temp){
            st.push(_st.top());
            _st.pop();
        }
        _st.push(temp);
    }

    // print the sorted stack
    while(!_st.empty()){
        cout << _st.top() << " ";
        _st.pop();
    }
}
 
// main function
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(15);
    st.push(5);
    st.push(30);

    // print the unsorted stack:
    cout << "Unsorted stack: " << endl;
    printStack(st);
    cout << endl;


    // print the sorted stack:
    cout << "\nSorted stack: " << endl;
    sortStack(st);
    cout << endl;

    system("pause");
    return 0;
}
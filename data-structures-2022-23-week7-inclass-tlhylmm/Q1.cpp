#include <iostream>
#include <stack>
using namespace std;

void stackPrint(stack<int> st){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void reversePrint(stack<int> st){
    // to print from first to last, another stack will be created
    // and filled with reverse order
    stack<int> _st;
    while(!st.empty()){
        _st.push(st.top());
        st.pop();
    }

    // print first to last
    while(!_st.empty()){
        cout << _st.top() << " ";
        _st.pop();
    }
    cout << "\n" << endl;
}

int main(){
    stack<int> st;

    cout << "Check stack initial state: ";
    if (st.empty()) cout << "empty" << endl;
    else cout << "not-empty" << endl;

    cout << "\nAdd elements to stack: 21 - 22 - 24 - 25" << endl;
    st.push(21);
    st.push(22);
    st.push(24);
    st.push(25);
    cout << endl;
    
    cout << "Show stack element (print first in to last in):" << endl;
    reversePrint(st);


    cout << "Show stack element (print last in to first in):" << endl;
    stackPrint(st);
    cout << endl;

    st.pop();
    st.pop();

    cout << "Delete last two elements from stack then show stack elements" 
         << " (print last in to first in)" << endl;
    stackPrint(st);

    system("pause");
    return 0;
}
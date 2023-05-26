#include <iostream>
#include <queue>
using namespace std;

class qStack {
    private:
        queue<int> st;
    public:
        void push(int i){
            //  Get previous size of queue
            int size = st.size();

            // Push the current element
            st.push(i);

            // Pop all the previous elements and put them after
            // current element

            for (int i = 0; i < size; i++) {
                // Add the front element again
                st.push(st.front());

                // Delete front element
                st.pop();
            }
        }
        void pop(){
            if (st.empty())
                cout << "Stack is empty. No elements to perform pop." << endl;
            else
                cout << "Popped " << st.front() << endl;
                st.pop();
        }
        bool empty(){
            return st.empty();
        }
        int size(){
            return st.size();
        }
        int top(){
            if(st.empty()){
                cout << "Stack is empty. No elements to return. ";
                return -1;
            }
            else{
                return st.front();
            }
        }
        void display(){
            queue<int> stack = st;
            while(!stack.empty()){
                cout << stack.front() << endl;
                stack.pop();
            }
        }
};

void menu(qStack &st){
    system("cls");
    int input;
    cout << "Stack using Queue" << endl;
    cout << "(Please select operation)" << endl;
    cout << "=========================" << endl;
    cout << "1) Empty\n"
        << "2) Size\n"
        << "3) Top\n"
        << "4) Push\n"
        << "5) Pop\n"
        << "6) Display\n"
        << "7) Exit program\n" 
        << "\nInput: ";
    cin >> input;

    //do operations according to given input
    switch(input) {
        case 1:
            cout << st.empty() << endl;
            system("pause");
            break;
        case 2:
            cout << st.size() << endl;
            system("pause");
            break;
        case 3:
            cout << st.top() << endl;
            system("pause");
            break;
        case 4:
            int i;
            cout << "Enter the number to be pushed: ";
            cin >> i;
            st.push(i);
            cout << "Pushed " << i << " succesfully." << endl;
            system("pause");
            break;
        case 5:
            st.pop();
            system("pause");
            break;
        case 6:
            st.display();
            system("pause");
            break;
        case 7:
            exit(0);
            break;
        default:
            cout << "Wrong input. Try again." << endl;
            system("pause");
            menu(st);
    }
    menu(st);
}

int main(){
    qStack st;
    menu(st);
    return 0;
}
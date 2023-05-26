#include <iostream>
#include <stack>
using namespace std;

class sQueue {
    private:
        stack<int> s;
    public:
        void enqueue(int i)
        {
            s.push(i);
        }    
        // Dequeue an item from the queue
        int dequeue()
        {
            if (s.empty()) {
                cout << "Queue is empty. No elements to dequeue " << endl;
                return -1;
            }
    
            // pop an item from the stack
            int x = s.top();
            s.pop();
    
            // if stack becomes empty, return
            // the popped item
            if (s.empty())
                return x;
    
            // recursive call
            int item = dequeue();
    
            // push popped item back to the stack
            s.push(x);
    
            // return the result of deQueue() call
            return item;
        }
        bool empty(){
            return s.empty();
        }
        int size(){
            return s.size();
        }
        int front(){
             if(s.empty()){
                cout << "Queue is empty. No elements to return. ";
                return -1;
            }
            else{
                stack<int> _s = s;
                stack<int> display;
                while(!_s.empty()){
                    display.push(_s.top());
                    _s.pop();
                }
                return display.top();
            }
        }
        void display(){
            stack<int> _s = s;
            stack<int> display;
            while(!_s.empty()){
                display.push(_s.top());
                _s.pop();
            }
            while(!display.empty()){
                cout << display.top() << endl;
                display.pop();
            }
        }
};

void menu(sQueue &q){
    system("cls");
    int input;
    cout << "Queue using Stack" << endl;
    cout << "(Please select operation)" << endl;
    cout << "=========================" << endl;
    cout << "1) Empty\n"
        << "2) Size\n"
        << "3) Front\n"
        << "4) Enqueue\n"
        << "5) Dequeue\n"
        << "6) Display\n"
        << "7) Exit program\n" 
        << "\nInput: ";
    cin >> input;

    //do operations according to given input
    switch(input) {
        case 1:
            cout << q.empty() << endl;
            system("pause");
            break;
        case 2:
            cout << q.size() << endl;
            system("pause");
            break;
        case 3:
            cout << q.front() << endl;
            system("pause");
            break;
        case 4:
            int i;
            cout << "Enter the number to be pushed: ";
            cin >> i;
            q.enqueue(i);
            cout << "Pushed " << i << " succesfully." << endl;
            system("pause");
            break;
        case 5:
            q.dequeue();
            system("pause");
            break;
        case 6:
            q.display();
            system("pause");
            break;
        case 7:
            exit(0);
            break;
        default:
            cout << "Wrong input. Try again." << endl;
            system("pause");
            menu(q);
    }
    menu(q);
}

int main(){
    sQueue q;
    menu(q);
    return 0;
}
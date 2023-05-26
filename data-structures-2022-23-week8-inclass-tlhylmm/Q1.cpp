#include <iostream>
#include <queue>
#define QUEUE_SIZE 5 //change the queue size here
using namespace std;

//prototypes
void enqueue();
void dequeue();
bool isEmpty();
bool isFull();
int count();
void display(queue<int>);
void clear();

queue<int> q;
int itemCount = 0;

int main(){
    int input;
    while(true){
        cout << "What Operation Do You Want to Perform?"
            << " Select Option Number. Enter 0 to Exit.\n"
            << "1. Enqueue()\n" 
            << "2. Dequeue()\n"  
            << "3. IsEmpty()\n"  
            << "4. IsFull()\n"  
            << "5. Count()\n" 
            << "6. Display()\n" 
            << "7. Clear Screen\n\n";

        cin >> input;
        cout << endl;
        switch (input){
            case 0:
                exit(0);
            case 1: 
                enqueue();
                cout << "\n" << endl;
                break;
            case 2:
                dequeue();
                cout << "\n" << endl;
                break;
            case 3:
                if(isEmpty()) cout << "Queue is empty" << endl;
                else cout << "Queue is not empty" << endl;
                cout << "\n" << endl;
                break;
            case 4:
                if(isFull()) cout << "Queue is full" << endl;
                else cout << "Queue is not full" << endl;
                cout << "\n" << endl;
                break;
            case 5:
                cout << "Counted elements: " << count();
                cout << "\n" << endl;
                break;
            case 6:
                display(q);
                cout << "\n" << endl;
                break;
            case 7:
                clear();
                break;
            default:
                cout << "Wrong entry. Try again.";
                cin >> input;
        }
    }
    return 0;
}

void enqueue(){
    cout << "Enqueue operation" << endl;
    if(isFull()){
        cout << "Queue is already full, can't enqueue any item.";
        system("pause");
    }
    else{
        cout << "Enter an item to Enqueue in the Queue" << endl;
        int num;
        cin >> num;
        q.push(num);
        itemCount++;
    }
}

void dequeue(){
    if(isEmpty()){
        cout << "Queue is empty. Nothing to dequeue." << endl;
        system("pause");
    }
    else{
        cout << "Dequeue operation" << endl;
        q.pop();
        itemCount--;
    }
}

bool isEmpty(){
    return itemCount == 0;
}

bool isFull(){
    return itemCount == QUEUE_SIZE;
}

int count(){
    return q.size();
}

void display(queue<int> myQ){
    while(!myQ.empty()){
        cout << myQ.front() << endl;
        myQ.pop();
    }
}

void clear(){
    system("cls");
}
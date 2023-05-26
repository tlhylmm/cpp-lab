#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void orderUnion(list<int> list1, list<int> list2){
    list<int>::iterator i = list1.begin();
    list<int>::iterator j = list2.begin();
    list<int> result;

    while(i != list1.end()){
        while(j != list2.end()){
            if(*i < *j){
                result.push_back(*i);
                i++;
            }
            else if(*j < *i){
                result.push_back(*j);
                j++;
            }
            else if (*i == *j){
                result.push_back(*j);
                i++;
                j++;
            }

            //break when reached the end of any list:
            if(i == list1.end()){
                break;
            }
            if(j == list2.end()){
                break;
            }
        }
        //if reached end of any list add the other list directly to result
        if(i == list1.end()){
            while(j != list2.end()){
                result.push_back(*j);
                j++;
            }
            break;
        }
        if(j == list2.end()){
            while(i != list1.end()){
                result.push_back(*i);
                i++;
            }
            break;
        }
    }

    // print the result
    for(auto itr = result.begin(); itr != result.end(); itr++){
        cout << *itr << endl;
    }
}

int main(){
    list<int> list1 = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    list<int> list2 = {0, 3, 6, 9, 12};

    list1.sort();
    list2.sort();

    orderUnion(list1, list2);




    return 0;
}
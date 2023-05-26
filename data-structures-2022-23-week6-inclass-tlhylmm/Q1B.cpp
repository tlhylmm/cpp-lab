#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

void orderUnion(vector<int> vector1, vector<int> vector2){
    vector<int>::iterator i = vector1.begin();
    vector<int>::iterator j = vector2.begin();
    vector<int> result;

    while(i != vector1.end()){
        while(j != vector2.end()){
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
            if(i == vector1.end()){
                break;
            }
            if(j == vector2.end()){
                break;
            }
        }
        //if reached end of any list add the other list directly to result
        if(i == vector1.end()){
            while(j != vector2.end()){
                result.push_back(*j);
                j++;
            }
            break;
        }
        if(j == vector2.end()){
            while(i != vector1.end()){
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
    vector<int> vector1 = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    vector<int> vector2 {0, 3, 6, 9, 12};

    sort(vector1.begin(), vector1.end());
    sort(vector2.begin(), vector2.end());

    orderUnion(vector1, vector2);

    return 0;
}
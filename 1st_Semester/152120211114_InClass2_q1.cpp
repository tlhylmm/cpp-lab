#include <iostream>
using namespace std;
#define direction 1//1 is left and 2 is right
#define N 2//how many times it will be shifted

int main()
{
    
    int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int temp[N], x = N, y = 0; //temporary numbers and arrays
    if( direction == 1 ){
        for(int i = 0; i < N; i++){
            temp[i] = a[i];
        }
        for(int i = N; i < 9; i++){
            a[x-2] = a[x];
            x++;
        }
        for(int i = 9 - N; i < 9; i++){
            a[i] = temp[y];
            y++;
        }
        for(int i = 0; i < 9; i++){
            cout << a[i] << " ";
        }
    }
    if( direction == 2){
    }
    system("pause");
}
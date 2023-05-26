#include <iostream>

using namespace std;

int main()
{
    int arrInteger[5] = {1, 2, 3, 4, 5};
    char arrChar[5] = {'a', 'b', 'c', 'd', 'e'};
    double arrDouble[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int *pint = arrInteger;
    char *pchar = arrChar; 
    double *pdouble = arrDouble;
    cout << "Using Integer Array => arrInteger(1,2,3,4,5)" << endl;
    for(int i = 0; i < 5; i++){
        printf("arrInteger => %d.th value : %d  address : %p\n", i, arrInteger[i], &arrInteger[i]);
    }
    cout << "\nUsing Integer Pointer" << endl;
    for(int i = 0; i < 5; i++){
        printf("arrInteger => %d.th value : %d  address : %p\n", i, *pint + i, pint + i); // pint + i means (0+i)th element of array
                                                                                          // increasing the address by 4 byte in each loop
    }
    cout << "\nUsing Char Array => arrChar(a,b,c,d,e)" << endl;
    for(int i = 0; i < 5; i++){
        printf("arrChar => %d.th value : %c  address : %p\n", i, arrChar[i], &arrChar[i]);
    }
    cout << "\nUsing Char Pointer" << endl;
    for(int i = 0; i < 5; i++){
        printf("arrChar => %d.th value : %c  address : %p\n", i, *pchar + i, pchar + i);// pchar + i means (0+i)th element of array
                                                                                        // increasing the address by 1 byte in each loop
    }
    cout << "\nUsing Double Array => arrChar(1.1, 2.2, 3.3, 4.4, 5.5)" << endl;
    for(int i = 0; i < 5; i++){
        printf("arrDouble => %d.th value : %f  address : %p\n", i, arrDouble[i], &arrDouble[i]);
    }    
    cout << "\nUsing Double Pointer" << endl;
    for(int i = 0; i < 5; i++){
        printf("arrDouble => %d.th value : %f  address : %p\n", i, *(pdouble + i), pdouble + i);// pdouble + i means (0+i)th element of array
                                                                                              // increasing the address by 8 byte in each loop
    }    
    
    system("pause");
}
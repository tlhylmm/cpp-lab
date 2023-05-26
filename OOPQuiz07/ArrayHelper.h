#pragma once
#include <iostream>
using namespace std;

template <typename T>

class ArrayHelper{
    public:
        ArrayHelper(){}
        void Display(T* array, int size,
                    int numberOfElementsInOneLine, int oneElementLength){
                for(int i = 0; i < size; i++){
                        cout << array[i] << " ";
                        //go to new line
                        if(i % numberOfElementsInOneLine = numberOfElementsInOneLine - 1)
                                cout << endl;
                }

        }
        int MaxIndex(T* array, int size){}
        T* Merge(T* firstArray, int firstArraySize,
                T* secondArray, int secondArraySize){}
        int MinIndex(T* array, int size){}
        void Sort(T* array, int size){}
        void Swap(t& operand1, T& operand2){}
        ~ArrayHelper(){}
};
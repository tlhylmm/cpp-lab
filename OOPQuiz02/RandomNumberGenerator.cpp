/// RandomNumberGenerator.cpp  
#include "RandomNumberGenerator.h"  
#include <time.h>  
#include <iostream>  
using namespace std; 
RandomNumberGenerator::RandomNumberGenerator()  
{  
srand(time(NULL));  
}  
RandomNumberGenerator::~RandomNumberGenerator()  
{  
}  
int RandomNumberGenerator::getRandomInteger(int lowerBound, int upperBound)  
{  
    return ( rand()%(upperBound-lowerBound + 1) + lowerBound );  
}  
float RandomNumberGenerator::getRandomFloat(float lowerBound, float upperBound, 
Precision precision)  
{  
    int _lowerBound = 0;
    int _upperBound = 0;
    float _finalNumber = 0; 
    float finalNumber = 0; 
    switch (precision){
        case ONE:
            _lowerBound = lowerBound*10;
            _upperBound = upperBound*10;
            _finalNumber = (rand()%(_upperBound-_lowerBound + 1) + _lowerBound);
            finalNumber = (_finalNumber / 10); 
            return (finalNumber);
            break;
        case TWO:
            _lowerBound = lowerBound*100;
            _finalNumber = (rand()%(_upperBound-_lowerBound + 1) + _lowerBound);
            finalNumber = (_finalNumber / 100); 
            return (finalNumber);
            break;
        case THREE:
            _lowerBound = lowerBound*1000;
            _upperBound = upperBound*1000;
            _finalNumber = (rand()%(_upperBound-_lowerBound + 1) + _lowerBound);
            finalNumber = (_finalNumber / 1000);
            return (finalNumber);
            break;
        case FOUR:
            _lowerBound = lowerBound*10000;
            _upperBound = upperBound*10000;
            _finalNumber = (rand()%(_upperBound-_lowerBound + 1) + _lowerBound);
            finalNumber = (_finalNumber / 10000);
            return (finalNumber);
            break;
    }

}  
double RandomNumberGenerator::getRandomDouble(double lowerBound, double upperBound, 
Precision precision)  
{
    int _lowerBound = 0;
    int _upperBound = 0;
    double _finalNumber = 0;
    double finalNumber = 0;
    switch (precision){
        case ONE:
            _lowerBound = lowerBound*10;
            _upperBound = upperBound*10;
            _finalNumber = (rand()%(_upperBound-_lowerBound + 1) + _lowerBound);
            finalNumber = (_finalNumber / 10);
            return (finalNumber);
            break;
        case TWO:
            _lowerBound = lowerBound*100;
            _upperBound = upperBound*100;
            _finalNumber = (rand()%(_upperBound-_lowerBound + 1) + _lowerBound);
            finalNumber = (_finalNumber / 100);
            return (finalNumber);
            break;
        case THREE:
            _lowerBound = lowerBound*1000;
            _upperBound = upperBound*1000;
            _finalNumber = (rand()%(_upperBound-_lowerBound + 1) + _lowerBound);
            finalNumber = (_finalNumber / 1000);
            return (finalNumber);
            break;
        case FOUR:
            _lowerBound = lowerBound*10000;
            _upperBound = upperBound*10000;
            _finalNumber = (rand()%(_upperBound-_lowerBound + 1) + _lowerBound);
            finalNumber = (_finalNumber / 10000);
            return (finalNumber);
            break;
    }
}
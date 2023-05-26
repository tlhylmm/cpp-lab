/// RandomNumberGeneratorTestMain.cpp  
#include <iostream>  
#include "RandomNumberGenerator.h"  
using namespace std;  
/// <summary>  
/// Random Integer Test  
/// </summary>  
/// <param name="generator">The generator.</param>  
/// <param name="lowerBound">The lower bound.</param>  
/// <param name="upperBound">The upper bound.</param>  
void TEST_RandomInteger(RandomNumberGenerator& generator, int lowerBound, int 
upperBound)  
{ 
 int randomNumber = generator.getRandomInteger(lowerBound, upperBound);  
if (randomNumber >= lowerBound && randomNumber <= upperBound)  
{
cout << "SUCCESS : " << randomNumber << endl;  
}  
else  
{ 
cout << "FAILURE : Obtained number is not between the range [" << lowerBound << "," << upperBound << 
"]" << endl; 
} 
} 
 
/// <summary>  
/// Random Float Test  
/// </summary>  
/// <param name="generator">The generator.</param>  
/// <param name="lowerBound">The lower bound.</param>  
/// <param name="upperBound">The upper bound.</param>  
/// <param name="precision">The precision.</param>  
void TEST_RandomFloat(RandomNumberGenerator& generator, float lowerBound, float 
upperBound, RandomNumberGenerator::Precision precision)  
{  
float randomNumber = generator.getRandomFloat(lowerBound, upperBound, precision);  
if (randomNumber >= lowerBound && randomNumber <= upperBound)  
{
cout << "SUCCESS : " << randomNumber << endl;  
}  
else  
{ 
cout << "FAILURE : Obtained number is not between the range [" << lowerBound << "," << upperBound << 
"]" << endl; 
}   





} 
/// <summary>  
/// Random Double Test  
/// </summary>  
/// <param name="generator">The generator.</param>  
/// <param name="lowerBound">The lower bound.</param>  
/// <param name="upperBound">The upper bound.</param>  
/// <param name="precision">The precision.</param>  
void TEST_RandomDouble(RandomNumberGenerator& generator, double lowerBound, double 
upperBound, RandomNumberGenerator::Precision precision)  
{  
    double randomNumber = generator.getRandomDouble(lowerBound, upperBound, precision);  
if (randomNumber >= lowerBound && randomNumber <= upperBound)  
{
cout << "SUCCESS : " << randomNumber << endl;  
}  
else  
{ 
cout << "FAILURE : Obtained number is not between the range [" << lowerBound << "," << upperBound << 
"]" << endl; 
}   








}  
/// <summary>  
/// Main Function  
/// </summary>  
/// <returns></returns>  
int main()  
{ 
 RandomNumberGenerator generator;  
cout << "+---------------------+" << endl  
<< "| Random Integer Test |" << endl  
<< "+---------------------+" << endl;  
TEST_RandomInteger(generator,5,20);  
TEST_RandomInteger(generator, 2, 60);  
cout <<"+-------------------+" << endl  
<< "| Randon Float Test |" << endl  
<< "+-------------------+" << endl;  
TEST_RandomFloat(generator, 5, 20, RandomNumberGenerator::Precision::ONE);  
TEST_RandomFloat(generator, 5, 20, RandomNumberGenerator::Precision::TWO);  
TEST_RandomFloat(generator, 5, 20, RandomNumberGenerator::Precision::THREE);  
TEST_RandomFloat(generator, 5, 20, RandomNumberGenerator::Precision::FOUR); 
cout << "+--------------------+" << endl  
<< "| Randon Double Test |" << endl  
<< "+--------------------+" << endl;  
TEST_RandomDouble(generator, 5, 20, RandomNumberGenerator::Precision::ONE);
TEST_RandomDouble(generator, 5, 20, RandomNumberGenerator::Precision::TWO);  
TEST_RandomDouble(generator, 5, 20, RandomNumberGenerator::Precision::THREE);  
TEST_RandomDouble(generator, 5, 20, RandomNumberGenerator::Precision::FOUR); 
} 
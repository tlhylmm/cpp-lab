/// RandomNumberGenerator.h  
#pragma once  
class RandomNumberGenerator  
{  
public:  
/// <summary>  
/// Precision of a float or double number  
/// ONE : one digit after point  
/// TWO : two digit after point  
/// THREE : three digit after point  
/// FOUT : four digit after point  
/// </summary>  
enum Precision  
{  
/// <summary>  
/// The one  
/// </summary>  
ONE,  
/// <summary>  
/// The two  
/// </summary>  
TWO, 
/// <summary>  
/// The three  
/// </summary>  
THREE,  
/// <summary>  
/// The four  
/// </summary>  
FOUR  
}; 
/// <summary>  
/// Initializes a new instance of the <see cref="RandomNumberGenerator"/> class.  
/// </summary>  
RandomNumberGenerator();  
/// <summary>  
/// Finalizes an instance of the <see cref="RandomNumberGenerator"/> class.  
/// </summary>  
virtual ~RandomNumberGenerator();  
/// <summary>  
/// Gets the random integer.  
/// </summary>  
/// <param name="lowerBound">The lower bound.</param>  
/// <param name="upperBound">The upper bound.</param>  
/// <returns></returns>  
int getRandomInteger(int lowerBound, int upperBound);  
/// <summary>  
/// Gets the random float.  
/// </summary>  
/// <param name="lowerBound">The lower bound.</param>  
/// <param name="upperBound">The upper bound.</param>  
/// <param name="precision">The precision.</param>  
/// <returns></returns>  
float getRandomFloat(float lowerBound, float upperBound, Precision precision);  
/// <summary>  
/// Gets the random double.  
/// </summary>
/// <param name="lowerBound">The lower bound.</param>  
/// <param name="upperBound">The upper bound.</param>  
/// <param name="precision">The precision.</param>  
/// <returns></returns>  
double getRandomDouble(double lowerBound, double upperBound, Precision 
precision);  
};

//=========================================================================
//=========================================================================
//=========================================================================
//=========================================================================


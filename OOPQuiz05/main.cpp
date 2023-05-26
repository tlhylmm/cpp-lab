#include <iostream>
#include "Vector.h"

using namespace std;

void TEST_Input(Vector* vector)
{
	cout << "+------------+" << endl
		<< "| INPUT TEST |" << endl
		<< "+------------+" << endl;
	cin >> *vector;
}
void TEST_Output(Vector* vector)
{
	cout << "+-------------+" << endl
		<< "| OUTPUT TEST |" << endl
		<< "+-------------+" << endl;
	cout << (*vector) << endl;
}
void TEST_CopyConstructor(Vector* vector)
{
	cout << "+-----------------------+" << endl
		<< "| COPY CONSTRUCTOR TEST |" << endl
		<< "+-----------------------+" << endl;
	Vector copy_vector(*vector);
	cout << "Original Vector : " << *vector << endl << "Copy Vector : " << copy_vector
		<< endl;
}
void TEST_Assignment(Vector* vector)
{
	cout << "+-----------------+" << endl
		<< "| ASSIGNMENT TEST |" << endl
		<< "+-----------------+" << endl;
	cout << "Original Vector: " << (*vector) << endl;
	Vector copy = (*vector);
	cout << "Assignment Copy Vector: " << copy << endl;
}
void TEST_Equal(Vector* vector1, Vector* vector2)
{
	cout << "+------------+" << endl
		<< "| EQUAL TEST |" << endl
		<< "+------------+" << endl;
	if (*vector1 == *vector2) {
		cout << *vector1 << " is equal to " << *vector2 << endl;
	}
	else {
		cout << *vector1 << " is not equal to " << *vector2 << endl;
	}
}
void TEST_Not_Equal(Vector* vector1, Vector* vector2)
{
	cout << "+----------------+" << endl
		<< "| NOT EQUAL TEST |" << endl
		<< "+----------------+" << endl;
	if((*vector1) != (*vector2))
		cout << (*vector1) << " is not equal to " << (*vector2) << endl; 

}
void TEST_Subscription(Vector * vector, int i, double newValue)
{
	cout << "+-------------------+" << endl
		<< "| SUBSCRIPTION TEST |" << endl
		<< "+-------------------+" << endl;
	cout << "Vector itself : " << *vector << endl;
	cout << "Get vector[" << i << "] = " << (*vector)[i] << endl;
	(*vector)[i] = newValue;
	cout << "Set vector[" << i << "] to " << newValue << ", then vector[" << i << "] = " << (*vector)[i] << endl;
}
void TEST_Addition(Vector * vector1, Vector * vector2)
{
	cout << "+---------------+" << endl
		<< "| ADDITION TEST |" << endl
		<< "+---------------+" << endl;
	Vector* result = *vector1 + *vector2;
	cout << *vector1 << " + " << *vector2 << " = " << *result << endl;
}
void TEST_Subtraction(Vector * vector1, Vector * vector2)
{
	cout << "+------------------+" << endl
		<< "| SUBTRACTION TEST |" << endl
		<< "+------------------+" << endl;
	Vector* result = (*vector1) - (*vector2);
	cout << (*vector1) << " - " << (*vector2) << " = " << (*result) << endl;
}
int main() {
	double firstTestData[3] = { 1.2, 2.4, 3.6 };
	double secondTestData[3] = { 1.8, 2.6, 3.4 };
	Vector* v1 = new Vector(3);
	Vector* v2 = new Vector(3);
	Vector* v3 = new Vector(firstTestData, 3);
	Vector* v4 = new Vector(firstTestData, 3);
	Vector* v5 = new Vector(secondTestData, 3);
	TEST_Input(v1);
	TEST_Output(v1);
	TEST_Input(v2);
	TEST_Output(v2);
	TEST_CopyConstructor(v1);
	TEST_Assignment(v1);
	TEST_Equal(v3, v4);
	TEST_Not_Equal(v3, v5);
	TEST_Subscription(v1, 1, 5.3);
	TEST_Addition(v1, v2);
	TEST_Subtraction(v1, v2);
	return 0;
}

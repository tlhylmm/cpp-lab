#include <iostream>
#include "Vector.h"

int Vector::getDimension() const
{
    return dimension;
}

bool Vector::operator!=(const Vector& vector)
{
    if (vector.dimension != dimension) return true;
    else { //if dimensions are equal check values:
        for (int i = 0; i < dimension; i++) {
            if (data[i] != vector.data[i]) return true;
        }
    }

    return false;
}

Vector* Vector::operator+(const Vector& secondOperand)
{
    Vector* result = new Vector;
    for (int i = 0; i < dimension; i++) {
        result->data[i] = data[i] + secondOperand.data[i];
    }

    return result;
}

Vector* Vector::operator-(const Vector& secondOperand)
{
    Vector* result = new Vector;
    for (int i = 0; i < dimension; i++) {
        result->data[i] = data[i] - secondOperand.data[i];
    }

    return result;
}

const Vector* Vector::operator=(const Vector& copyVector)
{
    // in case dimension sizes are not equal:
    dimension = copyVector.dimension;
    delete [] data; //free the previous memory
    data = new double[dimension]; //create new data array
    for (int i = 0; i < dimension; i++) {
        data[i] = copyVector.data[i];
    }

    return this;
}

bool Vector::operator==(const Vector& vector)
{
    if (vector.dimension != dimension) return false;
    else { //if dimensions are equal check values:
        for (int i = 0; i < dimension; i++) {
            if (data[i] != vector.data[i]) return false;
        }
    }

    return true;
}

double& Vector::operator[](int index)
{
    return data[index];
}

const double& Vector::operator[](int index) const
{
    return data[index];
}

Vector::Vector(int dimension)
{
    this->dimension = dimension;
    data = new double[dimension]{0};
}

Vector::Vector(double data[3] , int dimension)
{
    this->dimension = dimension; //set dimension
    this->data = new double[dimension]{0}; //create data array
    //assign values:
    for (int i = 0; i < dimension; i++) {
        this->data[i] = data[i];
    }
}

Vector::Vector(const Vector& copyVector)
{
    dimension = copyVector.dimension;
    data = new double[dimension];
    for (int i = 0; i < dimension; i++) {
        data[i] = copyVector.data[i];
    }
}

Vector::~Vector()
{
    delete[] data;
}

ostream& operator<<(ostream& output, const Vector& vector)
{
    output << "[\t" << vector[0] << ",\t" << vector[1] << ",\t" << vector[2] << "]";
    return output;
}

istream& operator>>(istream& input, Vector& vector)
{
    input >> vector[0] >> vector[1] >> vector[2];
    return input;
}
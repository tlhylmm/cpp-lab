#include <iostream>
using namespace std;
#pragma once

class Vector {
    private:
        double* data;
        int dimension;
    public:
        int getDimension() const;
        bool operator != (const Vector& vector);
        Vector* operator + (const Vector& secondOperand);
        Vector* operator - (const Vector& secondOperand);
        const Vector* operator = (const Vector& copyVector);
        bool operator == (const Vector& vector);
        double& operator [] (int index);
        const double& operator [] (int index) const;
        Vector(int dimension = 3);
        Vector(double data[], int dimension);
        Vector(const Vector& copyVector);
        ~Vector();
        friend ostream& operator << (ostream& output, const Vector& vector);
        friend istream& operator >> (istream& input, Vector& vector);
};






        
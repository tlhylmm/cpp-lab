#include "GoalKeeper.h"

double GoalKeeper::CalculatePaymentForThisYear()
{
    return this->getPaymentPerYear();
}

void GoalKeeper::FlyAndTryCatch()
{
    cout << "'" << this->getName() << "' is flying and trying to catch ..." << endl;
}

GoalKeeper::GoalKeeper(const string& name, int age, double paymentPerYear)
{
    this->name = name;
    this->age = age;
    this->setPaymentPerYear(paymentPerYear);
}

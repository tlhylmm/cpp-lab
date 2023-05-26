#include "ForwardPlayer.h"

double ForwardPlayer::CalculatePaymentForThisYear()
{
    return (this->getPaymentPerYear() + (paymentPerGoal * this->getGoalCount()));
}

ForwardPlayer::ForwardPlayer(const string& name, int age, double PaymentPerYear,
                            double paymentPerGoal)
{
    this->name = name;
    this->age = age;
    this->paymentPerGoal = paymentPerGoal;
    this->setPaymentPerYear(PaymentPerYear);
}

int ForwardPlayer::getGoalCount()
{
    return goalCount;
}

void ForwardPlayer::setGoalCount(int goalCount)
{
    this->goalCount = goalCount;
}

void ForwardPlayer::ThrowYourSelf()
{
    cout << "'" << this->getName() << "' is throwing himself..." << endl;
}

void ForwardPlayer::TryDribblePast(const Player* player)
{
    Player temp = *player;
    cout << "'" << this->getName() << "' is trying a dribble past on '"
        << temp.getName() << "' ..." << endl; 
}

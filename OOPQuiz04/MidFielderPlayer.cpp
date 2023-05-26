#include "MidFielderPlayer.h"

double MidFielderPlayer::CalculatePaymentForThisYear()
{
    return (this->getPaymentPerYear() + (this->paymentPerAssist * this->getAssistCount()));
}

int MidFielderPlayer::getAssistCount()
{
    return this->assistCount;
}

MidFielderPlayer::MidFielderPlayer(const string& name, int age, double paymentPerYear,
                                    double paymentPerAssist)
{
    this->name = name;
    this->age = age;
    this->paymentPerAssist = paymentPerAssist;
    this->setPaymentPerYear(paymentPerYear);
}

void MidFielderPlayer::Press()
{
    cout << "'" << this->getName() << "' is pressing..." << endl;
}

void MidFielderPlayer::setAssistCount(int assistCount)
{
    this->assistCount = assistCount;
}

void MidFielderPlayer::TryThroughBall(const Player* player)
{
    Player temp = *player;
    cout << "'" << this->getName() << "' is trying a through ball to 'Cristiano Ronaldo'" << endl;
}

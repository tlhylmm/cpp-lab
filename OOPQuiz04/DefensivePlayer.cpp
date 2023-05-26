#include "DefensivePlayer.h"

double DefensivePlayer::CalculatePaymentForThisYear()
{
    return (this->getPaymentPerYear() + (this->paymentPerMatch * this->getPlayedMatchCount()));
}

void DefensivePlayer::Defense()
{
    cout << "'" << this->getName() << "' is defending..." << endl;
}

DefensivePlayer::DefensivePlayer(const string& name, int age,
                                double PaymentPerYear, double paymentPerMatch)
{
    this->name = name;
    this->age = age;
    this->paymentPerMatch = paymentPerMatch;
    this->setPaymentPerYear(PaymentPerYear);
}

int DefensivePlayer::getPlayedMatchCount()
{
    return this->playerMatchCount;
}

void DefensivePlayer::setPlayerMatchCount(int playedMatchCount)
{
    this->playerMatchCount = playedMatchCount;
}

void DefensivePlayer::TripUp(const Player* player)
{
    Player temp = *player;
    cout << "'" << this->getName() << "' tripped up '" << temp.getName() << "'" <<  endl;
}

#include "FootballPlayer.h"
#pragma once

FootballPlayer::FootballPlayer(const string& name, int age,
                                double paymentPerYear)
{
    this->name = name;
    this->age = age;
    this->setPaymentPerYear(paymentPerYear); 
}

double FootballPlayer::getPaymentPerYear()
{
    return this->paymentPerYear;
}

void FootballPlayer::Pas(const Player* player)
{
    Player temp = *player;
    cout << "'" << this->name << "' is passing to '" << temp.getName() << "'" <<  endl;
}

void FootballPlayer::setPaymentPerYear(double paymentPerYear)
{
    this->paymentPerYear = paymentPerYear;
}

void FootballPlayer::Shot()
{
    cout << "'" << this->getName() << "' is shotting !" << endl;
}

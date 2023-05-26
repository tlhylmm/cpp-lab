#include "Player.h"
#pragma once

class FootballPlayer:public Player{
    protected:
        double paymentPerYear;
    public:
        FootballPlayer(){};
        FootballPlayer(const string& name, int age, double paymentPerYear);
        double getPaymentPerYear();
        void Pas(const Player* player);
        void setPaymentPerYear(double paymentPerYear);
        void Shot();
        ~FootballPlayer(){};
};
#include "FootballPlayer.h"

class ForwardPlayer:public FootballPlayer{
    private:
        int goalCount;
        double paymentPerGoal;
    public:
        double CalculatePaymentForThisYear();
        ForwardPlayer(const string& name, int age, double PaymentPerYear,
                        double paymentPerMatch);
        int getGoalCount();
        void setGoalCount(int goalCount);
        void ThrowYourSelf();
        void TryDribblePast(const Player* player);
        ~ForwardPlayer();
};
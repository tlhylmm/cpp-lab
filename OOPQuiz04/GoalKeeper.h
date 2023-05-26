#include "FootballPlayer.h"

class GoalKeeper:public FootballPlayer{
    public:
        double CalculatePaymentForThisYear();
        void FlyAndTryCatch();
        GoalKeeper(const string& name, int age, double paymentPerYear);
        ~GoalKeeper();
};
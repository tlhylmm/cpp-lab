#include "FootballPlayer.h"

class DefensivePlayer:public FootballPlayer{
    private:
        double paymentPerMatch;
        int playerMatchCount;
    public:
        double CalculatePaymentForThisYear();
        void Defense();
        DefensivePlayer(const string& name, int age, double PaymentPerYear,
                        double paymentPerMatch);
        int getPlayedMatchCount();
        void setPlayerMatchCount(int playedMatchCount);
        void TripUp(const Player* player);
        ~DefensivePlayer();
};
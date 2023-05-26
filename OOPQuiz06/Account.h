// Lab 6: Account.h
// Definition of Account class.
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
    Account(double); // constructor initializes balance
    virtual void credit(double amount);
    virtual bool debit(double amount);
    void setBalance(double); // sets the account balance
    double getBalance(); // return the account balance
private:
    double balance; // data member that stores the balance
}; // end class Account

#endif
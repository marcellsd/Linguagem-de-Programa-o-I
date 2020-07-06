#include<string>
#include<iostream>
class Account
{
private:
   
public:
    Account(std::string name_, int number_);
    int number;
    std::string name;
    float balance;
    float limit;
    void withdraw(float amount);
    void deposit(float amount);
    void transfer(Account &account, float amount);
};

#include "Account.h"

Account::Account(std::string name_, int number_) : name(name_), number(number_)
{
    this->balance = 0.0;
    this->limit = 400;
}

void Account::withdraw(float amount)
{
    if (amount <= this->limit && amount <= this->balance)
    {
        this->balance = this->balance - amount;
        std::cout << this->name << "\t" << "Your new balance is: " << this->balance << "$" << std::endl;
    } 
    if(amount > this->balance)
    {
        std::cout << "You don't have enough funds in your account." << std::endl;
    }
    else
    {
        std::cout << "You can't withdraw more than your limit." << std::endl; 
    }
}

void Account::deposit(float amount)
{
    this->balance = this->balance + amount;
    std::cout << this->name << "\t" << "Your new balance is: " << this->balance << "$" << std::endl;
}

void Account::transfer(Account &account, float amount)
{
    if (amount <= this->limit && amount <= this->balance)
    {
        this->balance = this->balance - amount;
        account.deposit(amount);
        std::cout << this->name << "\t" <<  "Your new balance is: " << this->balance << "$" << std::endl;
    } 
    else if(amount > this->balance)
    {
        std::cout << "You don't have enough funds in your account." << std::endl;
    }
    else
    {
        std::cout << "You can't transfer more than your limit." << std::endl; 
    }
}
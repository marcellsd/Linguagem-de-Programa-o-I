#include <iostream>
#include "Account.h"
#include "Customer.h"
#include "Branch.h"


int main(int argc, char const *argv[])
{
    Account c1("José", "0001", "000.000.000-01", "01");
    Account c2("João", "0002", "000.000.000-02", "02");
    Account c3("Maria", "0003", "000.000.000-03", "03");

    c1.deposit(2000);
    c2.deposit(1000);

    c1.transfer(c2, 250);

    std::cout << "Number of accounts: " << c1.numberOfAccounts << std::endl;
    std::cout << "Number of accounts: " << c2.numberOfAccounts << std::endl;
    std::cout << "Number of customers: " << c1.customer.numberofCustomers << std::endl;
    std::cout << "Number of customers: " << c2.customer.numberofCustomers << std::endl;

    return 0;
}
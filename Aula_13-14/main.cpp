 #include <iostream>
#include "Account.h"

int main(int argc, char const *argv[])
{
    Account c1("José", "0001", "000.000.000-01", "01");
    Account c2("João", "0002", "000.000.000-02", "02");

    c1.deposit(2000);
    c2.deposit(1000);

    c1.transfer(c2, 250);


    return 0;
}
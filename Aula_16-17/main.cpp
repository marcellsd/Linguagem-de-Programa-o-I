 #include <iostream>
#include "Account.h"

int main(int argc, char const *argv[])
{
    Account c1("José", 1);
    Account c2("João", 2);

    c1.deposit(2000);
    c2.deposit(1000);

    c1.transfer(c2, 250);


    return 0;
}
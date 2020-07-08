#include "Customer.h"

int Customer::numberofCustomers;

Customer::Customer()
{
    this->numberofCustomers += 1;
}


#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer
{
private:
    
public:
    Customer();
    std::string name;
    std::string cpf;
    static int numberofCustomers;

};

#endif
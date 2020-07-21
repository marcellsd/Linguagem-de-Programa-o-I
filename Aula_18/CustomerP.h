 
#ifndef CUSTOMERP_H
#define CUSTOMERP_H

#include "Customer.h"
#include <string>

class CustomerP : public Customer
{
  public:
    CustomerP();
    CustomerP(std::string, std::string);

    std::string toString();
};

#endif
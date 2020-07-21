#ifndef CUSTOMERLP_H
#define CUSTOMERLP_H

#include "Customer.h"
#include <string>

class CustomerLP : public Customer
{

public:
    CustomerLP();
    CustomerLP(std::string,std::string);
    //void setCompanyName(std::string companyName_);
    //std::string getCompanyName();
    //void setEIN(std::string EIN_);
    //std::string getEIN();
    std::string toString();
};

#endif
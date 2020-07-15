#ifndef CUSTOMERLP_H
#define CUSTOMERLP_H

#include <string>

class CustomerLP
{
private:
    std::string companyName;
    std::string EIN;
public:
    CustomerLP();
    //~CustomerLP();

    void setCompanyName(std::string companyName_);
    std::string getCompanyName();
    void setEIN(std::string EIN_);
    std::string getEIN();
};

#endif
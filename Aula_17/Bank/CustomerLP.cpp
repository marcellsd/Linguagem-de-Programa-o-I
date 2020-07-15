#include "CustomerLP.h"

CustomerLP::CustomerLP(){}
//CustomerLP::~CustomerLP(){}

void CustomerLP::setCompanyName(std::string companyName_)
{
    this->companyName = companyName_;
}

std::string CustomerLP::getCompanyName()
{
    return this->companyName;
}

void CustomerLP::setEIN(std::string EIN_)
{
    this->EIN = EIN_;
}

std::string CustomerLP::getEIN()
{
    return this->EIN;
}
#include "CustomerLP.h"
#include <sstream>

CustomerLP::CustomerLP(){}
CustomerLP::CustomerLP(std::string companyName_, std::string EIN_)
{
    setName(companyName_);
    setDocument(EIN_);
}

std::string CustomerLP::toString()
{
    std::ostringstream stream;
    stream << "Company name:   " << getName() << std::endl;
    stream << "EIN:   " << getDocument() << std::endl;
    return stream.str();
}
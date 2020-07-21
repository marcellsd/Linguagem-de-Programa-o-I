#include "CustomerP.h"
#include <sstream>

CustomerP::CustomerP(){}
CustomerP::CustomerP(std::string name_, std::string cpf_)
{
    setName(name_);
    setDocument(cpf_);
}

std::string CustomerP::toString()
{
    std::ostringstream stream;
    stream << "Name:   " << getName() << std::endl;
    stream << "CPF:   " << getDocument() << std::endl;
    return stream.str();
}
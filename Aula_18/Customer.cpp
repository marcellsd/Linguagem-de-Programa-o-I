#include "Customer.h"

int Customer::numberofCustomers;

Customer::Customer()
{
    this->numberofCustomers += 1;
}

Customer::Customer(std::string name_, std::string document_) : name(name_), document(document_)
{
    this->numberofCustomers += 1;
}
Customer::~Customer() {}

void Customer::setName(std::string name_)           
{ 
    name = name_; 
}
std::string Customer::getName()
{ 
    return name; 
}
void Customer::setDocument(std::string document_)  
{ 
    document = document_;
}
std::string Customer::getDocument() 
{ 
    return document; 
}
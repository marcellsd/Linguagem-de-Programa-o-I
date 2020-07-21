#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer
{
private:
    std::string name;
    std::string document;
public:
    Customer();
    Customer(std::string, std::string);
    static int numberofCustomers;

    void setName(std::string);
    std::string getName();
    void setDocument(std::string);
    std::string getDocument();
    
    std::string toString();
};

#endif
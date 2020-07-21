 
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
private:
    std::string name;
    unsigned id;

public:
    Employee();
    Employee(std::string, unsigned);
    ~Employee();
    void setName(std::string);
    std::string getName();
    void setId(unsigned);
    unsigned getId();

    std::string toString();
};

#endif
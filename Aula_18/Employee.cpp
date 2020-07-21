#include "Employee.h"

Employee::Employee() {}
Employee::Employee(std::string name_, unsigned id_) : name(name_), id(id_) {}
Employee::~Employee() {}


void Employee::setName(std::string name_)           
{ 
    name = name_; 
}
std::string Employee::getName()                     
{
    return name; 
}
void Employee::setId(unsigned id_)            
{
    id = id_; 
}
unsigned Employee::getId()                    
{ 
    return id; 
}
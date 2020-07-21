#include <iostream>
#include "Account.h"
#include "Customer.h"
#include "Branch.h"
#include "CustomerLP.h"
#include "Queue.h"
#include <vector>

int main(int argc, char const *argv[])
{
    Customer c1, c2, c3;
    CustomerLP cLP1, cLP2, cLP3;

    c1.name = "José"; c1.cpf = "000.000.000-01";
    c2.name = "João"; c2.cpf = "000.000.000-02";
    c3.name = "Maria"; c3.cpf = "000.000.000-03";

    cLP1.setCompanyName("Unknown 1");
    cLP2.setCompanyName("Unknown 2");
    cLP3.setCompanyName("Unknown 3");
    cLP1.setEIN("00.000.000/0000-01");
    cLP2.setEIN("00.000.000/0000-02");
    cLP3.setEIN("00.000.000/0000-03");

    Queue<Customer> queue(2);

    queue.add(c1);
    queue.add(c3);
    queue.add(c2);

    Queue<CustomerLP> queueLP(2);

    queueLP.add(cLP2);
    queueLP.add(cLP3);
    queueLP.add(cLP1);

    std::vector<Customer> queueCustumer;

    for (size_t i = 0; i < 2; i++)
    {
        queueCustumer.push_back(queue.value[i]);
    }
    
    for (size_t i = 0; i < queueCustumer.size(); i++)
    {
        std::cout << queueCustumer[i].name << std::endl;
        std::cout << queueCustumer[i].cpf << std::endl;
    }    
    
    std::vector<CustomerLP> queueCustumerLP;

    for (size_t i = 0; i < 2; i++)
    {
        queueCustumerLP.push_back(queueLP.value[i]);
    }
    
    for (size_t i = 0; i < queueCustumerLP.size(); i++)
    {
        std::cout << queueCustumerLP[i].getCompanyName() << std::endl;
        std::cout << queueCustumerLP[i].getEIN() << std::endl;
    }   
         

    return 0;
}
#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include "Empresa.h"

class Funcionario
{
private:
    std::string nome;
    Empresa empresa;
    std::string departamento;
    float salario;
    std::string dataDeAdmissao;
public:
    Funcionario();
    ~Funcionario();
    std::string getNome();
    void setNome(std::string nome_);
    Empresa getEmpresa();
    void setEmpresa(Empresa empresa_);
     std::string getDepartamento();
    void setDepartamento(std::string departamento_);
    float getSalario();
    void setSalario(float salario_);
    std::string getDataDeAdmissao();
    void setDataDeAdmissao(std::string dataDeAdmissao_);  
};


#endif
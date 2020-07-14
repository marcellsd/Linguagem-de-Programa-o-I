#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>

class Empresa
{
private:
    std::string nome;
    std::string cnpj;
public:
    Empresa();
    ~Empresa();

    std::string getNome();
    void setNome(std::string nome_);
    std::string getCnpj();
    void setCnpj(std::string cnpj_); 
};


#endif
#include "Empresa.h"

Empresa::Empresa(){}
Empresa::~Empresa(){}
std::string Empresa::getNome()
{
    return this->nome;
}
void Empresa::setNome(std::string nome_)
{
    this->nome = nome_;
}

std::string Empresa::getCnpj()
{
    return this->cnpj;
}
void Empresa::setCnpj(std::string cnpj_)
{
    this->cnpj = cnpj_;
}
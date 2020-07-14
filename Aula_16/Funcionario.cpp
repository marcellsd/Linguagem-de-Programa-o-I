#include "Funcionario.h"

Funcionario::Funcionario(){}
Funcionario::~Funcionario(){}
std::string Funcionario::getNome()
{
    return this->nome;
}
void Funcionario::setNome(std::string nome_)
{
    this->nome = nome_;
}

Empresa Funcionario::getEmpresa()
{
    return this->empresa;
}
void Funcionario::setEmpresa(Empresa empresa_)
{
    this->empresa = empresa_;
}

std::string Funcionario::getDepartamento()
{
    return this->departamento;
}

void Funcionario::setDepartamento(std::string departamento_)
{
    this->departamento = departamento_;
}

float Funcionario::getSalario()
{
    return this->salario;
}

void Funcionario::setSalario(float salario_)
{
    this->salario = salario_;
}

std::string Funcionario::getDataDeAdmissao()
{
    return this->dataDeAdmissao;
}

void Funcionario::setDataDeAdmissao(std::string dataDeAdmissao_)
{
    this->dataDeAdmissao = dataDeAdmissao_;
}
#include <iostream>
#include "Empresa.h"
#include "Funcionario.h"
#include <vector>


int main()
{
    Empresa empresa;
    std::vector<Funcionario> funcionarios;
    std::string quantidadeFuncionarios;
    std::cout << "Digite a quantidade de funcionários da Empresa." << std::endl;
    std::getline(std::cin, quantidadeFuncionarios);

    for (int i = 0; i < std::stoi(quantidadeFuncionarios); i++)
    {
        Funcionario f;
        f.setNome("Funcionário_"+std::to_string(i+1));
        f.setEmpresa(empresa);
        f.setSalario(3500);
        f.setDataDeAdmissao("22/02/2020");
        if ((i%5) == 0)
        {
            f.setDepartamento("Pessoal");
        }
        else if ((i%5) == 1)
        {
            f.setDepartamento("Financeiro");
        }
        else if ((i%5) == 3)
        {
            f.setDepartamento("Vendas");
        }
         else if ((i%5) == 4)
        {
            f.setDepartamento("Desenvolvimento");
        }
        funcionarios.push_back(f);
    }
    std::cout << std::endl;
    std::cout<<"\t\tQuadro de funcionários"<<std::endl;
    std::cout << std::endl;
    for (size_t i = 0; i < funcionarios.size(); i++)
    {
         if (funcionarios[i].getDepartamento() == "Desenvolvimento")
        {
            float salario = funcionarios[i].getSalario();
            funcionarios[i].setSalario(salario * 1.2);
        }
        std::cout << "Nome: " + funcionarios[i].getNome(); 
        std::cout << " - Departamento: " + funcionarios[i].getDepartamento();
        std::cout << " - Salario: " + std::to_string(funcionarios[i].getSalario()) << std::endl;
    }
}

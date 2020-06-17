#include <iostream>
#include <string>
#include <fstream>

int main( int argc, char *argv[]){
    std::string add = "add";
    std::string mensagem;
    std::ofstream output_file("Arquivo_de_saída.txt");

    if (argc == 1 || add.compare(argv[1]) == 1){
        std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
        return -1;
        }
    
    if (add.compare(argv[1]) == 0 && argc == 2){    
        std::cout << "Por favor, insrira uma mensagem." << std::endl;
        std::getline(std::cin,mensagem);
        output_file << mensagem << std::endl;
        std::cout << "Mensagem adicionada" << std::endl;
    }
    else{
        mensagem = argv[2];
        output_file << mensagem << std::endl;
        std::cout << "Mensagem adicionada"<< std::endl;
    }

    output_file.close();

    return 0;
}
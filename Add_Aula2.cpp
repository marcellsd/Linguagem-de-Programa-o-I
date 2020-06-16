#include <iostream>
#include <string>

int main( int argc, char *argv[]){
    std::string add = "add";
    std::string mensagem;

    if (argc == 1 || add.compare(argv[1]) == 1){
        std::cout << "Uso: " << argv[0] << " add <mensagem>" << std::endl;
        return -1;
        }
    
    if (add.compare(argv[1]) == 0 && argc == 2){    
        std::cout << "Por favor, insrira uma mensagem." << std::endl;
        std::getline(std::cin,mensagem);
        std::cout << "Mensagem adicionada";
    }
    else{
        mensagem = argv[2];
        std::cout << "Mensagem adicionada"<< std::endl;
    }

    return 0;
}
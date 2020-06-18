#include <iostream>
#include <string>
#include <fstream>

#define USAGE_MSG 
void usage_msg(const std::string& program);

int main( int argc, char *argv[]){
    std::string add = "add";
    std::string list = "list";
    std::string message;
    std::fstream file("output_file.txt", std::fstream::in | std::fstream::out | std::fstream::app);

    if (argc == 1){
        usage_msg(argv[0]);
        return -1;
        }
    if (!file.is_open()){
        std::cerr << "File do not exist or you don't have permission to open it." << std::endl;
    }

    if (add == argv[1]){
        if ( argc == 2){    
            std::cout << "Please, insert a message." << std::endl;
            std::getline(std::cin,message);
            file << message << std::endl;
            std::cout << "Message added!" << std::endl;
        }
        else{
            message = argv[2];
            file << message << std::endl;
            std::cout << "Message added!" << std::endl;
        }
        file.close();
        return 0;
    } else if (list == argv[1]){
        int line_pos = 0;

        while(!file.eof()) {
            std::getline(file, message);
            line_pos++;

            if (message.size() == 0) {
                continue;
            }

        std::cout << line_pos << ". " << message << std::endl;
        }

        file.close();
        return 0;
    } else{
        usage_msg(argv[0]);
        return 1;
    }
}

void usage_msg(const std::string& program){
    std::cout << "To correctly use this program use one of the forms bellow:" << std::endl;
    std::cout << "> To add: " << program << " add <message>.";
    std::cout << " or  simply: " << program << " add." << std::endl;
    std::cout << "> To list: " << program << " list." << std::endl;
}
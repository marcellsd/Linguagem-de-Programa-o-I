#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

#define USAGE_MSG 
#define FORMAT_CURRENT_DATE
#define GET_CURRENT_DATE
#define GET_CURRENT_TIME
#define PRINT_TODAY

void usage_msg(const std::string& program);
std::string format_current_date(const std::string &format);
std::string get_current_date();
std::string get_current_time();
std::string print_today(std::fstream& file);


int main( int argc, char *argv[]){
    std::string add = "add";
    std::string list = "list";
    std::string message;
    std::fstream file("output_file.md", std::fstream::in | std::fstream::out | std::fstream::app);

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
            
            std::string today = print_today(file);

            std::fstream file("output_file.md", std::fstream::in | std::fstream::out | std::fstream::app);
            
            file << today << std::endl; 

            std::string time = get_current_time();
            file <<"- "<< time << " " << message;
            std::cout << "Message added!" << std::endl;
        }
        else{
            message = argv[2];

            std::string today = print_today(file);

            std::fstream file("output_file.md", std::fstream::in | std::fstream::out | std::fstream::app);
            
            file << today << std::endl;
            
            std::string time = get_current_time();            
            file <<"- " << time << " " << message;

            std::cout << "Message added!" << std::endl;
        }
        file.close();
        return 0;

    } else if (list == argv[1]){
        int pos = 1;
        while(!file.eof()) {
            std::getline(file, message);
            char first_char = message[0];

            if (message.size() == 0) {
                continue;
            }
            if (first_char == '#') {
                continue;
            }

            std::cout <<pos << ". " << message.erase(0, 11)  << std::endl;
            pos++;
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

std::string format_current_date(const std::string &format) {
    
    std::time_t time = std::time(nullptr);
    char result[1024];

    std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));

    return std::string(result);

}

std::string get_current_date() { return format_current_date("%d/%m/%Y"); }


std::string get_current_time() { return format_current_date("%H:%M:%S"); }


std::string print_today(std::fstream& file){
    
    int is_today = 0;
    std::string msg;
    std::string today = "# " + get_current_date();
    
    while(!file.eof()){
        std::getline(file, msg);
        
        if(msg == today){
            is_today = 1;
        }  
    }
    if (is_today == 0){
        return ("\n\n" + today + "\n");
    } else return "";
}

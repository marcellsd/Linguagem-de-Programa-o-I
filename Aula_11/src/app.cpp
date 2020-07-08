#include "App.h"

#include <iostream>
#include <string>

App::App(const std::string& filename) : diary(filename){

}

int App::run(int argc, char* argv[]){
    
    if (argc == 1) {
        return show_usage(argv[0]);
    }

    std::string action = argv[1];

    if (action == "add"){
        if(argc == 2){
            add();
        } else {
            add(argv[2]);
        }
    } 
    else if (action == "list") 
    {
        if (argc == 2)
        {
            list_messages_config();
        } else{
            list_messages_config(argv[2]);
        }
    } 
    else if (action == "search")
    {
      search();
    } 
    else if(action == "interactive")
    {
        int option = 5;
        
        while (option != 0)
        {
            std::cout << std::endl;
            std::cout << "Diary 1.0" << std::endl;
            std::cout << std::endl;
            std::cout << "Choose an option:" << std::endl;
            std::cout << std::endl;
            std::cout << "1) List messages" << std::endl;
            std::cout << "2) Add new message" << std::endl;
            std::cout << std::endl;
            std::cout << "0) Exit program" << std::endl;
            std::cout << std::endl << " ";

            std::cin >> option;
            std::cout << std::endl;

            if (option == 1)
            {
                list_messages_config();
            } 
            else if (option == 2)
            {
                add();
            } 
            else if (option == 0) 
            {
                std::cout << "Program closed" << std::endl;
                return 0;
            }
        } 
    }
    else 
    {
        return show_usage(argv[0]);
    }

    return 0;
}

void App::add(){
    std::cin.ignore();
    std::string message;
    std::cout << "Enter your message:" << std::endl;
    std::getline(std::cin, message);
    add(message);
}

void App::add(const std::string message){

    diary.add(message);

}

void App::list_messages_config()
{
    for(size_t i = 0; i < diary.messages.size(); ++i){
        std::vector<std::string> format_config;
        format_config = App::config_list_format(i);
        for (size_t j = 0; j < format_config.size(); j++)
        {
            std::cout << format_config[j];
        }
        std::cout << std::endl;
        
    }
}

void App::list_messages_config(std::string format)
{
    for(size_t i = 0; i < diary.messages.size(); ++i){
        std::vector<std::string> format_config;
        format_config = App::config_list_format(format, i);
        for (size_t j = 0; j < format_config.size(); j++)
        {
            std::cout << format_config[j];
        }
        std::cout << std::endl;
        
    }
}

int App::show_usage(const std::string& program_name){
    std::cout << "To correctly use this program use one of the forms bellow:" << std::endl;
    std::cout << "> To add: " <<program_name << " add <message>.";
    std::cout << " or  simply: " << program_name << " add." << std::endl;
    std::cout << "> To list: " << program_name << " list." << std::endl;
    std::cout << "> To search: " << program_name << " search." << std::endl;
    std::cout << "> Interactive mode: " << program_name << " interactive." << std::endl;
    return 1;
}

void App::search(){
    std::string what;

    std::cout << "Please, enter the word to search:" << std::endl;
    std::getline(std::cin, what);
    std::vector<Message> m;
    std::vector<Message*> strcpr_return = diary.search(what);

    if(strcpr_return.size() == 0){
        std::cout << "Word not found!" << std::endl;
        return;
    } else{
        for (size_t i = 0; i < strcpr_return.size(); i++)
        {
            std::cout << strcpr_return[i]->date.to_string() << " " << strcpr_return[i]->time.to_string() << " " << strcpr_return[i]->content << std::endl;
        }
        
    }
}

std::vector<std::string> App::config_list_format(int cont_message)
{
    std::ifstream config_file;
    config_file.open("diary.config");
    std::string line;
    std::vector<std::string> list_format;
   
    while(!config_file.eof())
    {
       std::getline(config_file, line);
    
       std::vector<int> pos;
       pos.push_back(0);
       int end_instruction = 0;
       
       for (size_t i = 0; i < line.length(); i++)
       {
            if (line[i] == '=' && end_instruction == 0)
            {
                pos.push_back(i);
                pos.push_back(i+1);
                end_instruction++;
            }
            else if (line[i] == '%' && line[i+1] == 'd' && i< (line.length()-1))
            {
                pos.push_back(i);
                pos.push_back(i+2);
            }

            else if (line[i] == '%' && line[i+1] == 't' && i< (line.length()-1))
            {
                pos.push_back(i);
                pos.push_back(i+2);
            }

            else if (line[i] == '%' && line[i+1] == 'm' && i< (line.length()-1))
            {
                pos.push_back(i);
                pos.push_back(i+2);
            }

            if ((i+1) == line.length())
            {
                end_instruction = 0;
            }
       }
  
        if (line.substr(pos[0],pos[1]) == "default_format")
        {
            for (size_t i = 2; i < pos.size(); i++)
            {    
                if (line.substr(pos[i],(pos[i+1]-pos[i])) == "%d")
                {
                    list_format.push_back(diary.messages[cont_message].date.to_string_list());
                }
                else if (line.substr(pos[i],(pos[i+1]-pos[i])) == "%t")
                {
                    list_format.push_back(diary.messages[cont_message].time.to_string_list());
                }
                else if (line.substr(pos[i],(pos[i+1]-pos[i])) == "%m")
                {
                    list_format.push_back(diary.messages[cont_message].content);
                }
                else
                {
                list_format.push_back(line.substr(pos[i],(pos[i+1]-pos[i])));
                }
            }
            
        }  
    }
    return list_format;
}


std::vector<std::string> App::config_list_format(std::string format,int cont_message)
{
    std::vector<int> pos;
    pos.push_back(0);
    std::vector<std::string> list_format;
    std::string line = format;
    for (size_t i = 0; i < format.length(); i++)
    {

        if (line[i] == '%' && line[i+1] == 'd' && i< (line.length()-1))
        {
            pos.push_back(i);
            pos.push_back(i+2);
        }

        else if (line[i] == '%' && line[i+1] == 't' && i< (line.length()-1))
        {
            pos.push_back(i);
            pos.push_back(i+2);
        }

        else if (line[i] == '%' && line[i+1] == 'm' && i< (line.length()-1))
        {
            pos.push_back(i);
            pos.push_back(i+2);
        }
    }

    for (size_t i = 0; i < pos.size(); i++)
    {    
        if (line.substr(pos[i],(pos[i+1]-pos[i])) == "%d")
        {
            list_format.push_back(diary.messages[cont_message].date.to_string_list());
        }
        else if (line.substr(pos[i],(pos[i+1]-pos[i])) == "%t")
        {
            list_format.push_back(diary.messages[cont_message].time.to_string_list());
        }
        else if (line.substr(pos[i],(pos[i+1]-pos[i])) == "%m")
        {
            list_format.push_back(diary.messages[cont_message].content);
        }
        else
        {
        list_format.push_back(line.substr(pos[i],(pos[i+1]-pos[i])));
        }
    }
    return list_format;
}


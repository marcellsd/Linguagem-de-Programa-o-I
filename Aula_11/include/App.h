#ifndef APP_H
#define APP_H

#include "Diary.h"


struct App{
    App(const std::string& filename);
    
    Diary diary;
    std::string list_format;

    int run(int argc, char* argv[]);
    int show_usage(const std::string& program_name);
    void add();
    void add(const std::string message);
    void list_messages_config();
    void list_messages_config(const std::string format);
    void search();
    std::vector<std::string> config_list_format(int cont_message);
     std::vector<std::string> config_list_format(std::string format, int cont_message);

};

#endif


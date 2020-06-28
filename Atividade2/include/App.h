#ifndef APP_H
#define APP_H

#include "Diary.h"
#include <string>
#include <fstream>

struct App{
    App(const std::string& filename);
    
    Diary diary;
    
    int run(int argc, char* argv[]);
    int show_usage(const std::string& program_name);
    void add();
    void add(const std::string message);
    void list_messages();

};

#endif


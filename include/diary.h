#ifndef DIARY_H
#define DIARY_H

#include <iostream>
#include <string>
#include <fstream>
#include "message.h"

struct diary{

    Message* message;

    void add(message);
    void list();
    void usage_msg(const std::string& program_name);
    std::string print_today(std::fstream& file);

};



#endif
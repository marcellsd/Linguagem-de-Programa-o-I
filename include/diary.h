#ifndef DIARY_H
#define DIARY_H

#include <string>
#include "message.h"

struct Diary{

    std::string filename;

    Diary(const std::string& filename);
    
    Message* message;
    size_t messages_size;
    size_t messages_capacity;

    void add(const std::string& message);
    void write();
};



#endif
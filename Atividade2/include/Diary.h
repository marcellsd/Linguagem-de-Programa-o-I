#ifndef DIARY_H
#define DIARY_H

#include <string>
#include <fstream>
#include "Message.h"
#include <iostream>
#include <sstream>

struct Diary{

    Diary(const std::string& filename);
    ~Diary();
    
    std::string filename;
    Message* messages;
    size_t messages_size;
    size_t messages_capacity;

    void add(const std::string& message);
    void write(Message msg);
    void load_diary();
    void more_messages();
    
};

#endif
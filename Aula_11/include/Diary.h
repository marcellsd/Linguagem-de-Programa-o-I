#ifndef DIARY_H
#define DIARY_H

#include <string>
#include <fstream>
#include "Message.h"
#include <iostream>
#include <sstream>
#include <vector>

struct Diary{

    Diary(const std::string& filename);
    std::string path;
    std::string filename;
    std::vector<Message> messages;
    size_t messages_size;
    void add(const std::string& message);
    void write(Message msg);
    void load_diary();
    void more_messages();
    std::vector<Message*> search(std::string what);
    void config_path();
};

#endif
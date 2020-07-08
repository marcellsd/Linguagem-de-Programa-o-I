#ifndef TIME_H
#define TIME_H

#include <string>
#include <sstream>
#include <ctime>

struct Time{

    Time();
    unsigned hour;
    unsigned minute;
    unsigned second;

    void set_from_string(const std::string& time);
    std::string to_string();
    std::string format_current_time(const std::string &format);
    std::string get_current_time();
    std::string to_string_list();
};

#endif
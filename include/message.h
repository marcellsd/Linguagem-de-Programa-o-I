#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <ctime>



struct Chrono{
    
    std::string date;
    std::string time;
    
    
    std::string format_current_date(const std::string &format);
    std::string get_current_date();
    std::string get_current_time();

    };

struct Message{
    
    Chrono chrono;
    std::string content;

    };

#endif
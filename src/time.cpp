#include "Time.h"

Time::Time() : hour(0), minute(0), second(0){}

void Time::set_from_string(const std::string& time){

    //format: HH:MM:SS -> 01:01:01

    std::stringstream stream(time);
    char discard;

    stream >> hour;
    stream >> discard;
    stream >> minute;
    stream >> discard;
    stream >> second;
}
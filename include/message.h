#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include "date.h"
#include "time.h"

struct Message{
    
    Date date;
    Time time;
    std::string content;

    };

#endif
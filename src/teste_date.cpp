#include "Date.h"
#include "Time.h"
#include <iostream>

int main(int argc, char* argv[]){
    Date today;
    Time now;
    std::string date = "25/06/2020";
    std::string time = "18:11:45";
    
    today.set_from_string(date);
    std::cout << today.day << std::endl;
    std::cout << today.month << std::endl;
    std::cout << today.year << std::endl;
    
    now.set_from_string(time);
    std::cout << now.hour << std::endl;
    std::cout << now.minute << std::endl;
    std::cout << now.second << std::endl;
    
    
    return 0;
}

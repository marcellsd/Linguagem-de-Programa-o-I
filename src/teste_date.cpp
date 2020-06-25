#include "Date.h"
#include <iostream>

int main(int argc, char* argv[]){
    Date today;
    std::string date = "25/06/2020";

    today.set_from_string(date);
    std::cout << today.day << std::endl;
    std::cout << today.month << std::endl;
    std::cout << today.year << std::endl;

    return 0;
}
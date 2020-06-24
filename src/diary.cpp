#include "Diary.h"
#include <iostream>

Diary::Diary(const std::string& filename) :  messages_size(0), messages_capacity(10), messages(nullptr){
    messages = new Message[messages_capacity];
}

void Diary::add(const std::string& message){

    messages[messages_size].content = message;
    messages_size++;
}

void Diary::write(){
   
    
}
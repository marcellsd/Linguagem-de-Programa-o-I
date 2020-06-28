#include "Diary.h"


Diary::Diary(const std::string& filename) : filename(filename),  messages_size(0), messages_capacity(10), messages(nullptr){
    messages = new Message[messages_capacity];
    Diary::load_diary();
}
Diary::~Diary(){
    delete[] messages;
}

void Diary::add(const std::string& message){

    if (messages_size >= messages_capacity-1){
        Diary::more_messages();
    }
    
    Message m;

    m.date.set_from_string(m.date.get_current_date());
    m.time.set_from_string(m.time.get_current_time());
    m.content = message;
    messages[messages_size] = m;
    messages_size++;

    Diary::write(m);

}

void Diary::write(Message msg){
    
    std::ofstream file;
    file.open(filename, std::ios::app);

    if (!file.is_open()){
        std::cerr << "File do not exist or you don't have permission to open it." << std::endl;
        return;
    }
    
    if (msg.date.day != messages[messages_size-2].date.day ||
        msg.date.month != messages[messages_size-2].date.month || 
        msg.date.year != messages[messages_size-2].date.year)
    {
        if (messages_size <= 1)
        {
            file <<msg.date.to_string() << "\n" << std::endl;
        } else
        {
          file << "\n" <<msg.date.to_string() << "\n" << std::endl;
        }
        
    }

    file << msg.time.to_string() << " " << msg.content << std::endl;
    std::cout << "Message added!" << std::endl;
}

void Diary::load_diary(){
    
    std::ifstream file;
    file.open(filename);
    std::string line;

    if (!file.is_open()){
        std::cerr << "File do not exist or you don't have permission to open it." << std::endl;
        return;
    }
    
    Message n;

    while(!file.eof()){
        std::getline(file, line);
        char first_char = line[0];
        char discards;
        
        Message m;
        
        if (line.size() == 0) {
            continue;
        }
        if (first_char == '#') {
            n.date.set_from_string(line);

        } else if (first_char == '-') {
            m.date = n.date;
            m.time.set_from_string(line);
            m.content = line.erase(0,11);
            messages[messages_size] = m;
            messages_size++;
        }
        if (messages_size >= messages_capacity-1){
                Diary::more_messages();
        }

    }
        
}

void Diary::more_messages(){
    messages_capacity*=2;
    Message* moremsgs = new Message[messages_capacity];

    for (size_t i = 0; i < messages_size; i++)
    {
        moremsgs[i] = messages[i];
        
    }
    delete[] messages;
    messages = moremsgs;
    

}
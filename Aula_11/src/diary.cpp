#include "Diary.h"
#include "App.h"


Diary::Diary(const std::string& filename) : filename(filename),messages_size(0){
    Diary::config_path();
    Diary::load_diary();
}


void Diary::add(const std::string& message){
    
    Message m;

    m.date.set_from_string(m.date.get_current_date());
    m.time.set_from_string(m.time.get_current_time());
    m.content = message;
    messages.push_back(m);
    messages_size++;
    Diary::write(m);

}

void Diary::write(Message msg){
    
    std::ofstream file;
    filename = path;
    file.open(filename, std::ios::app);

    /*if (!file.is_open()){
        std::cerr << "File do not exist or you don't have permission to open it." << std::endl;
        return;
    }*/
    
    if (msg.date.day != messages[messages_size - 2].date.day ||
        msg.date.month != messages[messages_size - 2].date.month || 
        msg.date.year != messages[messages_size - 2].date.year)
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
    filename = path;
    file.open(filename);
    std::string line;

    if (!file.is_open()){
        std::cerr << "File not found!" << std::endl;
        return;
    }
    
    Message n;

    while(!file.eof()){
        std::getline(file, line);
        char first_char = line[0];
        
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
            messages.push_back(m);
            messages_size++;
        }

    }
        
}

 std::vector<Message*> Diary::search(std::string what){

     std::vector<Message*> message_return;
     Message* m;

    for (size_t i=0; i < messages.size() + 1; i++){

        std::size_t strcpr = messages[i].content.find(what);
        
        if (strcpr < messages[i].content.npos) {
            m = &messages[i];
            message_return.push_back(m);
        }
    }
  
  return message_return;

}

void Diary::config_path(){
    std::ifstream config_file;
    config_file.open("diary.config");
    std::string line;

    if (!config_file.is_open()){
        std::ofstream config_new_file("diary.config",std::ofstream::out);
        config_new_file << "path=diary.md" << std::endl;
        config_new_file << "default_format=%d %t: %m" << std::endl;
        config_file.open("diary.config");
        std::cout << "A new diary config file has been created." << std::endl;
    }
        
    while(!config_file.eof())
    {
       std::getline(config_file, line);
       
       std::vector<int> pos;
       pos.push_back(0);
       int end_instruction = 0;
       
       for (size_t i = 0; i < line.length(); i++)
       {
            if (line[i] == '=' && end_instruction == 0)
            {
                pos.push_back(i);
                pos.push_back(i+1);
                end_instruction++;
            }

            if ((i+1) == line.length())
            {
                end_instruction = 0;
            }
       }
  
       if (line.substr(pos[0],pos[1]) == "path")
       {
           path = line.substr(pos[1]+1);
       }
    }
    
}
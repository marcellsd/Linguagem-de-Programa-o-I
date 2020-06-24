#include "Diary.h"

#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
  Diary diary("diary.md");
  std::string message = "Message";

  for (int i = 0; i < 10; ++i) {
    diary.add(message);
  }

  std::cout << diary.messages_size << std::endl;
  std::cout << diary.messages_capacity << std::endl;

  return 0;
}
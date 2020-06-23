#include "App.h"

int main(int argc, char* argv[]){

    std::string filename = "diary.md";
    App aplicativo("diary.md");
    return aplicativo.run(argc, argv);

}
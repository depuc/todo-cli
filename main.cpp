#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <filesystem>
#include <cstdlib>
#include <fstream>
#include <sstream>

namespace fs = std::filesystem;

std::vector<std::string> Tasks;

std::string getPath() {

    const char* home = std::getenv("HOME");
    if(!home){
        std::cerr<<"Unable to determine HOME directory"<<std::endl;
        exit(1);
    }

    std::string dirpath = std::string(home) + "/.todo";
    
    if(!fs::exists(dirpath)){
        fs::create_directory(dirpath);
    }

    return dirpath + "/todo.txt";

}


void show_help() {
    // Mimic the 'usage' line from git help
    std::cout << "usage: todo <command> [<args>]\n\n";
    std::cout << "These are common todo commands used in various situations:\n\n";

    // First group of commands
    std::cout << "start and manage your todo list\n";
    std::cout << "   add \"<task>\"    Add a new task to the list\n";
    std::cout << "   list            List all active tasks\n";
    std::cout << "   clear           Remove all tasks from the list\n\n";
    
    // Second group of commands
    std::cout << "work on specific tasks\n";
    std::cout << "   done <id>       Mark a task as complete by its ID\n";
    std::cout << "   remove <id>     Delete a task by its ID\n\n";

    // Help command
    std::cout << "get help\n";
    std::cout << "   help            Show this help message\n";
}

void add(const std::string& Task, std::string& filePath) {

    std::ifstream infile(filePath);
    std::string line;
    int lastId = 0;

    while (std::getline(infile, line)) {
        if (line.rfind("#", 0) == 0) { 
            size_t dashPos = line.find("-");
            if (dashPos != std::string::npos) {
                std::string idStr = line.substr(1, dashPos - 2);
                try {
                    int id = std::stoi(idStr);
                    if (id > lastId) {
                        lastId = id;
                    }
                } catch (...) {

                }
            }
        }
    }
    infile.close();

    int newId = lastId + 1;

    std::ofstream outfile(filePath, std::ios::app);
    if (outfile.is_open()) {
        outfile << "#" << newId << " - " << Task << std::endl;
        outfile.close();
    } else {
        std::cerr << "Error opening file for writing" << std::endl;
    }

}

void list(const std::string& filePath){

    std::ifstream infile(filePath);
    if(infile.is_open()) {
        std::string line;
        while(getline(infile, line)){
            std::cout<< line << std:: endl;
        }
        infile.close();
    }
    else{
        std::cerr<<"No Entries yet."<<std::endl;
    }

}

void clear(const std::string& filePath){

    if(fs::exists(filePath)){
        try {
            fs::remove(filePath);
        }
        catch(const fs::filesystem_error& e){
            std::cerr << "Error deleting file: " << e.what() << '\n';
        }
    }
    else{
            std::cout << "File '" << filePath << "' does not exist.\n";
    }


}
        
int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No arguments provided.\n";
        show_help();
        return 1;
    }

    std::string filePath = getPath();

    std::string command = argv[1];

    if (command == "add") {
        if (argc >= 3) {
            add(argv[2], filePath);
        } else {
            std::cerr << "Error: No task provided.\n";
            show_help();
        }
    }
    else if (command == "--list") {
        list(filePath);
    }
    else if (command == "--clear") {
        clear(filePath);
    }
    else if (command == "--help") {
        show_help();
    }
    else {
        std::cerr << "Invalid command: '" << command << "'\n";
        show_help();
    }

    return 0;
}


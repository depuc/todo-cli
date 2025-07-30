#include <iostream>
#include <vector>
#include <string>


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
        


int main(int argc,char* argv[]){
        

    if(argc < 2){
        std::cerr<<"Error: No Arguments provided.\n";
        show_help();
        return 1;
    }

    


}

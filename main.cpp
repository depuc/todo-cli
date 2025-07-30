#include <iostream>
#include <vector>
#include <cstring>
#include <string>

std::vector<std::string> Tasks;

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

void add(const std::string& Task){
    Tasks.push_back(Task);
    for(const std::string x: Tasks){
        std::cout<< x;
    }
}
        


int main(int argc,char* argv[]){
        

    if(argc < 2){
        std::cerr<<"Error: No Arguments provided.\n";
        show_help();
        return 1;
    }
//    for(int i = 0; i < argc; i++){
 //       std::cout<<"Argument: "<< argv[i] <<std::endl;
  //  }      
    
    if(strcmp(argv[1] , "add")==0){
       if(argv[2]!= NULL)
           add(argv[2]); 
       else
           show_help();

    } 


}

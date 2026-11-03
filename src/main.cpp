#include <iostream>
#include "Interface.hpp"
#include "TaskGenerator.hpp"

int main() 
{
    TaskGenerator generator;
    int choice = 1;
    
    while(choice != 0)
    {
        Interface::printMenu();
        choice = Interface::getChoice();

        switch(choice)
        {
            default:
                std::cout << "Invalid choice. Please repeat.\n";
                break;
            case 0: return 0;
            case 1:
                if (!generator.hasTasks())
                {
                    std::cout << "No tasks loaded. Please load tasks from file first.\n";
                    break;
                }
                std::cout << "Generating variants...\n";
                break;
            case 2:
                if (generator.loadTasksFromFile("data/tasks.txt"))
                {
                    std::cout << "Tasks loaded successfully.\n";
                    std::cout << "Total tasks loaded: " << generator.getTaskCount() << '\n';
                }
                else
                {
                    std::cout << "Failed to load tasks from file.\n";
                }
                break;
        }
    }

    return 0;
}
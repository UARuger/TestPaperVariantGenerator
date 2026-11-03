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
            {
                if (!generator.hasTasks())
                {
                    std::cout << "No tasks loaded. Please load tasks from file first.\n";
                    break;
                }

                int variantCount = Interface::getNumber("Enter the number of variants to generate: ");
                int tasksPerVariant = Interface::getNumber("Enter the number of tasks per variant: ");

                if (!generator.validateParameters(variantCount, tasksPerVariant))
                {
                    std::cout << "Invalid generation parameters.\n";
                    break;
                }
                
                std::cout << "Generating " << variantCount << " variants with " << tasksPerVariant << " tasks each...\n";
                
                for (int i = 0; i < variantCount; ++i)
                {
                    std::vector<std::string> variant = generator.generateVariant(tasksPerVariant);
                    Interface::printVariant(variant, i + 1);
                }
                break;
            }
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
#include <iostream>
#include "Interface.hpp"

int main() 
{
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
                std::cout << "Generating variants...\n";
                break;
        }
    }

    return 0;
}
#include "Interface.hpp"
#include <limits>

void Interface::printMenu()
{
    printf(
        "=== Task Generator ===\n"
        "0. Exit\n"
        "1. Generate variants\n"
        "2. Load tasks from file\n"
        "======================\n"
    );
}

int Interface::getChoice()
{
    int choice = 0;
    printf("Enter your choice: ");
    std::cin >> choice;
    return choice;
}

int Interface::getNumber(const std::string& message)
{
    int number;
    
    std::cout << message;
    if (!(std::cin >> number))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid number.\n";

        return 0;
    }

    return number;
}
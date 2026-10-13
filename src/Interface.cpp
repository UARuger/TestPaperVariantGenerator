#include "Interface.hpp"

void Interface::printMenu()
{
    printf(
        "=== Task Generator ===\n"
        "0. Exit\n"
        "1. Generate variants\n"
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
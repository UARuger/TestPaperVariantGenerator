#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace Interface
{
    void printMenu();
    int getChoice();
    int getNumber(const std::string& message);
    void printVariant(const std::vector<std::string>& tasks, int number);
}

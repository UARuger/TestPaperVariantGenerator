#pragma once

#include <iostream>
#include <string>

namespace Interface
{
    void printMenu();
    int getChoice();
    int getNumber(const std::string& message);
}

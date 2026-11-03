#pragma once

#include <string>
#include <vector>

class TaskGenerator
{
private:
    std::vector<std::string> tasks;

public:
    TaskGenerator();
    bool loadTasksFromFile(const std::string& filename);
};
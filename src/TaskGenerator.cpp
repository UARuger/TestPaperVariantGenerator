#include "TaskGenerator.hpp"
#include <fstream>

TaskGenerator::TaskGenerator()
{

}

bool TaskGenerator::loadTasksFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    
    if (!file.is_open())
    {
        return false;
    }

    tasks.clear();

    std::string line;
    while (std::getline(file, line))
    {
        if (!line.empty())
        {
            tasks.push_back(line);
        }
    }

    return true;
}

std::size_t TaskGenerator::getTaskCount() const
{
    return tasks.size();
}

bool TaskGenerator::hasTasks() const
{
    return !tasks.empty();
}
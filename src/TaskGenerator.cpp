#include "TaskGenerator.hpp"
#include <fstream>
#include <random>
#include <algorithm>

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

bool TaskGenerator::validateParameters(int variantCount, int tasksPerVariant) const
{
    if (variantCount <= 0 || tasksPerVariant <= 0)
    {
        return false;
    }

    if (static_cast<std::size_t>(tasksPerVariant) > tasks.size())
    {
        return false;
    }

    return true;
}

std::vector<std::string> TaskGenerator::generateVariant(int count)
{
    std::vector<std::string> result = tasks;

    std::random_device rd;
    std::mt19937 generator(rd());
    
    std::shuffle(result.begin(), result.end(), generator);

    result.resize(count);

    return result;
}
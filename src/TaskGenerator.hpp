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
    std::size_t getTaskCount() const;
    bool hasTasks() const;
    bool validateParameters(int variantCount, int tasksPerVariant) const;
    std::vector<std::string> generateVariant(int count);
};
#include "ExpenseFileHandler.h"

// for future: dependency injection

ExpenseFileHandler::ExpenseFileHandler()
    
{
}
/*
FileExporter::~FileExporter()
{
}
*/
IOStatus ExpenseFileHandler::saveToFile(const std::vector<Expense> &expenses, const std::string &filename)
{
    std::ofstream file(filename);


    if (!file.is_open())
    {
        return FILE_NOT_OPEN;
    }

    file << "Amount [zl]" << "," << "Description" << "\n";
    for (const auto &e : expenses)
    {
        file <<e.amount << "," << e.description << "\n";
    }
   

    file.close();
    return SUCCESS;
}


IOStatus ExpenseFileHandler::loadFromFile(std::vector<Expense>& expenses, const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        return FILE_NOT_OPEN;
    }
    
    std::string line;
    bool isFirstLine = true;

    while (std::getline(file, line))
    {
        if (isFirstLine) {
            isFirstLine = false;
            continue;
        }

        std::istringstream ss(line);
        std::string amountStr, description;

        if (!std::getline(ss, amountStr, ',')) continue;
        if (!std::getline(ss, description)) continue;

        try {
            double amount = std::stod(amountStr);
            expenses.emplace_back(Expense{amount, description});
        } catch (const std::exception&) {
            // Możesz dodać log błędu lub zwrócić kod błędu
            continue;
        }
    }
    file.close();
    return SUCCESS;    
}
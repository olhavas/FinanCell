#include "ExpenseManager.h"



ExpenseManager::ExpenseManager(IFileHandler& fhandler)
            : fileHandler(fhandler)
{
    expences = std::vector<Expense>();
    validator = ExpenseValidator();
    handler = UserInputHandler();

}

ValidationStatus ExpenseManager::addExpense(const Expense& expense)
{
    if (!validator.isValidDescription(expense.description))
    {
        return DESCRIPTION_NOT_VALID;
    }
        
    expences.push_back(expense);
    return VALID;
}

const std::vector<Expense>& ExpenseManager::getExpenses() const 
{
    return expences;    
}

double ExpenseManager::sumUpExpeses()
{
    double sum = 0.0;
    for (const auto &expence : expences)
    {
        sum += expence.amount;
    }
    return sum;
}

IOStatus ExpenseManager::loadExpensesFromFile(std::string path)
{
    return fileHandler.loadFromFile(expences, path);
}

IOStatus ExpenseManager::saveExpensesToFile(std::string filenamepath)
{
    return fileHandler.saveToFile(expences, filenamepath);
}
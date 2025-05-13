#ifndef ExpenseManager_h
#define ExpenseManager_h

#include <vector> 
#include <iostream>

#include "Exceptions.h" 
#include "Expense.h"
#include "ExpenseValidator.h"
#include "UserInputHandler.h"
#include "IExpenseManager.h"
#include "IFileHandler.h"
#include "TextFormatter.h"
#include "ExpenseFormatter.h"

namespace fs = std::filesystem;


class ExpenseManager : public IExpenseManager 
{
    private:
        std::vector<Expense> expences;
        UserInputHandler handler;
        ExpenseValidator validator;
        IFileHandler& fileHandler;
        double safeReadAmount();
    public:
        ExpenseManager(IFileHandler& fhandler);
        ValidationStatus addExpense(const Expense& expense) override;
        const std::vector<Expense>& getExpenses() const override;
        IOStatus saveExpensesToFile(std::string filenamepath) override;
        IOStatus loadExpensesFromFile(std::string path) override;
        double sumUpExpeses();
};


#endif /* ExpenseManager_h */
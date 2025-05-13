#ifndef IExpenseManager_h
#define IExpenseManager_h

#include "Status.h"

class IExpenseManager {
public:
    virtual const std::vector<Expense>& getExpenses() const = 0;
    virtual ValidationStatus addExpense(const Expense& ) = 0;
    virtual IOStatus saveExpensesToFile(std::string ) = 0;
    virtual IOStatus loadExpensesFromFile(std::string ) = 0;
    virtual ~IExpenseManager() = default;
};

#endif
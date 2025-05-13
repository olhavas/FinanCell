#ifndef ExpenseFormatter_h
#define ExpenseFormatter_h
#include <string>
#include <sstream>
#include <iomanip>
#include "Expense.h"

class ExpenseFormatter {
public:
    static std::string format(const Expense& expense);
};

#endif
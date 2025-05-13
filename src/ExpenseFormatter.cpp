#include "ExpenseFormatter.h"


std::string ExpenseFormatter::format(const Expense& expense)
{
    std::ostringstream oss;
    oss << expense.description<<" : "<<std::fixed << std::setprecision(2) << expense.amount<<"\n" ;
    return oss.str();
}
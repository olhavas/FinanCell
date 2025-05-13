#ifndef ExpenseFileHandler_h
#define ExpenseFileHandler_h



#include "Expense.h"
#include "IFileHandler.h"


namespace fs = std::filesystem;

class ExpenseFileHandler : public IFileHandler
{
private:
    /* data */
    
public:
    ExpenseFileHandler();
    ~ExpenseFileHandler() = default;
    IOStatus saveToFile(const std::vector<Expense>& expenses, const std::string& filename) override;
    IOStatus loadFromFile(std::vector<Expense>& expenses, const std::string& filename)override;
};




#endif
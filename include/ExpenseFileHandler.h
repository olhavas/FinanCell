#ifndef ExpenseFileHandler_h
#define ExpenseFileHandler_h

#include <memory>

#include "Expense.h"
#include "IFileHandler.h"
#include "IExportStrategy.h"
#include "Logger.h"


namespace fs = std::filesystem;

class ExpenseFileHandler : public IFileHandler
{
private:
    std::unique_ptr<IExportStrategy> strategy;
    /* data */
    
public:
    ExpenseFileHandler(std::unique_ptr<IExportStrategy> s);
    ~ExpenseFileHandler() = default;
    IOStatus saveToFile(const std::vector<Expense>& expenses, const std::string& filename) override;
    IOStatus loadFromFile(std::vector<Expense>& expenses, const std::string& filename)override;
};




#endif
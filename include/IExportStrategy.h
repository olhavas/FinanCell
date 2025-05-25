#ifndef IExportStrategy_h
#define IExportStrategy_h
#include <vector>
#include <fstream>
#include <filesystem>
#include "Expense.h"
#include "Status.h"



class IExportStrategy {
public:
    virtual IOStatus save(const std::vector<Expense>& expenses, const std::string& filename) = 0;
    virtual ~IExportStrategy() = default;
};

#endif
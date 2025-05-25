#ifndef CSVExportStrategy_h
#define CSVExportStrategy_h


#include "IExportStrategy.h"



class CSVExportStrategy : public IExportStrategy 
{
public:
    IOStatus save(const std::vector<Expense>& expenses, const std::string& filename) override;
};

#endif
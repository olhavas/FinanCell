#include "CSVExportStrategy.h"

IOStatus CSVExportStrategy::save(const std::vector<Expense>& expenses, const std::string& filename)
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
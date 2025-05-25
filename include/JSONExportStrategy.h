#ifndef JSONExportStrategy_h
#define JSONExportStrategy_h

#include <nlohmann/json.hpp> // biblioteka json
#include "IExportStrategy.h"

using json = nlohmann::json;


class JSONExportStrategy : public IExportStrategy
{
public:
    virtual IOStatus save(const std::vector<Expense>& expenses, const std::string& filename) override;
};

#endif
#include "JSONExportStrategy.h"

IOStatus JSONExportStrategy::save(const std::vector<Expense>& expenses, const std::string& filename)
{
    std::ofstream file(filename);

    if (!file.is_open())
    {
        return FILE_NOT_OPEN;
    }

    json jExpenses = json::array();
    for (const auto& e : expenses) {
        json j;
        j["amount"] = e.amount;
        j["description"] = e.description;
        jExpenses.push_back(j);
    }

    file << jExpenses.dump(4); // formatowanie JSON, 4 spacje wcięcia
   

    file.close();
    return SUCCESS;
}
#include "ExpenseManager.h"
#include "UserInterface.h"
#include "ExpenseFileHandler.h"
#include "CSVExportStrategy.h"
#include "JSONExportStrategy.h"

int main()
{

    ExpenseFileHandler fileHandler(std::make_unique<JSONExportStrategy>());
    ExpenseManager manager(fileHandler);
    UserInterface UI(manager);
    UI.run();
    return 0;
}


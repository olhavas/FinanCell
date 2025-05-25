#include "ExpenseManager.h"
#include "UserInterface.h"
#include "ExpenseFileHandler.h"
#include "CSVExportStrategy.h"

int main()
{

    ExpenseFileHandler fileHandler(std::make_unique<CSVExportStrategy>());
    ExpenseManager manager(fileHandler);
    UserInterface UI(manager);
    UI.run();
    return 0;
}


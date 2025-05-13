#include "ExpenseManager.h"
#include "UserInterface.h"
#include "ExpenseFileHandler.h"

int main()
{

    
    ExpenseFileHandler fileHandler;
    ExpenseManager manager(fileHandler);
    UserInterface UI(manager);
    UI.run();
    return 0;
}


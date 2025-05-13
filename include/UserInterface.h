#ifndef UserInterface_h
#define UserInterface_h


#include "ExpenseValidator.h"
#include "ExpenseManager.h"


class UserInterface
{
private:
    int option;
    IExpenseManager &manager;
    UserInputHandler uiHandler;
    bool exit;
    
public:
    UserInterface(IExpenseManager &manager);
    ~UserInterface() = default;
    void showMenu();
    void chooseOption();
    void showExpenses(const std::vector<Expense>&);
    void run();
    std::string getFilenameFromUser();
};

#endif
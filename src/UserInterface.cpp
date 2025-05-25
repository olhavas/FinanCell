#include "UserInterface.h"

UserInterface::UserInterface(IExpenseManager &manager) : manager(manager)
{
    this->uiHandler = UserInputHandler();
    this->exit = false;
}

/**
 * Funtion lists operations available in app.
 * Return type: void
 * Input: None
 **/
void UserInterface::showMenu()
{
    uiHandler.output("=== Personal Finance Manager ===\n");
    uiHandler.output("1. Add Expense\n");
    uiHandler.output("2. Show All Expenses\n");
    uiHandler.output("3. Save Expenses to file\n");
    uiHandler.output("4. Exit\n");
}
void UserInterface::showExpenses(const std::vector<Expense>& expences)
{
    uiHandler.output("\n--- Expense List ---\n");
    for (const auto &expence : expences)
    {
        uiHandler.output(ExpenseFormatter::format(expence));
    }
}

void UserInterface::chooseOption()
{   
  
    option = UserInputHandler::getValidatedOption("Choose option: ");
    double amount;
    std::string description = "";  
    std::string directory = "", filename = "", fullpath = "";

    switch (option)
    {
    case 1:

        amount = UserInputHandler::getValidatedAmount("Enter expense amount: ");
        description = UserInputHandler::getStringInput("Enter description: ");
        
        if(ValidationStatus::DESCRIPTION_NOT_VALID ==
                    manager.addExpense(Expense{amount, description}))
        {
            uiHandler.output("Description cannot be empty.\n");
        }

        uiHandler.output("Amount: " + std::to_string(amount) + " zl\n");
        break;
    case 2:        
        showExpenses(manager.getExpenses());
        break;
    case 3:
        directory= UserInputHandler::getStringInput("Please provide directory to save (for default directory press ENTER): ");

        if(directory.empty())
        {
            directory = "resources";
        }
        filename = UserInputHandler::getStringInput("Please provide name of file to save (for default name of file press ENTER): ");

        if(filename.empty())
        {
            filename = "expenses.csv";
        }
        fullpath = directory + "/"+filename;

        if (!directory.empty() && !fs::exists(directory)) {
        fs::create_directories(directory);}

        if(IOStatus::SUCCESS == manager.saveExpensesToFile(fullpath)) 
        {
            uiHandler.output("Expenses saved to file: "+fullpath +"\n");
        }
        else
        {
            uiHandler.output("Error: Cannot open file to save.\n");
            uiHandler.error("Cannot open file to save.\n");
        }
        break;
    case 4:
        this->exit = true;
        break;
    default:
        uiHandler.output("Invalid option!");        
        break;
    }
}

void UserInterface::run()
{
    Logger::instance()->log(INFO, "Entry." );
    std::string path= "resources/expenses.csv";
    if(SUCCESS != manager.loadExpensesFromFile(path))
    {
        uiHandler.output("Error: Cannot recover data from file.\n");
        Logger::instance()->log(ERROR, "Cannot recover data from file." );

    }
    while (!exit)
    {
        showMenu();
        chooseOption();
    }
    if(exit)
    {
        Logger::instance()->log(INFO, "Exit." );
    }
}

std::string UserInterface::getFilenameFromUser()
{
    return uiHandler.getStringInput("If you have a custom file to load data from: ");
}
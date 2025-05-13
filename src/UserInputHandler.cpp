#include <UserInputHandler.h>

std::string UserInputHandler::input()
{
    std::cin.ignore();
    std::string input;
    std::getline(std::cin, input);
    return input;
}
void UserInputHandler::output(const std::string & s)
{
    std::cout<<s;
}

void UserInputHandler::end()
{
    std::cout<<'\n';
}

void UserInputHandler::error(const std::string & s)
{
    std::cerr<<"[ERROR] "<<s;
}

std::string UserInputHandler::getStringInput(const std::string& prompt) {
    std::cout << prompt;
    std::string input;
    std::getline(std::cin, input);
    return input;
}

double UserInputHandler::getValidatedAmount(const std::string& prompt) {
    while (true) {
        std::string input = getStringInput(prompt);
        try {
            size_t pos;
            double amount = std::stod(input, &pos);
            if (pos == input.length()) {
                return amount;
            } else {
                std::cout << "Invalid input. Please enter a number.\n";
            }
        } catch (...) {
            std::cout << "Invalid input. Please enter a number.\n";
        }
    }
}

int UserInputHandler::getValidatedOption(const std::string& prompt)
{
    while (true) {
        std::string input = getStringInput(prompt);
        try {
            int option = std::stoi(input);
            
            return option;
            
        } catch (...) {
            std::cout << "Invalid input. Please enter a number.\n";
        }
    }
}


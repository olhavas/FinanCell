#include "ExpenseValidator.h"


bool ExpenseValidator::isValidAmount(const std::string& input) {
    try {
        double amount = std::stod(input);  // rzuci wyjątkiem jeśli błąd
        return amount > 0.0;
    } catch (...) {
        return false;
    }
}

bool ExpenseValidator::isValidDescription(const std::string& desc) {
    return !desc.empty();
}
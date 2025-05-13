#ifndef ExpenseValidator_h
#define ExpenseValidator_h

#include <string>

class ExpenseValidator
{
public:
    bool isValidAmount(const std::string& input);

    bool isValidDescription(const std::string &desc);
};

#endif
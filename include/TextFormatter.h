#ifndef TextFormatter_h
#define TextFormatter_h
#include <string>
#include <sstream>
#include <iomanip>

class TextFormatter {
public:
    // Format amount to string with 2 decimal places and currency
    static std::string formatAmount(double amount, const std::string& currency = "zł");

    // Format a label-value pair: "Amount: 120.50 zł"
    static std::string formatLabel(const std::string& label, double value, const std::string& currency = "zł");

    // Generic label with string value
    static std::string formatLabel(const std::string& label, const std::string& value);
};

#endif
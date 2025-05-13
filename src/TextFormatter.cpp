#include "TextFormatter.h"

std::string TextFormatter::formatAmount(double amount, const std::string& currency) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << amount << " " << currency;
    return oss.str();
}

std::string TextFormatter::formatLabel(const std::string& label, double value, const std::string& currency) {
    return label + ": " + formatAmount(value, currency)+'\n';
}

std::string TextFormatter::formatLabel(const std::string& label, const std::string& value) {
    return label + ": " + value+'\n';
}
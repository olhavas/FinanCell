#include <gtest/gtest.h>
#include "ExpenseFileHandler.h"
#include "CSVExportStrategy.h"

TEST(ExpenseFileHandlerTest, SaveToFileCreatesFile) {
    ExpenseFileHandler handler(std::make_unique<CSVExportStrategy>());
    std::vector<Expense> expenses = { {123.45, "Lunch"} };
    std::string filename = "resources/test.csv";

    auto status = handler.saveToFile(expenses, filename);

    EXPECT_EQ(status, IOStatus::SUCCESS);

    EXPECT_TRUE(std::filesystem::exists(filename));


    std::ifstream file(filename);
    std::string line;

    std::getline(file, line); 
    EXPECT_EQ(line, "Amount [zl],Description");
    std::getline(file, line);
    EXPECT_EQ(line, "123.45,Lunch");

    // Sprzątanie po teście
    std::filesystem::remove(filename);
}
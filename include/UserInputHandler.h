#ifndef UserInputHandler_h
#define UserInputHandler_h
#include <iostream>



class UserInputHandler 
{
    public:
    std::string input();
    void output(const std::string & s);
    void error(const std::string & s);
    void end();
    static std::string getStringInput(const std::string& prompt);
    static double getValidatedAmount(const std::string& prompt);
    static int getValidatedOption(const std::string& prompt);
    
};

#endif
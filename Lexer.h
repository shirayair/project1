//
// Created by shira on 12/19/18.
//

#ifndef EX3_LEXER_H
#define EX3_LEXER_H
#include <string>
#include <vector>


typedef std::string::iterator stritr;
class Lexer {
    std::string fileName;

public:
    Lexer(string fileName);
    std::vector<std::string> readFromScript();
    std::vector<std::string> toEnterAccording(std::string line);
    bool isDigit(char c);
    bool ifToSeperate(char c,char s);
    bool isOperator(char c);
    std::vector<std::string>  seperateVector(std::vector<std::string> scriptSpleet);
    bool isSign(char c);
};


#endif //EX3_LEXER_H

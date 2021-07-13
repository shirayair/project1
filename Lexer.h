//
// Created by shira on 12/19/18.
//

#ifndef EX3_LEXER_H
#define EX3_LEXER_H
#include <string>
#include <vector>

using namespace std;
typedef string::iterator stritr;
class Lexer {
    string fileName;

public:
    Lexer(string fileName);
    vector<string> readFromScript();
    vector<string> toEnterAccording(string line);
    bool isDigit(char c);
    bool ifToSeperate(char c,char s);
    bool isOperator(char c);
    vector<string>  seperateVector(vector<string> scriptSpleet);
    bool isSign(char c);
};


#endif //EX3_LEXER_H

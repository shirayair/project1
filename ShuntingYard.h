//
// Created by shira on 12/19/18.
//

#ifndef EX3_SHUNTINGYARD_H
#define EX3_SHUNTINGYARD_H
#include <string>
#include <map>
#include "Expression.h"
#include "stack"
#include "SymTbl.h"

using namespace std;


class ShuntingYard {
    SymTbl* expVar;
    map<char, int> prcedence;
public:

    ShuntingYard(SymTbl* expVar);
    ~ShuntingYard() = default;
    void initializeMap();

    int precedence(char operation);
    Expression *createExpression(string tokens);
    Expression* applyOp(Expression* val1,Expression*  val2,char operation);
};

#endif //EX3_SHUNTINGYARD_H

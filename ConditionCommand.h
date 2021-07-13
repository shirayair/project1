//
// Created by osnat on 12/26/18.
//

#ifndef EX3_CONDITIONCOMMAND_H
#define EX3_CONDITIONCOMMAND_H


#include <list>
#include "Command.h"
#include "SymTbl.h"
#include "Expression.h"
#include "CommandExpression.h"

class ConditionCommand: public Command {
    Expression* exp1;
    Expression* exp2;
    string sign;

protected:
    list<Expression*> commands;
    bool checkCondition();
public:
    ConditionCommand(Expression* exp1, Expression* exp2, string sign);
    void addCommand(list<Expression*> commands);
    virtual ~ConditionCommand();
};


#endif //EX3_CONDITIONCOMMAND_H

//
// Created by shira on 12/23/18.
//

#ifndef EX3_COMMANDEXPRESSION_H
#define EX3_COMMANDEXPRESSION_H

#include "Command.h"
#include "Expression.h"

class CommandExpression : public Expression
{
    Command* c = nullptr;

public:
    CommandExpression(Command* command);
    ~CommandExpression();
    double calculate();
};

#endif // EX3_COMMANDEXPRESSION_H

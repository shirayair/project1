//
// Created by shira on 12/19/18.
//

#ifndef EX3_WHILECOMMAND_H
#define EX3_WHILECOMMAND_H


#include "Command.h"
#include "Expression.h"
#include "ConditionCommand.h"
#include <vector>
class WhileCommand : public ConditionCommand{
public:
    WhileCommand(Expression* exp1, Expression* exp2, string sign);
    void execute() override;
};
#endif //EX3_WHILECOMMAND_H

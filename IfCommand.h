//
// Created by osnat on 12/26/18.
//

#ifndef EX3_IFCOMMAND_H
#define EX3_IFCOMMAND_H


#include "ConditionCommand.h"

class IfCommand: public ConditionCommand {
public:
    IfCommand(Expression* exp1, Expression* exp2, string sign);
    void execute() override;
};


#endif //EX3_IFCOMMAND_H

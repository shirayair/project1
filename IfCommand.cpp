//
// Created by osnat on 12/26/18.
//

#include "IfCommand.h"

IfCommand::IfCommand(Expression *exp1, Expression *exp2,
        string sign) :ConditionCommand(exp1, exp2, sign) {
}

void IfCommand::execute() {
    if (checkCondition()) {
        for(auto c: commands) {
            c->calculate();
        }
    }
}

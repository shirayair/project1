//
// Created by shira on 12/19/18.
//

#include "WhileCommand.h"


WhileCommand::WhileCommand( Expression *exp1,
        Expression *exp2, string sign) :ConditionCommand(exp1,exp2, sign) {
}

void WhileCommand::execute() {
    while (checkCondition()) {
        for(auto c: commands) {
            c->calculate();
        }
    }
}
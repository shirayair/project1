//
// Created by osnat on 12/26/18.
//

#include "ConditionCommand.h"

ConditionCommand::ConditionCommand(Expression* exp1, Expression* exp2, string sign){
    this->exp1 = exp1;
    this->exp2 = exp2;
    this->sign = sign;
}
ConditionCommand::~ConditionCommand() {
    delete this->exp1;
    delete this->exp2;
    for (auto c : this->commands) {
        delete c;
    }
}





bool ConditionCommand::checkCondition() {
    double val1 = exp1->calculate();
    double val2 = exp2->calculate();
    if(sign == "<=" && val1 <= val2) {
        return true;
    }
    if(sign == ">=" && val1 >= val2) {
        return true;
    }
    if(sign == "<" && val1 < val2) {
        return true;
    }
    if(sign == ">" && val1 > val2) {
        return true;
    }
    if(sign == "==" && val1 == val2) {
        return true;
    }
    if(sign == "!=" && val1 != val2) {
        return true;
    }
    return false;
}

void ConditionCommand::addCommand(list<Expression*> commands) {
    this->commands = commands;
}
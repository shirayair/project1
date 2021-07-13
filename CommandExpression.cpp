//
// Created by shira on 12/23/18.
//

#include "CommandExpression.h"
CommandExpression::CommandExpression(Command *command) {
    this->c = command;

}

double CommandExpression:: calculate(){
    c->execute();
}

CommandExpression::~CommandExpression() {
    if(this->c != nullptr) {
        delete this->c;
    }
}
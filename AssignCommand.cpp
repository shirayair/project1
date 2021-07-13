//
// Created by osnat on 12/26/18.
//

#include "AssignCommand.h"
#include "ShuntingYard.h"

AssignCommand::AssignCommand(SymTbl *symTbl1, string symName, Expression* symValue) {
    this->symTbl = symTbl1;
    this->symName = symName;
    this->symValue = symValue;
}

void AssignCommand::execute() {
    double enterVal = this->symValue->calculate();
    SymVal* symVal1 = this->symTbl->getSymbol(this->symName);
    symVal1->setVal(enterVal);
}

AssignCommand::~AssignCommand() {
    delete this->symValue;
}
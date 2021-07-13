//
// Created by osnat on 12/26/18.
//

#ifndef EX3_ASSIGNCOMMAND_H
#define EX3_ASSIGNCOMMAND_H


#include "SymTbl.h"
#include "Command.h"
#include "Expression.h"

class AssignCommand: public Command {
    SymTbl* symTbl;
    string symName;
    Expression* symValue;

public:
    AssignCommand(SymTbl* symTbl1, string symName, Expression* symValue);
    void execute() override;
    ~AssignCommand();

};


#endif //EX3_ASSIGNCOMMAND_H

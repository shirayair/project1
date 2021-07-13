//
// Created by osnat on 12/26/18.
//

#ifndef EX3_DEFINEVARCOMMAND_H
#define EX3_DEFINEVARCOMMAND_H


#include "Command.h"
#include "SymTbl.h"
#include "Expression.h"
#include "FSParamMap.h"

class DefineVarCommand: public Command {
    SymTbl* symTbl;
    string varName;
    Expression* varVal = nullptr;
    string PointerName ="";
    string path = "";
    FSParamMap* fsParamMap1;

public:
    DefineVarCommand(SymTbl *symTbl, string varName, string PointerName);
    DefineVarCommand(SymTbl *symTbl, string varName, string path,FSParamMap* fsParamMap1);
    DefineVarCommand(SymTbl *symTbl, string varName, Expression* varVal);
    void execute() override;
    ~DefineVarCommand();
};


#endif //EX3_DEFINEVARCOMMAND_H

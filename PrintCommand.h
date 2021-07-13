//
// Created by osnat on 12/29/18.
//

#ifndef EX3_PRINTCOMMAND_H
#define EX3_PRINTCOMMAND_H


#include "Command.h"
#include "SymTbl.h"

class PrintCommand : public Command{
    string str;
    SymTbl* symTbl;
public:
    PrintCommand(string str, SymTbl* symTbl);
    void execute()override;
};


#endif //EX3_PRINTCOMMAND_H

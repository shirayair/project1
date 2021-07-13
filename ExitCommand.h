//
// Created by osnat on 12/27/18.
//

#ifndef EX3_EXITCOMMAND_H
#define EX3_EXITCOMMAND_H


#include "Command.h"

class ExitCommand: public Command {

public:
    void execute() override;
};


#endif //EX3_EXITCOMMAND_H

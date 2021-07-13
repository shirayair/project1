//
// Created by shira on 12/28/18.
//

#ifndef EX3_CONNECTCOMMAND_H
#define EX3_CONNECTCOMMAND_H

#include "Client.h"
#include "Command.h"
#include "Expression.h"

class ConnectCommand :public Command {
    string ip;
    Expression* port;
public:
    ConnectCommand(string ip, Expression* port);
    ~ConnectCommand();
     void execute();
};


#endif //EX3_CONNECTCOMMAND_H

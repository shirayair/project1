//
// Created by shira on 12/19/18.
//

#ifndef EX3_OPENDATASERVER_H
#define EX3_OPENDATASERVER_H
#include "Command.h"
#include "Expression.h"
#include "FSParamMap.h"
#include <pthread.h>

class OpenDataServerCommand : public Command {
    Expression* port;
    Expression* hertz;
    FSParamMap* fsParamMap;

public:
    OpenDataServerCommand(Expression* p, Expression* h, FSParamMap* fsParamMap);
    void execute() override;
    ~OpenDataServerCommand();
};

#endif //EX3_OPENDATASERVER_H

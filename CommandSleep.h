//
// Created by shira on 12/19/18.
//

#ifndef EX3_COMANDSLEEP_H
#define EX3_COMANDSLEEP_H

#include "string.h"
#include "Command.h"
#include "Expression.h"
#include <chrono>
#include <thread>
class CommandSleep :public Command{
    Expression* sleep;
public:
    explicit CommandSleep(Expression* sleep);
    ~CommandSleep();
    void execute() override;

};


#endif //EX3_COMANDSLEEP_H

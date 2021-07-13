//
// Created by shira on 12/19/18.
//

#ifndef EX3_COMMAND_H
#define EX3_COMMAND_H

#include <string>
#include <vector>

using namespace std;

class Command{
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

#endif //EX3_COMMAND_H

//
// Created by shira on 12/19/18.
//

#include "OpenDataServerCommand.h"

#include "Server.h"

#include <chrono>
#include <iostream>
#include <netinet/in.h>
#include <thread>
#include <unistd.h>

#define MAX_NUMBER 300
int server_fdGlobal;
// extern bool connectedGame;

OpenDataServerCommand::OpenDataServerCommand(Expression* p, Expression* h, FSParamMap* fsParamMap)
{
    this->port = p;
    this->hertz = h;
    this->fsParamMap = fsParamMap;
}

OpenDataServerCommand::~OpenDataServerCommand()
{
    delete this->port;
    delete this->hertz;
}
void OpenDataServerCommand::execute()
{
    int port1 = (int)this->port->calculate();
    int hertz1 = (int)this->hertz->calculate();
    Server::run(port1, hertz1, fsParamMap);
}

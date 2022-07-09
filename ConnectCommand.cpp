//
// Created by shira on 12/28/18.
//

#include "ConnectCommand.h"

#include <iostream>
ConnectCommand ::ConnectCommand(string ip, Expression *port)
{
    this->ip = ip;
    this->port = port;
}
ConnectCommand::~ConnectCommand()
{
    delete this->port;
}
void ConnectCommand::execute()
{
    int int_port = (int)this->port->calculate();
    cout << "Please enter char only when simulator is on." << endl;
    cin.ignore();
    Client::connectClient(this->ip, int_port);
}
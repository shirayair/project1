//
// Created by osnat on 12/27/18.
//

#include "ExitCommand.h"
#include "Client.h"
#include "Server.h"

void ExitCommand::execute() {
    Client::closeClient();
    Server::stop();
}
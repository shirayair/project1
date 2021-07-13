//
// Created by osnat on 12/27/18.
//

#ifndef EX3_CLIENT_H
#define EX3_CLIENT_H

#include <string>

using  namespace std;

class Client {
    static int socket_id;
public:
    static void connectClient(string ip, int port);
    static void send(string path, double value);
    static void closeClient();
};


#endif //EX3_CLIENT_H

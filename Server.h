//
// Created by osnat on 12/29/18.
//

#ifndef EX3_SERVER_H
#define EX3_SERVER_H


#include <sys/types.h>
#include "FSParamMap.h"

struct arg_struct {
    FSParamMap *fsParamMap_args;
    int socket_args;
};

class Server {

public:
    static bool sould_stop;
    static pthread_t pthreadID;
    static void run(int port, int herz, FSParamMap* fsParamMap);
    static void stop();

};



#endif //EX3_SERVER_H

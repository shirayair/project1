////
//// Created by shira on 12/19/18.
////

#include <unistd.h>
#include <chrono>
#include <thread>
#include "CommandSleep.h"

CommandSleep::CommandSleep(Expression* sleep) {
    this->sleep = sleep;
}

CommandSleep:: ~CommandSleep(){
    delete this->sleep;
}

void CommandSleep::execute(){
/*    auto milsecs = (__useconds_t) this->sleep->calculate();
    usleep(milsecs);*/
    int millisec = static_cast<int>(this->sleep->calculate());
    this_thread::sleep_for(chrono::milliseconds(millisec));
}

////
//// Created by shira on 12/19/18.
////

#include "CommandSleep.h"

#include <chrono>
#include <thread>
#include <unistd.h>

CommandSleep::CommandSleep(Expression* sleep)
{
    this->sleep = sleep;
}

CommandSleep::~CommandSleep()
{
    delete this->sleep;
}

void CommandSleep::execute()
{
    /*    auto milsecs = (__useconds_t) this->sleep->calculate();
        usleep(milsecs);*/
    int millisec = static_cast<int>(this->sleep->calculate());
    this_thread::sleep_for(chrono::milliseconds(millisec));
}

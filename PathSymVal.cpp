//
// Created by osnat on 12/26/18.
//

#include <thread>
#include "PathSymVal.h"


PathSymVal::PathSymVal(string path, FSParamMap *fsParamMap1) {
    this->path = path;
    this->fsParamMap = fsParamMap1;
}
double PathSymVal:: getVal(){
    return this->fsParamMap->getVal(path);
}
//client
void PathSymVal:: setVal(double value){
    Client::send(path,value);

}
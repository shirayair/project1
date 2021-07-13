//
// Created by osnat on 12/26/18.
//

#ifndef EX3_FSPARAMMAP_H
#define EX3_FSPARAMMAP_H

#define BUFFER_SIZE 1024
#include <map>
#include <pthread.h>
#include <vector>
using namespace std;

class FSParamMap {
    map<string, double> pathMap;
    pthread_mutex_t tex;

public:
    FSParamMap();
    ~FSParamMap();
    double getVal(string path);
    bool parsBuffer(string& buff2);
    void inserToMap(vector<double>& fromXML);
};


#endif //EX3_FSPARAMMAP_H

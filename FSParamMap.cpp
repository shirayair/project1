//
// Created by osnat on 12/26/18.
//

#include <sstream>
#include "FSParamMap.h"
FSParamMap::FSParamMap(){
    pthread_mutex_init(&this->tex, nullptr);
    this->pathMap["/instrumentation/heading-indicator/offset-deg"] = 0;

}

FSParamMap::~FSParamMap(){
    pthread_mutex_destroy(&this->tex);
}

bool FSParamMap::parsBuffer(string& buff2) {
    std::vector<double> vect;
    int n= 0;
    int i = 0;
    for(; i < buff2.length(); i++) {
        if (buff2[i] == '\n') {
            n = i;
            break;
        }
    }
    if( i == buff2.length()) {
        return false;
    }

    std::stringstream ss(buff2);
    double d;
    while (ss >> d && vect.size() <= 22)
    {
        vect.push_back(d);
        if (ss.peek() == ',')
            ss.ignore();
    }

    buff2 = buff2.substr(n+1, buff2.length()-n-1);

    inserToMap(vect);
    return true;

}

double FSParamMap:: getVal(string path){
    pthread_mutex_lock(&this->tex);
    auto x = this->pathMap[path];
    pthread_mutex_unlock(&this->tex);
    return x;
}


void FSParamMap::inserToMap(vector<double>& vector){
    pthread_mutex_lock(&this->tex);
    this->pathMap["/instrumentation/airspeed-indicator/indicated-speed-kt"] = vector[0];
    this->pathMap["/instrumentation/altimeter/indicated-altitude-ft"] = vector[1];
    this->pathMap["/instrumentation/altimeter/pressure-alt-ft"] = vector[2];
    this->pathMap["/instrumentation/attitude-indicator/indicated-pitch-deg"] = vector[3];
    this->pathMap["/instrumentation/attitude-indicator/indicated-roll-deg"] = vector[4];
    this->pathMap["/instrumentation/attitude-indicator/internal-pitch-deg"] = vector[5];
    this->pathMap["/instrumentation/attitude-indicator/internal-roll-deg"] = vector[6];
    this->pathMap["/instrumentation/encoder/indicated-altitude-ft"] = vector[7];
    this->pathMap["/instrumentation/encoder/pressure-alt-ft"] = vector[8];
    this->pathMap["/instrumentation/gps/indicated-altitude-ft"] = vector[9];
    this->pathMap["/instrumentation/gps/indicated-ground-speed-kt"] = vector[10];
    this->pathMap["/instrumentation/gps/indicated-vertical-speed"] = vector[11];
    this->pathMap["/instrumentation/heading-indicator/indicated-heading-deg"] = vector[12];
    this->pathMap["/instrumentation/magnetic-compass/indicated-heading-deg"] = vector[13];
    this->pathMap["/instrumentation/slip-skid-ball/indicated-slip-skid"] = vector[14];
    this->pathMap["/instrumentation/turn-indicator/indicated-turn-rate"] = vector[15];
    this->pathMap["/instrumentation/vertical-speed-indicator/indicated-speed-fpm"] = vector[16];
    this->pathMap["/controls/flight/rudder"] = vector[17];
    this->pathMap["/controls/flight/flaps"] = vector[18];
    this->pathMap["/controls/engines/current-engine/throttle"] = vector[19];
    this->pathMap["/engines/engine/rpm"] = vector[20];
    this->pathMap["/controls/flight/aileron"] = vector[21];
    this->pathMap["/controls/flight/elevator"] = vector[22];
    pthread_mutex_unlock(&this->tex);

}
//
// Created by osnat on 12/26/18.
//

#include "DoubleSymVal.h"

DoubleSymVal::DoubleSymVal(double val) {
    this->value = val;
}

double DoubleSymVal::getVal() {
    return this->value;
}

void DoubleSymVal::setVal(double value) {
    this->value = value;
}
//
// Created by osnat on 12/26/18.
//

#ifndef EX3_SYMVAL_H
#define EX3_SYMVAL_H


class SymVal {
public:
    virtual double getVal() = 0;
    virtual void setVal(double value) = 0;
    virtual ~SymVal() = default;

};


#endif //EX3_SYMVAL_H

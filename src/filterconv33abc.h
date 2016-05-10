#ifndef FILTERCONV33ABC_H
#define FILTERCONV33ABC_H

#include "filter.h"


/*
a b a
b c b
a b a  *  factor

*/
class FilterConv33abc : public virtual Filter
{
public:
    FilterConv33abc();
    FilterConv33abc(QString _name, int _a, int _b, int _c, double _factor);
    virtual ~FilterConv33abc();
    void calculateFilter(FastImage *bufferOut, FastImage *bufferIn);
protected:
    int a, b, c;
    double factor;
};

#endif // FILTERCONV33ABC_H

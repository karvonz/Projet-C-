#ifndef FILTERCONV2_H
#define FILTERCONV2_H

#include "filter.h"

class FilterConv2 : public Filter
{
public:
    FilterConv2();
    FilterConv2(QString _name);
    FilterConv2(QString _name, int _a, int _b);
    virtual ~FilterConv2();
    void calculateFilter(FastImage *bufferOut, FastImage *bufferIn);
protected:
    int a, b;
};

#endif // FILTERCONV2_H

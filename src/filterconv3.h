#ifndef FILTERCONV3_H
#define FILTERCONV3_H

#include "filterconv2.h"

class FilterConv3 : public FilterConv2
{
public:
    FilterConv3();
    FilterConv3(QString _name);
    virtual ~FilterConv3();
    void calculateFilter(FastImage *bufferOut, FastImage *bufferIn);
};

#endif // FILTERCONV3_H

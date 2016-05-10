#ifndef FILTERCONV33M9_H
#define FILTERCONV33M9_H

#include "filter.h"

class FilterConv33M9 : public Filter
{
public:
    FilterConv33M9();
    virtual ~FilterConv33M9();
    void calculateFilter(FastImage *bufferOut, FastImage *bufferIn);
};

#endif // FILTERCONV33M9_H

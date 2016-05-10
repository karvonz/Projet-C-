#ifndef FILTERCOMPLEX2_H
#define FILTERCOMPLEX2_H

#include "filtersubsampling.h"
#include "filterconv33vert.h"
#include "filter.h"

class FilterComplex2 : public FilterSubSampling, public FilterConv33Vert
{
public:
    FilterComplex2();
    virtual ~FilterComplex2();
    void calculateFilter(FastImage *bufferOut, FastImage *bufferIn);
protected:
    FastImage *bufferTemp;
};

#endif // FILTERCOMPLEX2_H

#ifndef FILTERCOMPLEX4_H
#define FILTERCOMPLEX4_H

#include "filterconv33abc.h"
#include "filterconv33vert.h"
#include "greyfilter.h"

class FilterComplex4 : public GreyFilter, public FilterConv33abc, public FilterConv33Vert
{
public:
    FilterComplex4();
    virtual ~FilterComplex4();
    void calculateFilter(FastImage *bufferOut, FastImage *bufferIn);
protected:
    FastImage *bufferTemp1, *bufferTemp2;


};

#endif // FILTERCOMPLEX4_H

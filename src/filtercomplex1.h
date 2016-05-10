#ifndef FILTERCOMPLEX1_H
#define FILTERCOMPLEX1_H

#include "filtercomplexsubsampling.h"
class FilterComplex1 : public FilterComplexSubSampling
{
public:
    FilterComplex1();
    virtual ~FilterComplex1();
    void calculateFilter(FastImage *bufferOut, FastImage *bufferIn);
protected:
    FastImage *bufferTemp;
};

#endif // FILTERCOMPLEX1_H

#ifndef FILTERCOMPLEXE3_H
#define FILTERCOMPLEXE3_H

#include "greyfilter.h"
#include "filterconv33abc.h"
#include "filtercomplexupsample.h"

class FilterComplex3 : public GreyFilter, public FilterConv33abc, public FilterComplexUpSample
{
public:
    FilterComplex3();
    virtual ~FilterComplex3();
    void calculateFilter(FastImage *bufferOut, FastImage *bufferIn);
protected:
    FastImage *bufferTemp1, *bufferTemp2;
};

#endif // FILTERCOMPLEXE3_H

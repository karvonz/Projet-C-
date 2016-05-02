#ifndef FILTERCOMPLEXSUBSAMPLING_H
#define FILTERCOMPLEXSUBSAMPLING_H

#include"filter.h"
//#include <math.h>

class FilterComplexSubSampling : public Filter
{
public:
    FilterComplexSubSampling();
    FilterComplexSubSampling(QString _name, int _n);
    virtual ~FilterComplexSubSampling();
    void calculateFilter(FastImage *bufferOut, FastImage *bufferIn);

protected:
    int n;
};


#endif // FILTERCOMPLEXSUBSAMPLING_H

#ifndef FILTERSUBSAMPLING_H
#define FILTERSUBSAMPLING_H
#include "filter.h"

class FilterSubSampling: public Filter
{
public:
    FilterSubSampling();
    FilterSubSampling(QString _name);
    virtual ~FilterSubSampling();
    void calculateFilter(FastImage *bufferOut, FastImage *bufferIn);

};

#endif // FILTERSUBSAMPLING_H

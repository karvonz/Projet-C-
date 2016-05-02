#ifndef FILTERUPSAMPLE_H
#define FILTERUPSAMPLE_H

#include "filter.h"

class FilterUpSample : public Filter
{
public:
    FilterUpSample();
    FilterUpSample(QString _name);
    virtual ~FilterUpSample();
    void calculateFilter(FastImage *bufferOut, FastImage *bufferIn);
};



#endif // FILTERUPSAMPLE_H

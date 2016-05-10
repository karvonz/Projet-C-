#ifndef FILTERCOMPLEXUPSAMPLE_H
#define FILTERCOMPLEXUPSAMPLE_H

#include "filter.h"

class FilterComplexUpSample : public virtual Filter
{
public:
    FilterComplexUpSample();
    FilterComplexUpSample(QString _name);
    virtual ~FilterComplexUpSample();
    void calculateFilter(FastImage *bufferOut, FastImage *bufferIn);
};

#endif // FILTERCOMPLEXUPSAMPLE_H

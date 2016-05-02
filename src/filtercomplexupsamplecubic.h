#ifndef FILTERCOMPLEXUPSAMPLECUBIC_H
#define FILTERCOMPLEXUPSAMPLECUBIC_H

#include "filter.h"

class FilterComplexUpsampleCubic : public Filter
{
public:
    FilterComplexUpsampleCubic();
    FilterComplexUpsampleCubic(QString _name);
    virtual ~FilterComplexUpsampleCubic();
    void calculateFilter(FastImage *bufferOut, FastImage *bufferIn);
};

#endif // FILTERCOMPLEXUPSAMPLECUBIC_H

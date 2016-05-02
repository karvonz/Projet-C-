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

class FilterComplexUpSample : public Filter
{
public:
    FilterComplexUpSample();
    FilterComplexUpSample(QString _name, int _n);
    virtual ~FilterComplexUpSample();
    void calculateFilter(FastImage *bufferOut, FastImage *bufferIn);
private:
    int n;
};

#endif // FILTERUPSAMPLE_H

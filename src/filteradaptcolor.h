#ifndef FILTERADAPTCOLOR_H
#define FILTERADAPTCOLOR_H
#include "filter.h"

class FilterAdaptColor : public Filter
{
public:
    FilterAdaptColor();
    FilterAdaptColor(QString _name);
    virtual ~FilterAdaptColor();
    void calculateFilter(FastImage *bufferOut, FastImage *bufferIn);
    void calculMaxMin(FastImage *bufferIn, int *maxRed, int *maxGreen, int *maxBlue, int *minRed, int *minGreen, int *minBlue);
};

#endif // FILTERADAPTCOLOR_H

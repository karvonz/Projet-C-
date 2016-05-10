#ifndef FILTERCONV33HORIZ_H
#define FILTERCONV33HORIZ_H

#include "filter.h"

class FilterConv33Horiz : public Filter
{
public:
    FilterConv33Horiz(QString _name, int _a, int _b);
    virtual ~FilterConv33Horiz();
    void calculateFilter(FastImage *bufferOut, FastImage *bufferIn);
    FilterConv33Horiz();
protected:
    int a,b;
};

#endif // FILTERCONV33HORIZ_H

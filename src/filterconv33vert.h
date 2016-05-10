#ifndef FILTERCONV33VERT_H
#define FILTERCONV33VERT_H

#include "filter.h"

class FilterConv33Vert : public virtual Filter
{
public:
    FilterConv33Vert(QString _name, int _a, int _b);
    virtual ~FilterConv33Vert();
    void calculateFilter(FastImage *bufferOut, FastImage *bufferIn);
    FilterConv33Vert();
protected:
    int a,b;
};

#endif // FILTERCONV33VERT_H

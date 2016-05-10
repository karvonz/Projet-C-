#ifndef GREYFILTER_H
#define GREYFILTER_H

#include "filter.h"

class GreyFilter : public virtual Filter
{
public:
    GreyFilter();
    GreyFilter(QString _name, double _factorInputRed, double _factorInputGreen, double _factorInputBlue);
    ~GreyFilter();
    void calculateFilter(FastImage *bufferOut, FastImage *bufferIn);
private:
    double factorInputRed, factorInputGreen, factorInputBlue;
};

#endif // GREYFILTER_H

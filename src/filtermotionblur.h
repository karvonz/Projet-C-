#ifndef FILTERMOTIONBLUR_H
#define FILTERMOTIONBLUR_H

#include "filter.h"

class FilterMotionBlur : public Filter
{
public:
    FilterMotionBlur();
    FilterMotionBlur(QString _name);
    virtual ~FilterMotionBlur();
    void calculateFilter(FastImage *bufferOut, FastImage *bufferIn);
protected:
    FastImage *buffer1, *buffer2;
};

#endif // FILTERMOTIONBLUR_H

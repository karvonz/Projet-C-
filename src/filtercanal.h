#ifndef FILTERCANAL_H
#define FILTERCANAL_H

#include "filter.h"


class FilterCanal: public Filter
{
public:
    FilterCanal();
    FilterCanal(QString _name);
    FilterCanal(QString _name, int _factorInputRed, int _factorInputGreen, int _factorInputBlue, int _constAddRed, int _constAddGreen, int _constAddBlue);
    ~FilterCanal();
    void calculateFilter(FastImage *bufferOut, FastImage *bufferIn);
private:
    int factorInputRed, factorInputGreen, factorInputBlue, constAddRed, constAddGreen, constAddBlue;

};

#endif // FILTERCANAL_H

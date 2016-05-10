#include "filtercomplex1.h"

FilterComplex1::FilterComplex1() : FilterComplexSubSampling("Complexe 1",2)
{
    bufferTemp=NULL;
}

FilterComplex1::~FilterComplex1()
{
    delete bufferTemp;
}

void FilterComplex1::calculateFilter(FastImage *bufferOut, FastImage *bufferIn)
{


    //initialisation du bufferTemp
    if (bufferTemp == NULL)
        bufferTemp= new FastImage(bufferIn);
    //subsampling 1
    FilterComplexSubSampling::calculateFilter(bufferTemp,bufferIn);
    FilterComplexSubSampling::calculateFilter(bufferOut,bufferTemp);
}

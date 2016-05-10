
#include "filtercomplex2.h"

FilterComplex2::FilterComplex2() : Filter("Complexe 2") ,FilterSubSampling("Complexe 2") , FilterConv33Vert("Complexe 2", 1 ,2)
{
    bufferTemp=NULL;
}

FilterComplex2::~FilterComplex2()
{
    delete bufferTemp;
}

void FilterComplex2::calculateFilter(FastImage *bufferOut, FastImage *bufferIn)
{
    if (bufferTemp == NULL)
        bufferTemp= new FastImage ( bufferIn);//(bufferIn->height()/2, bufferIn->width()/2);


    FilterSubSampling::calculateFilter(bufferTemp,bufferIn);
    FilterConv33Vert::calculateFilter(bufferOut,bufferTemp);


}

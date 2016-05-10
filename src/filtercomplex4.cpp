#include "filtercomplex4.h"

FilterComplex4::FilterComplex4() : Filter("Complexe 4"), GreyFilter("Complex 4", 0.299, 0.587, 0.114), FilterConv33Vert("Complex 4",1, 2 ), FilterConv33abc("Complex 4", 0,1,4,0.125)
{
    bufferTemp1=NULL;
    bufferTemp2=NULL;

}

FilterComplex4::~FilterComplex4()
{
    delete bufferTemp1;
    delete bufferTemp2;
}

void FilterComplex4::calculateFilter(FastImage *bufferOut, FastImage *bufferIn)
{
    if (bufferTemp1 == NULL)
        bufferTemp1= new FastImage ( bufferIn);//(bufferIn->height()/2, bufferIn->width()/2);
    if (bufferTemp2 == NULL)
        bufferTemp2= new FastImage ( bufferIn);//(bufferIn->height()/2, bufferIn->width()/2);

     FilterConv33abc::calculateFilter(bufferTemp1,bufferIn);
    FilterConv33Vert::calculateFilter(bufferTemp2,bufferTemp1);
    GreyFilter::calculateFilter(bufferOut,bufferTemp2);


}

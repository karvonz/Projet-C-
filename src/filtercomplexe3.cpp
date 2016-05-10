#include "filtercomplexe3.h"

FilterComplex3::FilterComplex3() : Filter("Complexe 3"), GreyFilter("Complex 3", 0.299, 0.587, 0.114), FilterComplexUpSample("Complex 3"), FilterConv33abc("Complex 3", 0,1,4,0.125)
{
    bufferTemp1=NULL;
    bufferTemp2=NULL;

}

FilterComplex3::~FilterComplex3()
{
    delete bufferTemp1;
    delete bufferTemp2;
}

void FilterComplex3::calculateFilter(FastImage *bufferOut, FastImage *bufferIn)
{
    if (bufferTemp1 == NULL)
        bufferTemp1= new FastImage ( bufferIn);//(bufferIn->height()/2, bufferIn->width()/2);
    if (bufferTemp2 == NULL)
        bufferTemp2= new FastImage ( bufferIn);//(bufferIn->height()/2, bufferIn->width()/2);

    GreyFilter::calculateFilter(bufferTemp1,bufferIn);
    FilterConv33abc::calculateFilter(bufferTemp2,bufferTemp1);
    FilterComplexUpSample::calculateFilter(bufferOut,bufferTemp2);


}

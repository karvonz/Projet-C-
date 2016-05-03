#include "filterconv2.h"

FilterConv2::FilterConv2() : Filter("ContourDectection M0"), a(-1), b(1)
{

}

FilterConv2::FilterConv2(QString _name) : Filter(_name), a(-1), b(1)
{

}

FilterConv2::FilterConv2(QString _name, int _a, int _b) : Filter(_name), a(_a), b(_b)
{

}

FilterConv2::~FilterConv2()
{

}

void FilterConv2::calculateFilter(FastImage *bufferOut, FastImage *bufferIn)
{
    // REDIMENTIONNEMENT SI NECESSAIRE DU BUFFER DE SORTIE...
    if( bufferOut->width() != bufferIn->width() || bufferOut->height() != bufferIn->height() ){
        bufferOut->resize(bufferIn->height(), bufferIn->width());
    }

    for(int y=0; y<bufferIn->height(); y++){
        for(int x=0; x<bufferIn->width()-1; x++){
            bufferOut->Red  (y, x,(a*bufferIn->Red(y,x) + b*bufferIn->Red(y,x+1)) );
            bufferOut->Green(y, x, (a*bufferIn->Green(y,x) + b*bufferIn->Green(y,x+1)) );
            bufferOut->Blue (y, x, (a*bufferIn->Blue(y,x) + b*bufferIn->Blue(y,x+1)) );
        }
    }
}

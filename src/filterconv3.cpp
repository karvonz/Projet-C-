#include "filterconv3.h"

FilterConv3::FilterConv3(): FilterConv2()
{

}

FilterConv3::FilterConv3(QString _name) : FilterConv2(_name, -1, 2)
{

}

FilterConv3::~FilterConv3()
{

}

void FilterConv3::calculateFilter(FastImage *bufferOut, FastImage *bufferIn)
{
    // REDIMENTIONNEMENT SI NECESSAIRE DU BUFFER DE SORTIE...
    if( bufferOut->width() != bufferIn->width() || bufferOut->height() != bufferIn->height() ){
        bufferOut->resize(bufferIn->height(), bufferIn->width());
    }

    for(int y=0; y<bufferIn->height(); y++){
        for(int x=1; x<bufferIn->width()-1; x++){
            bufferOut->Red  (y, x,(b*bufferIn->Red(y,x) + a*bufferIn->Red(y,x+1)+a*bufferIn->Red(y,x-1)) );
            bufferOut->Green(y, x, (b*bufferIn->Green(y,x) + a*bufferIn->Green(y,x+1)+a*bufferIn->Green(y,x-1)) );
            bufferOut->Blue (y, x, (b*bufferIn->Blue(y,x) + a*bufferIn->Blue(y,x+1)+a*bufferIn->Blue(y,x-1)) );
        }
    }
}

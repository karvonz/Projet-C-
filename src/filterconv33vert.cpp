
#include "filterconv33vert.h"

FilterConv33Vert::FilterConv33Vert() : Filter()
{

}

FilterConv33Vert::FilterConv33Vert(QString _name, int _a, int _b) : Filter(_name), a(_a),b(_b)
{

}

FilterConv33Vert::~FilterConv33Vert()
{

}

void FilterConv33Vert::calculateFilter(FastImage *bufferOut, FastImage *bufferIn)
{
    // REDIMENTIONNEMENT SI NECESSAIRE DU BUFFER DE SORTIE...
    if( bufferOut->width() != bufferIn->width() || bufferOut->height() != bufferIn->height() ){
        bufferOut->resize(bufferIn->height(), bufferIn->width());
    }

    for(int y=1; y<bufferIn->height()-1; y++){
        for(int x=1; x<bufferIn->width()-1; x++){
            bufferOut->Red  (y, x,(-a*(bufferIn->Red(y-1,x-1) + bufferIn->Red(y+1,x-1)) + -b*bufferIn->Red(y,x-1) + a*(bufferIn->Red(y-1,x+1) + bufferIn->Red(y+1,x+1)) + b*bufferIn->Red(y,x+1) ) );
            bufferOut->Green(y, x, (-a*(bufferIn->Green(y-1,x-1) + bufferIn->Green(y+1,x-1)) + -b*bufferIn->Green(y,x-1) + a*(bufferIn->Green(y-1,x+1) + bufferIn->Green(y+1,x+1)) + b*bufferIn->Green(y,x+1) ) );
            bufferOut->Blue (y, x, (-a*(bufferIn->Blue(y-1,x-1) + bufferIn->Blue(y+1,x-1)) + -b*bufferIn->Blue(y,x-1) + a*(bufferIn->Blue(y-1,x+1) + bufferIn->Blue(y+1,x+1)) + b*bufferIn->Blue(y,x+1) ) );
        }
    }
}

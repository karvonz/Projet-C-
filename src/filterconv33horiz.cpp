#include "filterconv33horiz.h"

FilterConv33Horiz::FilterConv33Horiz(QString _name, int _a, int _b) : Filter(_name), a(_a),b(_b)
{

}

FilterConv33Horiz::~FilterConv33Horiz()
{

}

void FilterConv33Horiz::calculateFilter(FastImage *bufferOut, FastImage *bufferIn)
{
    // REDIMENTIONNEMENT SI NECESSAIRE DU BUFFER DE SORTIE...
    if( bufferOut->width() != bufferIn->width() || bufferOut->height() != bufferIn->height() ){
        bufferOut->resize(bufferIn->height(), bufferIn->width());
    }

    for(int y=1; y<bufferIn->height()-1; y++){
        for(int x=1; x<bufferIn->width()-1; x++){
            bufferOut->Red  (y, x,(-a*(bufferIn->Red(y-1,x-1) + bufferIn->Red(y-1,x+1)) -b*bufferIn->Red(y-1,x) + a*(bufferIn->Red(y+1,x-1) + bufferIn->Red(y+1,x+1)) + b*bufferIn->Red(y+1,x) ) );
            bufferOut->Green(y, x, (-a*(bufferIn->Green(y-1,x-1) + bufferIn->Green(y-1,x+1)) -b*bufferIn->Green(y-1,x) + a*(bufferIn->Green(y+1,x-1) + bufferIn->Green(y+1,x+1)) + b*bufferIn->Green(y+1,x) ) );
            bufferOut->Blue (y, x, (-a*(bufferIn->Blue(y-1,x-1) + bufferIn->Blue(y-1,x+1)) -b*bufferIn->Blue(y-1,x) + a*(bufferIn->Blue(y+1,x-1) + bufferIn->Blue(y+1,x+1)) + b*bufferIn->Blue(y+1,x) ) );
        }
    }
}

FilterConv33Horiz::FilterConv33Horiz() : Filter()
{

}

#include "filterconv33m9.h"

FilterConv33M9::FilterConv33M9() : Filter("ContourDectection M9")
{

}

FilterConv33M9::~FilterConv33M9()
{

}

void FilterConv33M9::calculateFilter(FastImage *bufferOut, FastImage *bufferIn)
{
    // REDIMENTIONNEMENT SI NECESSAIRE DU BUFFER DE SORTIE...
    if( bufferOut->width() != bufferIn->width() || bufferOut->height() != bufferIn->height() ){
        bufferOut->resize(bufferIn->height(), bufferIn->width());
    }

    for(int y=1; y<bufferIn->height()-1; y++){
        for(int x=1; x<bufferIn->width()-1; x++){
            bufferOut->Red  (y, x,(-(bufferIn->Red(y-1,x-1) + bufferIn->Red(y-1,x) + bufferIn->Red(y,x-1) ) + (bufferIn->Red(y,x+1) + bufferIn->Red(y+1,x) + bufferIn->Red(y+1,x+1)) ) );
            bufferOut->Green  (y, x,(-(bufferIn->Green(y-1,x-1) + bufferIn->Green(y-1,x) + bufferIn->Green(y,x-1) ) + (bufferIn->Green(y,x+1) + bufferIn->Green(y+1,x) + bufferIn->Green(y+1,x+1)) ) );
            bufferOut->Blue  (y, x,(-(bufferIn->Blue(y-1,x-1) + bufferIn->Blue(y-1,x) + bufferIn->Blue(y,x-1) ) + (bufferIn->Blue(y,x+1) + bufferIn->Blue(y+1,x) + bufferIn->Blue(y+1,x+1)) ) );
        }
    }
}

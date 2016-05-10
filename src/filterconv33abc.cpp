#include "filterconv33abc.h"

FilterConv33abc::FilterConv33abc() : Filter()
{
    a = 0;
    b = 0;
    c = 0;
    factor = 0.;
}

FilterConv33abc::FilterConv33abc(QString _name, int _a, int _b, int _c, double _factor) : Filter(_name), a(_a), b(_b), c(_c), factor(_factor)
{

}

FilterConv33abc::~FilterConv33abc()
{

}

void FilterConv33abc::calculateFilter(FastImage *bufferOut, FastImage *bufferIn)
{
    // REDIMENTIONNEMENT SI NECESSAIRE DU BUFFER DE SORTIE...
    if( bufferOut->width() != bufferIn->width() || bufferOut->height() != bufferIn->height() ){
        bufferOut->resize(bufferIn->height(), bufferIn->width());
    }

    for(int y=1; y<bufferIn->height()-1; y++){
        for(int x=1; x<bufferIn->width()-1; x++){
            bufferOut->Red  (y, x,(int) (factor*(a*(bufferIn->Red(y-1,x-1) + bufferIn->Red(y-1,x+1) + bufferIn->Red(y+1,x-1) + bufferIn->Red(y+1,x+1)) + b*(bufferIn->Red(y-1,x)+bufferIn->Red(y,x-1)+bufferIn->Red(y+1,x)+bufferIn->Red(y,x+1)) + c*bufferIn->Red(y,x))  ) );
            bufferOut->Green  (y, x,(int) (factor*(a*(bufferIn->Green(y-1,x-1) + bufferIn->Green(y-1,x+1) + bufferIn->Green(y+1,x-1) + bufferIn->Green(y+1,x+1)) + b*(bufferIn->Green(y-1,x)+bufferIn->Green(y,x-1)+bufferIn->Green(y+1,x)+bufferIn->Green(y,x+1)) + c*bufferIn->Green(y,x))  ) );
            bufferOut->Blue  (y, x,(int) (factor*(a*(bufferIn->Blue(y-1,x-1) + bufferIn->Blue(y-1,x+1) + bufferIn->Blue(y+1,x-1) + bufferIn->Blue(y+1,x+1)) + b*(bufferIn->Blue(y-1,x)+bufferIn->Blue(y,x-1)+bufferIn->Blue(y+1,x)+bufferIn->Blue(y,x+1)) + c*bufferIn->Blue(y,x))  ) );
        }
    }
}

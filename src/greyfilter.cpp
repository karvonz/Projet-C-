#include "greyfilter.h"

GreyFilter::GreyFilter(): Filter()
{

}

GreyFilter::GreyFilter(QString _name, double _factorInputRed, double _factorInputGreen, double _factorInputBlue):
    Filter(_name)
{
    factorInputRed=_factorInputRed;
    factorInputGreen=_factorInputGreen;
    factorInputBlue=_factorInputBlue;
}

GreyFilter::~GreyFilter()
{

}

void GreyFilter::calculateFilter(FastImage *bufferOut, FastImage *bufferIn)
{
    // REDIMENTIONNEMENT SI NECESSAIRE DU BUFFER DE SORTIE...
    if( bufferOut->width() != bufferIn->width() || bufferOut->height() != bufferIn->height() ){
        bufferOut->resize(bufferIn->height(), bufferIn->width());
    }

    for(int y=0; y<bufferIn->height(); y++){
        for(int x=0; x<bufferIn->width(); x++){
            bufferOut->Red  (y, x, (int) (factorInputRed*bufferIn->Red(y,x) + factorInputGreen*bufferIn->Green(y,x) + factorInputBlue*bufferIn->Blue(y,x)) );
            bufferOut->Green(y, x, (int) (factorInputRed*bufferIn->Red(y,x) + factorInputGreen*bufferIn->Green(y,x) + factorInputBlue*bufferIn->Blue(y,x)) );
            bufferOut->Blue (y, x, (int) (factorInputRed*bufferIn->Red(y,x) + factorInputGreen*bufferIn->Green(y,x) + factorInputBlue*bufferIn->Blue(y,x)) );
        }
    }
}




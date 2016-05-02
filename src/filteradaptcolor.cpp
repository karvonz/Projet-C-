#include "filteradaptcolor.h"

FilterAdaptColor::FilterAdaptColor():Filter()
{

}

FilterAdaptColor::FilterAdaptColor(QString _name): Filter(_name)
{

}

FilterAdaptColor::~FilterAdaptColor()
{

}

void FilterAdaptColor::calculateFilter(FastImage *bufferOut, FastImage *bufferIn)
{
    // REDIMENTIONNEMENT SI NECESSAIRE DU BUFFER DE SORTIE...
    if( bufferOut->width() != bufferIn->width() || bufferOut->height() != bufferIn->height() ){
        bufferOut->resize(bufferIn->height(), bufferIn->width());
    }
    int maxRed=0,maxGreen=0,maxBlue=0,minRed=255,minGreen=255,minBlue=255;

    calculMaxMin(bufferIn,&maxRed, &maxGreen,&maxBlue ,&minRed, &minGreen, &minBlue);;

    for(int y=0; y<bufferIn->height(); y++){
        for(int x=0; x<bufferIn->width(); x++){
            bufferOut->Red  (y, x,(constAddRed + factorInputRed*bufferIn->Red(y,x)) );
            bufferOut->Green(y, x, (constAddGreen + factorInputGreen*bufferIn->Green(y,x)) );
            bufferOut->Blue (y, x, (constAddBlue + factorInputBlue*bufferIn->Blue(y,x)) );
            //cout<<"currently calculating ["<<x<<";"<<y<<"] pixel"<<endl;
            //cout<<"valeur ini"<<bufferIn->Red(y,x)<<"valeur finale"<<bufferOut->Red(y,x)<<endl;
        }
    }
}

void FilterAdaptColor::calculMaxMin(FastImage *bufferIn, int *maxRed, int *maxGreen, int *maxBlue, int *minRed, int *minGreen, int *minBlue)
{
    for(int y=0; y<bufferIn->height(); y++){
        for(int x=0; x<bufferIn->width(); x++){
            if (bufferIn->Red(y,x)>maxRed)
                maxRed=bufferIn->Red(y,x);
            if (bufferIn->Red(y,x)<minRed)
                minRed=bufferIn->Red(y,x);
            if (bufferIn->Green(y,x)>maxGreen)
                maxGreen=bufferIn->Green(y,x);
            if (bufferIn->Green(y,x)<minGreen)
                minGreen=bufferIn->Green(y,x);
            if (bufferIn->Blue(y,x)>maxBlue)
                maxBlue=bufferIn->Blue(y,x);
            if (bufferIn->Blue(y,x)<minBlue)
                minBlue=bufferIn->Blue(y,x);

        }
    }
}

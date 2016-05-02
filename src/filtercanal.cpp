#include "filtercanal.h"

FilterCanal::FilterCanal() : Filter()
{
    factorInputRed=1;
    factorInputGreen=1;
    factorInputBlue=1;
    constAddRed=0;
    constAddGreen=0;
    constAddBlue=0;
}

FilterCanal::FilterCanal(QString _name) : Filter(_name)
{
    factorInputRed=1;
    factorInputGreen=1;
    factorInputBlue=1;
    constAddRed=0;
    constAddGreen=0;
    constAddBlue=0;
}

FilterCanal::FilterCanal(QString _name, int _factorInputRed, int _factorInputGreen, int _factorInputBlue, int _constAddRed, int _constAddGreen, int _constAddBlue) : Filter(_name), factorInputRed(_factorInputRed), factorInputBlue(_factorInputBlue), factorInputGreen(_factorInputGreen), constAddRed(_constAddRed), constAddGreen(_constAddGreen), constAddBlue(_constAddBlue)
{
}

FilterCanal::~FilterCanal()
{
}


void FilterCanal::calculateFilter(FastImage *bufferOut, FastImage *bufferIn)
{
    // REDIMENTIONNEMENT SI NECESSAIRE DU BUFFER DE SORTIE...
    if( bufferOut->width() != bufferIn->width() || bufferOut->height() != bufferIn->height() ){
        bufferOut->resize(bufferIn->height(), bufferIn->width());
    }

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





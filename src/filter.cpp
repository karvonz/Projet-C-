#include "filter.h"
#include <iostream>
using namespace std;


Filter::Filter()
{
    name="None";
}

Filter::Filter(QString _name): name(_name)
{

}

Filter::~Filter()
{

}

/*Filter::Filter(QString _name, int _factorInputRed, int _factorInputGreen, int _factorInputBlue, int _constAddRed,
               int _constAddGreen, int _constAddBlue) : name(_name), factorInputRed(_factorInputRed),
    factorInputBlue(_factorInputBlue), factorInputGreen(_factorInputGreen), constAddRed(_constAddRed), constAddGreen(_constAddGreen),
    constAddBlue(_constAddBlue)
{
}*/

void Filter::printName() const
{
    cout<<"Le filtre s'appelle: "<<name.toUtf8().constData()<<endl;
}

QString Filter::getName() const
{
    return name;
}

void Filter::calculateFilter(FastImage *bufferOut, FastImage *bufferIn)
{/*
    // REDIMENTIONNEMENT SI NECESSAIRE DU BUFFER DE SORTIE...
    if( bufferOut->width() != bufferIn->width() || bufferOut->height() != bufferIn->height() ){
        bufferOut->resize(bufferIn->height(), bufferIn->width());
    }
    cout<<"in calculateFilter de filter.h"<<endl;

    for(int y=0; y<bufferIn->height(); y++){
        for(int x=0; x<bufferIn->width(); x++){
            bufferOut->Red  (y, x, bufferIn->Red(y,x)) ;
            bufferOut->Green(y, x, bufferIn->Green(y,x)) ;
            bufferOut->Blue (y, x, bufferIn->Blue(y,x)) ;
            //cout<<"currently calculating ["<<x<<";"<<y<<"] pixel"<<endl;
            //cout<<"valeur ini"<<bufferIn->Red(y,x)<<"valeur finale"<<bufferOut->Red(y,x)<<endl;
        }
    }*/
}

/*void Filter::printFilter()
{
    cout<<constAddRed<<factorInputRed<<endl;
}*/





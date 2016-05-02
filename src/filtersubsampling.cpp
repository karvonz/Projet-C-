
#include "filtersubsampling.h"

FilterSubSampling::FilterSubSampling() : Filter()
{
}

FilterSubSampling::FilterSubSampling(QString _name):    Filter(_name)
{

}

FilterSubSampling::~FilterSubSampling()
{

}



void FilterSubSampling::calculateFilter(FastImage *bufferOut, FastImage *bufferIn)
{
    //Redimensionnement du buffer de sortie
        bufferOut->resize(bufferIn->height()/2, bufferIn->width()/2);

    for(int y=0; y<bufferOut->height(); y++){
        for(int x=0; x<bufferOut->width(); x++){
            bufferOut->Red  (y, x, bufferIn->Red(2*y,2*x));
            bufferOut->Green(y, x, bufferIn->Green(2*y,2*x));
            bufferOut->Blue (y, x, bufferIn->Blue(2*y,2*x));
            //cout<<"currently calculating ["<<x<<";"<<y<<"] pixel"<<endl;
            //cout<<"valeur ini"<<bufferIn->Red(y,x)<<"valeur finale"<<bufferOut->Red(y,x)<<endl;
        }
    }
}

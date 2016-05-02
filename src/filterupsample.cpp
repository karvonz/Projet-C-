#include "filterupsample.h"

FilterUpSample::FilterUpSample() : Filter()
{

}

FilterUpSample::FilterUpSample(QString _name) : Filter(_name)
{

}

FilterUpSample::~FilterUpSample()
{

}

void FilterUpSample::calculateFilter(FastImage *bufferOut, FastImage *bufferIn)
{
    //Redimensionnement du buffer de sortie
        bufferOut->resize(bufferIn->height()*2, bufferIn->width()*2);

    for(int y=0; y<bufferIn->height(); y++){
        for(int x=0; x<bufferIn->width(); x++){
            bufferOut->Red  (2*y, 2*x, bufferIn->Red(y,x));
            bufferOut->Red  (2*y, 2*x+1, bufferIn->Red(y,x));
            bufferOut->Red  (2*y+1, 2*x, bufferIn->Red(y,x));
            bufferOut->Red  (2*y+1, 2*x+1, bufferIn->Red(y,x));
            bufferOut->Green  (2*y, 2*x, bufferIn->Green(y,x));
            bufferOut->Green  (2*y, 2*x+1, bufferIn->Green(y,x));
            bufferOut->Green  (2*y+1, 2*x, bufferIn->Green(y,x));
            bufferOut->Green  (2*y+1, 2*x+1, bufferIn->Green(y,x));
            bufferOut->Blue  (2*y, 2*x, bufferIn->Blue(y,x));
            bufferOut->Blue  (2*y, 2*x+1, bufferIn->Blue(y,x));
            bufferOut->Blue  (2*y+1, 2*x, bufferIn->Blue(y,x));
            bufferOut->Blue  (2*y+1, 2*x+1, bufferIn->Blue(y,x));

            //cout<<"currently calculating ["<<x<<";"<<y<<"] pixel"<<endl;
            //cout<<"valeur ini"<<bufferIn->Red(y,x)<<"valeur finale"<<bufferOut->Red(y,x)<<endl;
        }
    }
}

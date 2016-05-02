
#include "filtercomplexsubsampling.h"

FilterComplexSubSampling::FilterComplexSubSampling():Filter()
{   
}

FilterComplexSubSampling::FilterComplexSubSampling(QString _name, int _n) : Filter(_name), n(_n)
{
}

FilterComplexSubSampling::~FilterComplexSubSampling()
{
}

void FilterComplexSubSampling::calculateFilter(FastImage *bufferOut, FastImage *bufferIn)
{
    //Redimensionnement du buffer de sortie
        bufferOut->resize(bufferIn->height()/2, bufferIn->width()/2);

    for(int y=0; y<bufferOut->height(); y++){
        for(int x=0; x<bufferOut->width(); x++){
            bufferOut->Red  (y, x,(int) pow((pow(bufferIn->Red(2*y,2*x),n) + pow(bufferIn->Red(2*y,2*x+1),n) + pow(bufferIn->Red(2*y+1,2*x),n) + pow(bufferIn->Red(2*y+1,2*x+1),n))/4,(double)1/n));
            bufferOut->Green(y, x,(int) pow((pow(bufferIn->Green(2*y,2*x),n) + pow(bufferIn->Green(2*y,2*x+1),n) + pow(bufferIn->Green(2*y+1,2*x),n) + pow(bufferIn->Green(2*y+1,2*x+1),n))/4,(double)1/n));
            bufferOut->Blue (y, x,(int) pow((pow(bufferIn->Blue(2*y,2*x),n) + pow(bufferIn->Blue(2*y,2*x+1),n) + pow(bufferIn->Blue(2*y+1,2*x),n) + pow(bufferIn->Blue(2*y+1,2*x+1),n))/4,(double)1/n));
            //cout<<"currently calculating ["<<x<<";"<<y<<"] pixel"<<endl;
            //cout<<"valeur ini"<<bufferIn->Red(y,x)<<"valeur finale"<<bufferOut->Red(y,x)<<endl;
        }
    }
}

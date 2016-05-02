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

FilterComplexUpSample::FilterComplexUpSample() : Filter()
{

}

FilterComplexUpSample::FilterComplexUpSample(QString _name, int _n) : Filter(_name), n(_n)
{

}

FilterComplexUpSample::~FilterComplexUpSample()
{

}

void FilterComplexUpSample::calculateFilter(FastImage *bufferOut, FastImage *bufferIn)
{
    //Redimensionnement du buffer de sortie
        bufferOut->resize(bufferIn->height()*2, bufferIn->width()*2);

    for(int y=0; y<bufferIn->height(); y++){
        for(int x=0; x<bufferIn->width(); x++){
            bufferOut->Red  (2*y, 2*x, (int) pow((pow(bufferIn->Red(y,x),n) + pow(bufferIn->Red(y,x+1),n) + pow(bufferIn->Red(y+1,x),n) + pow(bufferIn->Red(y+1,x+1),n))/4.,(double)1/n));
            bufferOut->Red  (2*y, 2*x+1, (int) pow((pow(bufferIn->Red(y,x),n) + pow(bufferIn->Red(y,x+1),n) + pow(bufferIn->Red(y+1,x),n) + pow(bufferIn->Red(y+1,x+1),n))/4.,(double)1/n));
            bufferOut->Red  (2*y+1, 2*x, (int) pow((pow(bufferIn->Red(y,x),n) + pow(bufferIn->Red(y,x+1),n) + pow(bufferIn->Red(y+1,x),n) + pow(bufferIn->Red(y+1,x+1),n))/4.,(double)1/n));
            bufferOut->Red  (2*y+1, 2*x+1, (int) pow((pow(bufferIn->Red(y,x),n) + pow(bufferIn->Red(y,x+1),n) + pow(bufferIn->Red(y+1,x),n) + pow(bufferIn->Red(y+1,x+1),n))/4.,(double)1/n));
            bufferOut->Green  (2*y, 2*x, (int) pow((pow(bufferIn->Green(y,x),n) + pow(bufferIn->Green(y,x+1),n) + pow(bufferIn->Green(y+1,x),n) + pow(bufferIn->Green(y+1,x+1),n))/4.,(double)1/n));
            bufferOut->Green  (2*y, 2*x+1, (int) pow((pow(bufferIn->Green(y,x),n) + pow(bufferIn->Green(y,x+1),n) + pow(bufferIn->Green(y+1,x),n) + pow(bufferIn->Green(y+1,x+1),n))/4.,(double)1/n));
            bufferOut->Green  (2*y+1, 2*x, (int) pow((pow(bufferIn->Green(y,x),n) + pow(bufferIn->Green(y,x+1),n) + pow(bufferIn->Green(y+1,x),n) + pow(bufferIn->Green(y+1,x+1),n))/4.,(double)1/n));
            bufferOut->Green  (2*y+1, 2*x+1, (int) pow((pow(bufferIn->Green(y,x),n) + pow(bufferIn->Green(y,x+1),n) + pow(bufferIn->Green(y+1,x),n) + pow(bufferIn->Green(y+1,x+1),n))/4.,(double)1/n));
            bufferOut->Blue  (2*y, 2*x, (int) pow((pow(bufferIn->Blue(y,x),n) + pow(bufferIn->Blue(y,x+1),n) + pow(bufferIn->Blue(y+1,x),n) + pow(bufferIn->Blue(y+1,x+1),n))/4.,(double)1/n));
            bufferOut->Blue  (2*y, 2*x+1, (int) pow((pow(bufferIn->Blue(y,x),n) + pow(bufferIn->Blue(y,x+1),n) + pow(bufferIn->Blue(y+1,x),n) + pow(bufferIn->Blue(y+1,x+1),n))/4.,(double)1/n));
            bufferOut->Blue  (2*y+1, 2*x, (int) pow((pow(bufferIn->Blue(y,x),n) + pow(bufferIn->Blue(y,x+1),n) + pow(bufferIn->Blue(y+1,x),n) + pow(bufferIn->Blue(y+1,x+1),n))/4.,(double)1/n));
            bufferOut->Blue  (2*y+1, 2*x+1, (int) pow((pow(bufferIn->Blue(y,x),n) + pow(bufferIn->Blue(y,x+1),n) + pow(bufferIn->Blue(y+1,x),n) + pow(bufferIn->Blue(y+1,x+1),n))/4.,(double)1/n));

            //cout<<"currently calculating ["<<x<<";"<<y<<"] pixel"<<endl;
            //cout<<"valeur ini"<<bufferIn->Red(y,x)<<"valeur finale"<<bufferOut->Red(y,x)<<endl;
        }
    }
}

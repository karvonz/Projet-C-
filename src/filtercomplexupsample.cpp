#include "filtercomplexupsample.h"


FilterComplexUpSample::FilterComplexUpSample() : Filter()
{

}

FilterComplexUpSample::FilterComplexUpSample(QString _name) : Filter(_name)
{

}

FilterComplexUpSample::~FilterComplexUpSample()
{

}

void FilterComplexUpSample::calculateFilter(FastImage *bufferOut, FastImage *bufferIn)
{
    //Redimensionnement du buffer de sortie
        bufferOut->resize(bufferIn->height()*2, bufferIn->width()*2);
        int Redyx, Redyxx,Redyyx,Redyyxx,Greenyx, Greenyxx,Greenyyx,Greenyyxx,Blueyx, Blueyxx,Blueyyx,Blueyyxx;
    for(int y=0; y<bufferIn->height(); y++){
        for(int x=0; x<bufferIn->width(); x++){
            Redyx = bufferIn->Red(y,x);
            Redyxx = bufferIn->Red(y,x+1);
            Redyyx = bufferIn->Red(y+1,x);
            Redyyxx = bufferIn->Red(y+1,x+1);
            Greenyx = bufferIn->Green(y,x);
            Greenyxx = bufferIn->Green(y,x+1);
            Greenyyx = bufferIn->Green(y+1,x);
            Greenyyxx = bufferIn->Green(y+1,x+1);
            Blueyx = bufferIn->Blue(y,x);
            Blueyxx = bufferIn->Blue(y,x+1);
            Blueyyx = bufferIn->Blue(y+1,x);
            Blueyyxx = bufferIn->Blue(y+1,x+1);

            bufferOut->Red  (2*y, 2*x, (int) ((Redyx + Redyxx + Redyx + Redyyxx)/4.));
            bufferOut->Red  (2*y, 2*x+1, (int) ((Redyx + Redyxx + Redyx + Redyyxx)/4.));
            bufferOut->Red  (2*y+1, 2*x, (int) ((Redyx + Redyxx + Redyx + Redyyxx)/4.));
            bufferOut->Red  (2*y+1, 2*x+1, (int) ((Redyx + Redyxx + Redyx + Redyyxx)/4.));
            bufferOut->Green  (2*y, 2*x, (int) ((Greenyx + Greenyxx + Greenyx+Greenyyxx)/4.));
            bufferOut->Green  (2*y, 2*x+1, (int) ((Greenyx + Greenyxx + Greenyx+ Greenyyxx)/4.));
            bufferOut->Green  (2*y+1, 2*x, (int) ((Greenyx + Greenyxx + Greenyx +Greenyyxx)/4.));
            bufferOut->Green  (2*y+1, 2*x+1, (int) ((Greenyx + Greenyxx + Greenyx+ Greenyyxx)/4.));
            bufferOut->Blue  (2*y, 2*x, (int) ((Blueyx + Blueyxx + Blueyx +Blueyyxx)/4.));
            bufferOut->Blue  (2*y, 2*x+1, (int) ((Blueyx + Blueyxx + Blueyx+ Blueyyxx)/4.));
            bufferOut->Blue  (2*y+1, 2*x, (int) ((Blueyx + Blueyxx + Blueyx +Blueyyxx)/4.));
            bufferOut->Blue  (2*y+1, 2*x+1, (int) ((Blueyx + Blueyxx + Blueyx+ Blueyyxx)/4.));

            //cout<<"currently calculating ["<<x<<";"<<y<<"] pixel"<<endl;
            //cout<<"valeur ini"<<bufferIn->Red(y,x)<<"valeur finale"<<bufferOut->Red(y,x)<<endl;
        }
    }
}

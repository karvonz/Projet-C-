#include "filtercomplexupsamplecubic.h"

FilterComplexUpsampleCubic::FilterComplexUpsampleCubic() : Filter()
{

}

FilterComplexUpsampleCubic::FilterComplexUpsampleCubic(QString _name) : Filter(_name)
{

}

FilterComplexUpsampleCubic::~FilterComplexUpsampleCubic()
{

}

void FilterComplexUpsampleCubic::calculateFilter(FastImage *bufferOut, FastImage *bufferIn)
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

            bufferOut->Red  (2*y, 2*x, (int) pow((Redyx*Redyx + Redyxx*Redyxx + Redyx*Redyx + Redyyxx*Redyyxx)/4., 0.5));
            bufferOut->Red  (2*y, 2*x+1, (int) pow((Redyx*Redyx + Redyxx*Redyxx + Redyx*Redyx + Redyyxx*Redyyxx)/4.,0.5));
            bufferOut->Red  (2*y+1, 2*x, (int) pow((Redyx*Redyx + Redyxx*Redyxx + Redyx*Redyx + Redyyxx*Redyyxx)/4.,0.5));
            bufferOut->Red  (2*y+1, 2*x+1, (int) pow((Redyx*Redyx + Redyxx*Redyxx + Redyx*Redyx + Redyyxx*Redyyxx)/4.,0.5));
            bufferOut->Green  (2*y, 2*x, (int) pow((Greenyx*Greenyx + Greenyxx*Greenyxx + Greenyx*Greenyx + Greenyyxx*Greenyyxx)/4.,0.5));
            bufferOut->Green  (2*y, 2*x+1, (int) pow((Greenyx*Greenyx + Greenyxx*Greenyxx + Greenyx*Greenyx + Greenyyxx*Greenyyxx)/4.,0.5));
            bufferOut->Green  (2*y+1, 2*x, (int) pow((Greenyx*Greenyx + Greenyxx*Greenyxx + Greenyx*Greenyx + Greenyyxx*Greenyyxx)/4.,0.5));
            bufferOut->Green  (2*y+1, 2*x+1, (int) pow((Greenyx*Greenyx + Greenyxx*Greenyxx + Greenyx*Greenyx + Greenyyxx*Greenyyxx)/4.,0.5));
            bufferOut->Blue  (2*y, 2*x, (int) pow((Blueyx*Blueyx + Blueyxx*Blueyxx + Blueyx*Blueyx + Blueyyxx*Blueyyxx)/4.,0.5));
            bufferOut->Blue  (2*y, 2*x+1, (int) pow((Blueyx*Blueyx + Blueyxx*Blueyxx + Blueyx*Blueyx + Blueyyxx*Blueyyxx)/4.,0.5));
            bufferOut->Blue  (2*y+1, 2*x, (int) pow((Blueyx*Blueyx + Blueyxx*Blueyxx + Blueyx*Blueyx + Blueyyxx*Blueyyxx)/4.,0.5));
            bufferOut->Blue  (2*y+1, 2*x+1, (int) pow((Blueyx*Blueyx + Blueyxx*Blueyxx + Blueyx*Blueyx + Blueyyxx*Blueyyxx)/4.,0.5));

          }
    }
}

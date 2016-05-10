#include "filtermotionblur.h"

FilterMotionBlur::FilterMotionBlur() : Filter()
{ 
    buffer1 = NULL;
    buffer2 = NULL;
}

FilterMotionBlur::FilterMotionBlur(QString _name) : Filter(_name)
{
    buffer1 = NULL;
    buffer2 = NULL;
}

FilterMotionBlur::~FilterMotionBlur()
{
    delete buffer1;
    delete buffer2;
}

void FilterMotionBlur::calculateFilter(FastImage *bufferOut, FastImage *bufferIn)
{
    if (buffer1 == NULL)
        buffer1 = new FastImage( bufferIn );
    if (buffer2 == NULL)
        buffer2 = new FastImage( bufferIn );

    // REDIMENTIONNEMENT SI NECESSAIRE DU BUFFER DE SORTIE...
    if( bufferOut->width() != bufferIn->width() || bufferOut->height() != bufferIn->height() ){
        bufferOut->resize(bufferIn->height(), bufferIn->width());
    }

    for(int y=0; y<bufferIn->height(); y++){
        for(int x=0; x<bufferIn->width(); x++){
            bufferOut->Red  (y, x,(int)(0.5*bufferIn->Red(y,x) + (double) (3./10.)*buffer1->Red(y,x) + (double) (2./10.)*buffer1->Red(y,x)) );
            bufferOut->Green(y, x, (int)(0.5*bufferIn->Green(y,x) + (double) (3./10.)*buffer1->Green(y,x) + (double) (2./10.)*buffer1->Green(y,x)) );
            bufferOut->Blue (y, x, (int)(0.5*bufferIn->Blue(y,x) + (double) (3./10.)*buffer1->Blue(y,x) + (double) (2./10.)*buffer1->Blue(y,x)) );

            buffer2->Red (y, x, buffer1->Red(y,x));
            buffer2->Green (y, x, buffer1->Green(y,x));
            buffer2->Blue (y, x, buffer1->Blue(y,x));
            buffer1->Red (y, x, bufferIn->Red(y,x));
            buffer1->Green (y, x, bufferIn->Green(y,x));
            buffer1->Blue (y, x, bufferIn->Blue(y,x));

        }
    }
}

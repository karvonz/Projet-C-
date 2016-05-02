#ifndef FILTER_H
#define FILTER_H

#include "./Image/FImage.h"
#include <QString>


class Filter
{
public:
    Filter();
    Filter(QString _name);
    virtual ~Filter();
    //Filter(QString _name, int _factorInputRed, int _factorInputGreen, int _factorInputBlue, int _constAddRed,
    //       int _constAddGreen, int _constAddBlue);
    virtual void printName() const;
    QString getName() const;
    virtual void calculateFilter(FastImage *bufferOut, FastImage *bufferIn) =0;
    //void printFilter();
protected:
    QString name;
};



#endif // FILTER_H


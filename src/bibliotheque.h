#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include <QString>
#include "filter.h"
#include "greyfilter.h"
#include "filtercanal.h"
#include "filtersubsampling.h"
#include "filtercomplexsubsampling.h"
#include "filterupsample.h"
#include "filteradaptcolor.h"
#include "filtercomplexupsample.h"
#include "filtercomplexupsamplecubic.h"
#include "filtermotionblur.h"
#include "filterconv2.h"
#include "filterconv3.h"
#include "filterconv33vert.h"
#include "filterconv33horiz.h"
#include "filterconv33abc.h"
#include "filterconv33m9.h"
#include "filtercomplex1.h"
#include "filtercomplex2.h"
#include "filtercomplexe3.h"
#include "filtercomplex4.h"




#include <vector>

#define MAX_FILTER 12

class Bibliotheque
{
public:
    Bibliotheque();
    virtual ~Bibliotheque();
    void addFilter(Filter *filter);
    int nbrFilter();
    void presenteBiblio();
    QString getNameItem(int i);
    Filter* getFilter(int i);
private:
    vector<Filter*> biblio;
};

#endif // BIBLIOTHEQUE_H

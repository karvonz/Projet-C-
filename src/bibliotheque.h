#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include <QString>
#include "filter.h"
#include "greyfilter.h"
#include "filtercanal.h"
#include "filtersubsampling.h"
#include "filtercomplexsubsampling.h"
#include "filterupsample.h"
#include <vector>

#define MAX_FILTER 12

class Bibliotheque
{
public:
    Bibliotheque();
    virtual ~Bibliotheque();
    void addFilter(Filter *filter);
    void addFilter(GreyFilter *filter);
    void addFilter(FilterCanal *filter);
    void addFilter(FilterSubSampling *filter);
    void addFilter(FilterComplexSubSampling *filter);
    void addFilter(FilterUpSample *filter);
    void addFilter(FilterComplexUpSample *filter);
    int nbrFilter();
    void presenteBiblio();
    QString getNameItem(int i);
    Filter* getFilter(int i);
private:
    vector<Filter*> biblio;
};

#endif // BIBLIOTHEQUE_H

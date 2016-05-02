#include "bibliotheque.h"
#include "filter.h"


#include <iostream>
using namespace std;

Bibliotheque::Bibliotheque()
{
}

Bibliotheque::~Bibliotheque()
{
    cout<<"currently deleting Bibliotheque"<<endl;

    for(int i=0; i<biblio.size(); ++i)
    {
        delete biblio[i];
        biblio[i]=0;
    }
}

void Bibliotheque::addFilter(Filter *filter)
{
    biblio.push_back(filter);
}

void Bibliotheque::addFilter(GreyFilter *filter)
{
    biblio.push_back(filter);
}

void Bibliotheque::addFilter(FilterCanal *filter)
{
    biblio.push_back(filter);
}

void Bibliotheque::addFilter(FilterSubSampling *filter)
{
    biblio.push_back(filter);

}

void Bibliotheque::addFilter(FilterComplexSubSampling *filter)
{
    biblio.push_back(filter);
}

void Bibliotheque::addFilter(FilterUpSample *filter)
{
    biblio.push_back(filter);
}

void Bibliotheque::addFilter(FilterComplexUpSample *filter)
{
    biblio.push_back(filter);
}


int Bibliotheque::nbrFilter()
{
    return biblio.size();
}


void Bibliotheque::presenteBiblio()
{
    for(int i=0; i<nbrFilter();i++)
        getFilter(i)->printName();
}

QString Bibliotheque::getNameItem(int i)
{
    if( i<=nbrFilter())
        return biblio[i]->getName();
    else{
        perror("tentative d'accès a une case de la bibliothèque non valide dans la fonction getNameItem");
        exit(0);
        }

}

Filter* Bibliotheque::getFilter(int i)
{
    if( i<=nbrFilter())
        return biblio[i];
    else{
        perror("tentative d'accès a une case de la bibliothèque non valide dans la fonction getFilter");
        exit(0);
        }
}




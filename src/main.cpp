#include "playerinterface.h"
#include "bibliotheque.h"
#include "filter.h"
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>


#include "./Image/FImage.h"
#include "./Image/CVideo.h"
#include <QString>

int main(int argc,char **argv)
{
    Bibliotheque biblio;
    //Déclaration des filtres
    biblio.addFilter(new FilterCanal("None"));
    biblio.addFilter(new FilterCanal("Inverse",-1,-1,-1, 255, 255, 255));
    biblio.addFilter(new FilterCanal("Red Canal",1, 0, 0, 0, 0, 0 ));
    biblio.addFilter(new FilterCanal("Green Canal", 0, 1, 0, 0, 0, 0));
    biblio.addFilter(new FilterCanal("Blue Canal", 0, 0, 1, 0, 0, 0));
    biblio.addFilter(new GreyFilter("Simple Grey", 1.0/3.0,1.0/3.0,1.0/3.0 ));
    biblio.addFilter(new GreyFilter("Reliable Grey",0.299,0.587,0.114));
    biblio.addFilter(new FilterSubSampling("SubSampling (poinçon)"));
    biblio.addFilter(new FilterComplexSubSampling("SubSampling (linear)",1));
    biblio.addFilter(new FilterComplexSubSampling("SubSampling (cubic)",2));
    biblio.addFilter(new FilterUpSample("UpSampling (poinçon)"));
    biblio.addFilter(new FilterComplexUpSample("UpSampling (linear)", 1));
    biblio.addFilter(new FilterComplexUpSample("UpSampling (cubic)", 2));
    biblio.addFilter(new FilterAdaptColor("Adapt Color"));


    QApplication app(argc,argv);
    cout << "(II) int main(int argc,char **argv) :: Creation de l'interface graphique" << endl;
    PlayerInterface p(biblio);
    cout << "(II) int main(int argc,char **argv)  :: redimensionnement de l'interface graphique" << endl;
    p.resize(640,480);
    cout << "(II) int main(int argc,char **argv)  :: ouverture d'un fichier video" << endl;


    QString *name = NULL;
    if(argc == 2){
        name = new QString( argv[1] );
        cout << "(II) int main(int argc,char **argv)  :: parametre trouve (" << argv[1] << ")" << endl;
    }


    p.openFile( name );
    cout << "(II) int main(int argc,char **argv)  :: affichage de l'interface graphique" << endl;
    p.show();
    return app.exec();
    //biblio.~Bibliotheque();
}

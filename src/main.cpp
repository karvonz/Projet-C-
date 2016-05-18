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
    biblio.addFilter(new FilterComplexUpSample("UpSampling (linear)"));
    biblio.addFilter(new FilterComplexUpsampleCubic("UpSampling (cubic)"));
    biblio.addFilter(new FilterAdaptColor("Adapt Color"));
    biblio.addFilter(new FilterMotionBlur("Motion Blur"));
    biblio.addFilter(new FilterConv2("ContourDetection M0"));
    biblio.addFilter(new FilterConv3("ContourDetection M1"));
    biblio.addFilter(new FilterConv33Vert("ContourDetection M2",1, 2));
    biblio.addFilter(new FilterConv33Vert("ContourDetection M3",1, 1));
    biblio.addFilter(new FilterConv33Horiz("ContourDetection M4",1, 2));
    biblio.addFilter(new FilterConv33Horiz("ContourDetection M5",1, 1));
    biblio.addFilter(new FilterConv33abc("ContourDetection M6",0, -1, 4, 1));
    biblio.addFilter(new FilterConv33abc("ContourDetection M7",-1, -1,8,1));
    biblio.addFilter(new FilterConv33abc("ContourDetection M8",-1, -2, 12, 1));
    biblio.addFilter(new FilterConv33M9());
    biblio.addFilter(new FilterConv33abc("Flou B0",0, 1, 4, 1./8.));
    biblio.addFilter(new FilterConv33abc("Flou B1",1, 2, 8, 1./16.));
    biblio.addFilter(new FilterConv33abc("Flou B2",1, 1, 1, 1./9.));
    biblio.addFilter(new FilterConv33abc("Flou B3",1, 1, 0, 1./8.));
    biblio.addFilter(new FilterComplex1());
    biblio.addFilter(new FilterComplex2());
    biblio.addFilter(new FilterComplex3());
    biblio.addFilter(new FilterComplex4());





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
}

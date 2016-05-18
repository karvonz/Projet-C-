#ifndef PLAYERINTERFACE_H
#define PLAYERINTERFACE_H

#include <QtCore/QCoreApplication>
#include <QApplication>
#include <QProcess>
#include <QVBoxLayout>
#include <QWidget>
#include <QSizePolicy>
#include <QPushButton>
#include <QTextEdit>
#include <QComboBox>
#include <QCloseEvent>
#include <QTimer>
#include <QDebug>
#include <QVector>
#include <QFileDialog>
#include <QScrollArea>
#include <QShortcut>
#include <QGroupBox>
#include <QLabel>
#include <QString>

#include "bibliotheque.h"
#include "filter.h"
#include "./Image/CVideo.h"
#include "openglwidget.h"
//#include "greyfilter.h"
#include "combobox.h"

#define POSITION_RESOLUTION 10000


class PlayerInterface : public QWidget
{
    Q_OBJECT
    VComboBox *_listeFiltres;

    vector<VComboBox*> listeFiltresVector;


    QPushButton *start;
    QPushButton *pause;
    QPushButton *nextFrame;
    QPushButton *filterFrame;

    // LABELS UTILISES DANS L'INTERFACE AFIN DE FOURNIR DES INFORMATIONS
    // SUR LES FLUX VIDEO MANIPULES
    QLabel *inWidth;
    QLabel *inHeight;
    QLabel *ouWidth;
    QLabel *ouHeight;

    // LABLES UTILISES DANS L'INTERFACE AFIN DE FOURNIR UNE MESURE DU TEMPS
    // DES DIFFERENTS TRAITEMENTS (DECODAGE, PROCESSING, AFFICHAGE)
    QLabel *dTime;
    QLabel *pTime;
    QLabel *sTime;
    QHBoxLayout *layout = new QHBoxLayout;
    QVBoxLayout *layerList = new QVBoxLayout;

    // VARIABLE UTILISEE AFIN DE MINIMISER LE NOMBRE DE MISES A JOUR DE
    // L'INTERFACE GRAPHIQUE.
    int _inWidth;
    int _inHeight;
    int _ouWidth;
    int _ouHeight;

    //
    // VARIABLE UTILISEE AFIN DE MINIMISER LE NOMBRE DE MISES A JOUR DE
    // L'INTERFACE GRAPHIQUE.
    //
    int _avgDecoding;
    int _avgProcessing;
    int _avgDrawing;

    // MUTEX POUR GERER LE TRAITEMENT DE L'INFORMATION
    bool processing;

    bool isWebCam; // GESTION DU PASSAGE FLUX VIDEO / WebCam

    OpenglWidget *_videoWidget;
    QTimer *poller;

    int decodedFrames;
    int frameAverage;
    int seconds;
    QTimer *timerFPS;

    bool _isPlaying;
    CVideo *c;

    QString fileName;

    vector<FastImage *> buffer;
    FastImage *bufferIn;
    FastImage *bufferTmp1;
    FastImage *bufferTmp2;
    FastImage *bufferOut;

public:
    ~PlayerInterface();
    void addListFilter(VComboBox* l);
    VComboBox* getListFilter(int i);
    int nbrListFilter();
    void manageList(int newPosition);
    void deleteWidget(int i);
    void calculBuffer(FastImage* bufferOut,FastImage* bufferIn);

    PlayerInterface(Bibliotheque &_biblio);

public slots:
    void changeCurrentFilter(VComboBox* listeFilter);
    //void playFile();
    void openFile(QString* name);
    //void updateInterface();
    //void changeVolume(int newVolume);

    // METHODE SERVANT A GERER LE FILTRE EN MODE PAUSE
    void changePosition(int newPosition);

    void drawNextFrame();
    void frameCounterMethod();

    void startButton();
    void switchToWebCam();

    void unlockFrameRate();

    void stepOneFrame();
    void resetFilters();
private:
    Bibliotheque biblio;
    int currentFilter;
    int number_filter;
};

#endif // PLAYERINTERFACE_H

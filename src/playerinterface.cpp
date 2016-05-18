#include "playerinterface.h"

#define debug false


PlayerInterface::PlayerInterface(Bibliotheque & _biblio)
    : QWidget(0, Qt::Window)
{
    biblio=_biblio;
    number_filter=1;
    //
    //	INITIALISATION DES POINTEURS SUR LES "IMAGES"
    //
    bufferIn   = NULL;
    bufferOut  = NULL;
    bufferTmp1 = NULL;
    bufferTmp2 = NULL;


    frameAverage = 0;
    seconds      = 0;

    // ON INITIALISE LES VARIABLES AFIN DE PROVOQUER UNE MISE A JOUR LORS DU
    // PREMIER AFFICHAGE DE LA VIDEO A L'ECRAN
    _inWidth  = -1;
    _inHeight = -1;
    _ouWidth  = -1;
    _ouHeight = -1;

    //
    //	CREATION DES OBJETS VISUELS (INTERFACE GRAPHIQUE)
    //
    _videoWidget   = new OpenglWidget(this);

    //
    // ON REALISE LA MISE EN FORME A L'ECRAN
    //
    QVBoxLayout *l4     = new QVBoxLayout;
    setLayout(layout);


    //Initialisation des vectors
    listeFiltresVector.clear();
    addListFilter(new VComboBox());
    buffer.clear();

    //Ajout de la premiere liste
    layerList->addWidget(listeFiltresVector[0]);

    _isPlaying = false;

    //
    // LE MODE WEBCAM EST DESACTIVE DANS CETTE VERSION DE L'OUTIL
    //
    isWebCam         = false;


    //
    // DECLARATION ET INSTANCIATION DES BOUTTONS
    //
    start       = new QPushButton( "Stop video", this );
    nextFrame   = new QPushButton( "Next Frame", this );
    pause       = new QPushButton( "Switch to camera", this );
    filterFrame = new QPushButton( "Limit 24fps", this );

    pause->setEnabled( false );
    start->setEnabled( false );
    nextFrame->setEnabled( false );
    filterFrame->setEnabled( false );



    QGroupBox   *g2 = new QGroupBox(tr("Action commands"));
    QVBoxLayout *ac = new QVBoxLayout;
    ac->addWidget(pause);
    ac->addWidget(start);
    ac->addWidget(nextFrame);
    ac->addWidget(filterFrame);
    g2->setLayout(ac);

    QGroupBox   *g3 = new QGroupBox(tr("Input video informations"));
    QVBoxLayout *vi = new QVBoxLayout;
    inWidth  = new QLabel(tr("Video width"));
    inHeight = new QLabel(tr("Video width"));
    vi->addWidget( inWidth  );
    vi->addWidget( inHeight );
    g3->setLayout(vi);

    QGroupBox   *g4 = new QGroupBox(tr("Output video informations"));
    QVBoxLayout *pd = new QVBoxLayout;
    ouWidth  = new QLabel(tr("Video width"));
    ouHeight = new QLabel(tr("Video width"));
    pd->addWidget( ouWidth  );
    pd->addWidget( ouHeight );
    g4->setLayout(pd);

    QGroupBox   *pp = new QGroupBox(tr("Processing informations"));
    QVBoxLayout *pt = new QVBoxLayout;
    dTime  = new QLabel(tr("Video width"));
    pTime = new QLabel(tr("Video width"));
    sTime = new QLabel(tr("Video width"));
    pt->addWidget( dTime  );
    pt->addWidget( pTime );
    pt->addWidget( sTime );
    pp->setLayout(pt);

    l4->addWidget(g2);
    l4->addWidget(g3);
    l4->addWidget(g4);
    l4->addWidget(pp);
    layout->addLayout(layerList);

    layout->addLayout(l4);

    //
    // GESTION DE L'AFFICHAGE DE L'IMAGE
    //
    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(_videoWidget);
    layout->addWidget(scrollArea);


    //
    // ON GENERE UNE INTERUPTION TOUTES LES 5MS AFIN DE LANCER LE DECODAGE D'UNE IMAGE,
    // CELA NOUS PERMET EN THEORIE DE MONTER A 200Hz
    //
    poller = new QTimer(this);
    connect(poller, SIGNAL(timeout()), this, SLOT(drawNextFrame()));
    poller->setInterval(1000/200);
    processing = false;

    //
    // ON CREE UN PROGRAMME AUTONOME DONT LE ROLE EST DE METTRE A JOUR LA BARRE
    // DES TITRES AVEC LE NOMBRE D'IMAGES TRAITEES PAR SECONDE
    //
    timerFPS = new QTimer(this);
    connect(timerFPS, SIGNAL(timeout()), this, SLOT(frameCounterMethod()));
    timerFPS->start(1000);

    decodedFrames = 0;

    //
    // ON CONNECTE LES EVENEMENTS PRODUITS PAR LES OBJETS A UN GESTIONNAIRE D'INTERRUPTION
    // LOGICIEL EN CHARGE DE LEUR TRAITEMENT (CHAQUE EVENEMENT EST TRAITE PAR UNE METHODE)
    //
    connect(poller,         SIGNAL(timeout()),       this, SLOT(updateInterface())  );
    connect(start,          SIGNAL(clicked()),       this, SLOT(startButton())      );
    connect(pause,          SIGNAL(clicked()),       this, SLOT(openFile())         );
    connect(nextFrame,      SIGNAL(clicked()),       this, SLOT(stepOneFrame())     );
    connect(filterFrame,    SIGNAL(clicked()),       this, SLOT(unlockFrameRate())  );
    connect(listeFiltresVector[0],  SIGNAL(activated(int)),  this, SLOT(changePosition(int)));

    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    updateGeometry();


    //
    // DECLARATION DES RACOURCIS CLAVIER
    //
    new QShortcut(Qt::CTRL + Qt::Key_Q, this, SLOT(close()));
    new QShortcut(Qt::Key_Space,        this, SLOT(startButton()));
}


//
// DESTRUCTEUR DE L'OBJET QUI NE DEVRAIS PAS ETRE VIDE...
//
PlayerInterface::~PlayerInterface()
{
    cout<<"currently deleting listeFiltresVector"<<endl;

    for(int i=0; i<listeFiltresVector.size(); ++i)
    {
        delete listeFiltresVector[i];
        listeFiltresVector[i]=0;
    }
}

void PlayerInterface::addListFilter(VComboBox *l)
{
    //on connecte le passage de la souris sur la liste
    connect(l,SIGNAL(mouseEntered(VComboBox*)), this, SLOT(changeCurrentFilter(VComboBox*)));

    //on rajoute tous les filtres entrés au début
    for(int i=0; i<biblio.nbrFilter();i++)
        l->addItem(biblio.getNameItem(i));

    //ajout au vector
    listeFiltresVector.push_back(l);
}





VComboBox *PlayerInterface::getListFilter(int i)
{
    if ( i<=nbrListFilter())
        return listeFiltresVector[i];
    else{
        perror("probleme getListFilter tentative d'acces filtre hors du vector");
        exit(0);
    }
}


int PlayerInterface::nbrListFilter()
{
    return listeFiltresVector.size()   ;
}

void PlayerInterface::manageList(int newPosition)
{
    if( newPosition == 0)
    {
        if (currentFilter < (listeFiltresVector.size()-1) && (listeFiltresVector.size()-1) != 0 )
            deleteWidget(currentFilter);
    }
    else if(currentFilter==(listeFiltresVector.size()-1))
    {
        buffer.push_back(new FastImage(bufferTmp1)); //on ajoute un buffer.
        addListFilter(new VComboBox()); //nouvelle liste de filtre
        layerList->addWidget(listeFiltresVector[++currentFilter]); //on ajoute la liste au layer layerList
        connect(listeFiltresVector[currentFilter],  SIGNAL(activated(int)),  this, SLOT(changePosition(int)));


    }


}

void PlayerInterface::changeCurrentFilter(VComboBox *listeFilter) //slot pour savoir sur quel filtre est la souris
{
    //recherche du filtre dans le vector grâce a son adresse
    bool t=true;
    for(int i=0;(i<listeFiltresVector.size() && t);i++)
    {
        if (listeFilter==listeFiltresVector[i]){
            currentFilter=i;
            t=false;
        }
    }
    //cout<<currentFilter<<endl;
}


void PlayerInterface::drawNextFrame()
{
    //
    // SI ON EST DEJA EN TRAIN DE TRAITER UNE IMAGE LORSQUE LE TIMER SE REVEILLE CELA SIGNIFIE
    // QUE L'ON EST A LA BOURRE DONC ON REPART POUR UN TOUR D'ATTENTE
    //
    if( processing == true ){
        cout << "OUPS we must wait a bit more because a frame is currently processed !" << endl;
        return;
    } processing = true;

    //
    // MESURE DU TEMPS...
    //
    long startC = clock();

    //
    // ON INCREMENTE LE NOMBRE D'IMAGES TRAITES
    //
    decodedFrames += 1;

    //
    // ON REGARDE SI L'ON EST EN COURS DE LECTURE DU FICHIER VIDEO, SINON ON RAFRAICHI UNQIUEMENT LE TRAITEMENT
    //
    if( _isPlaying == true ){

        //
        // CREATION DES BUFFERS TEMPORAIRES SI NECESSAIRE
        //
        if( bufferIn == NULL ){
            bufferIn  = new FastImage( 2, 2 );
            bufferOut = new FastImage( bufferIn );
            bufferTmp1 = new FastImage( bufferIn );
            bufferTmp2 = new FastImage( bufferIn );
        }

        c->getNextVideoFrame( bufferIn );

        //
        // ON GERE LE CAS OU LA VIDEO VIENT DE SE TERMINER... ON N'A PLUS RIEN A FAIRE
        // MAINTENANT !
        //
        if( c->isFinished() == true ){
            poller->stop();
            filterFrame->setEnabled( false );
            start->setEnabled( false );
            nextFrame->setEnabled( false );
            processing = false;
            return;
        }
    }

    //
    // AFFICHAGE DU TEMPS NECESSAIRE A L'EXTRATION DE l'IMAGE
    //
    _avgDecoding   += ( (double)(clock() - startC) ) / ( CLOCKS_PER_SEC ) * 1000.0;

    startC = clock(); // ON RELANCE LE COMPTEUR...


    //QString value = _listeFiltres->currentText();
    //
    // EN FONCTION DU CHOIX FAIT DANS LA LISTE ON FAIT UN TRUC ?!
    //

    //Appel a la fonction de calcul du buffer de sortie
    calculBuffer(bufferOut,bufferIn);



    // ON AFFICHE LE TEMPS NECESSAIRE A LA GESTION DU FILTRAGE
    _avgProcessing += ( (double)(clock() - startC) ) / ( CLOCKS_PER_SEC ) * 1000.0;
    startC = clock(); // ON RELANCE LE COMPTEUR...

    //
    // ON REGARDE SI L'ON DOIT REDIMENSIONNER LA ZONE VISIBLE A L'ECRAN AFIN DE S'ADAPTER
    // AU RESULTAT DES DIFFERENTS FILTAGES
    //
    QSize cSize = _videoWidget->size();
    if( cSize.height() != bufferOut->height() || cSize.width() != bufferOut->width() ){
        //cout << "On a besoin d'un redimentionnement video (" << bufferOut->width() << "x" << bufferOut->height() << ")" << endl;
        cSize.setHeight( bufferOut->height() );
        cSize.setWidth ( bufferOut->width()  );
    }

    //
    // ON ENVOIE L'IMAGE VERS L'OBJET EN CHARGE DU TRAITEMENT OPENGL...
    //
    _videoWidget->DrawImage( bufferOut );
    _avgDrawing    += ( (double)(clock() - startC) ) / ( CLOCKS_PER_SEC ) * 1000.0;

    //
    // ON MET A JOURS LES DONNEES ISSUES DE L'INTERFACE GRAPHIQUE
    //
    if( bufferIn->width() != _inWidth || bufferIn->height() != _inHeight){
        _inWidth  = bufferIn->width();
        _inHeight = bufferIn->height();
        inWidth ->setText( tr("Video width  : ") + QVariant(_inWidth).toString()  + tr(" pixel(s)") );
        inHeight->setText( tr("Video height : ") + QVariant(_inHeight).toString() + tr(" pixel(s)") );
    }
    if( bufferOut->width() != _ouWidth || bufferOut->height() != _ouHeight){
        _ouWidth  = bufferOut->width();
        _ouHeight = bufferOut->height();
        ouWidth ->setText( tr("Video width  : ") + QVariant(_ouWidth).toString()  + tr(" pixel(s)") );
        ouHeight->setText( tr("Video height : ") + QVariant(_ouHeight).toString() + tr(" pixel(s)") );
    }

    // LE TRAITEMENT DE L'IMAGE EST TERMINE
    processing = false;
    if(debug) cout << "#################### FIN  PlayerInterface::drawNextFrame()  ####################" << endl;;
}



void PlayerInterface::openFile(QString* name)
{

    //
    // CREATION D'UNE BOITE DE DIALOGUE POUR L'OUVERTURE DU FICHIER VIDEO
    // UNIQUEMENT LORSQUE L'UTILISATEUR N'A PAS PRECISE DE FICHIER LORS
    // DU LANCEMENT DU PROGRAMME A L'AIDE DE LA LIGNE DE COMMANDE
    //
    if( name == NULL)
        fileName = QFileDialog::getOpenFileName(this,
                                                tr("Video files"), "",
                                                tr("Video files (*.avi *.mpg *.mkv *.mov);;All Files (*)"));
    else
        fileName = *name;

    // SI PAS DE NOM DE FICHIER ALORS ON QUITTE
    if(fileName.isEmpty()) exit( 0 );

    // ON CREE UN OBJET VIDEO ET ON PREFETCH LA PREMIERE IMAGE
    c = new CVideo( fileName.toStdString().c_str() );
    c->start();
    // ON ACTIVE LES BOUTONS EN CONSEQUENCE
    start->setEnabled( true );
    nextFrame->setEnabled( true );
    filterFrame->setEnabled( true );

    // ON AFFICHE LA PREMIERE IMAGE DE LA VIDEO
    _isPlaying = true;
    drawNextFrame();

    // ON DEMARRE LE PROCESSUS DE TRAITEMENT TEMPS REEL
    poller->start();
}


//
// METHODE INVOQUEE LORSQUE L'UTILISATEUR CHANGE UN FILTRE DANS LA LISTE. SI LA VIDEO
// EST EN COURS DE DECODAGE ALORS ON NE FAIT RIEN, SI ELLE EST ARRETEE ALORS ON CHOISI
//
void PlayerInterface::changePosition(int newPosition)
{

    manageList(newPosition);


    cout << "(II) Un changement de filtre a ete enregistre... (" << newPosition << ")"  << endl;
    if( _isPlaying == true ) return;
    drawNextFrame();



}

void PlayerInterface::deleteWidget(int i) //supprime la liste i du layerList + dernier buffer
{
    listeFiltresVector[i]->deleteLater();
    listeFiltresVector.erase(listeFiltresVector.begin()+i);
    buffer.pop_back();
}


void PlayerInterface::calculBuffer(FastImage *bufferOut, FastImage *bufferIn) //Calcul l'image de sortie en fcontion des différents filtres en cours
{
    if (buffer.size()==0){ //si un seul filtre
        biblio.getFilter(listeFiltresVector[0]->currentIndex())->calculateFilter(bufferOut,bufferIn);
    }
    else
    {
        //cascadage des filtres
        biblio.getFilter(listeFiltresVector[0]->currentIndex())->calculateFilter(buffer[0],bufferIn);
        for(int j=1;j<buffer.size();j++){
            biblio.getFilter(listeFiltresVector[j]->currentIndex())->calculateFilter(buffer[j],buffer[j-1]);}

        // REDIMENTIONNEMENT SI NECESSAIRE DU BUFFER DE SORTIE puis recopie du dernier buffer dans bufferOut
        if( bufferOut->width() != buffer[buffer.size()-1]->width() || bufferOut->height() != buffer[buffer.size()-1]->height() ){
            bufferOut->resize(buffer[buffer.size()-1]->height(), buffer[buffer.size()-1]->width());
        }

        bufferOut->FastCopyTo(buffer[buffer.size()-1]);
    }
}


//
// METHODE INVOQUEE PAR LE PROCESSUS PERIODIQUE (1 SECONDE) ET DONT LE ROLE EST DE
// RAFRAICHIR LE NOMBRE DE FPS INDIQUE DANS LA BARRE DES TITRES
//
void PlayerInterface::frameCounterMethod(){
    int nbre      = decodedFrames;

    if( decodedFrames != 0 ){
        int v0 = ((int)(100*((double)_avgDecoding  )/((double)decodedFrames)))/100.0;
        int v1 = ((int)(100*((double)_avgProcessing)/((double)decodedFrames)))/100.0;
        int v2 = ((int)(100*((double)_avgDrawing   )/((double)decodedFrames)))/100.0;

        dTime ->setText( tr("Avg decoding   time : ") + QVariant(v0).toString()  + tr(" ms") );
        pTime ->setText( tr("Avg processing time : ") + QVariant(v1).toString()  + tr(" ms") );
        sTime ->setText( tr("Avg drawing    time : ") + QVariant(v2).toString()  + tr(" ms") );
    }

    // ON REMET A ZERO LES COMPTEURS DE PERFORMANCE...
    _avgDecoding   = 0;
    _avgProcessing = 0;
    _avgDrawing    = 0;

    frameAverage += nbre;
    seconds      += 1;
    decodedFrames = 0;
    int nAvg = ((float)(floor(((float)frameAverage/(float)seconds)*10))/10);
    this->setWindowTitle("Processing speed : " + QVariant(nbre).toString()
                         + " (Average : " + QVariant(nAvg).toString() + ")" );
}


//
// METHODE INVOQUEE LORSQUE L'UTILISATEUR DEMANDE LE PASSAGE EN MODE WEBCAM. ON
// VERIFIE SI UNE WEBCAM EST DISPONIBLE, SI OUI ALORS ON L'ACTIVE...
//
void PlayerInterface::startButton(){
    if( poller->isActive() ){
        poller->stop();						// ARRET DU TIMER VIDEO
        start->setText("Start video");
        nextFrame->setEnabled( true );
    }else{
        poller->start();					// DEMARRAGE DU TIMER VIDEO
        start->setText("Stop video");
        nextFrame->setEnabled( false );
    }

    // ON MEMORISE L'ETAT D'ACTIVITE DE L'APPLICATION
    _isPlaying = poller->isActive();
}


//
// METHODE INVOQUEE LORSQUE L'UTILISATEUR DEMANDE DE BRIDER OU DEBRIDER LE FRAME
// RATE DU TRAITEMENT VIDEO.
//
void PlayerInterface::unlockFrameRate(){
    if( poller->interval() == (1000/25) ){
        filterFrame->setText("Limit to 24 fps");
        poller->setInterval( 5 );
    }else{
        filterFrame->setText("Unlock framerate");
        poller->setInterval( 1000/25 );
    }
}

//
// METHODE INVOQUEE LORSQUE L'UTILISATEUR DEMANDE LE PASSAGE EN MODE WEBCAM. ON
// VERIFIE SI UNE WEBCAM EST DISPONIBLE, SI OUI ALORS ON L'ACTIVE...
//
void PlayerInterface::switchToWebCam(){
    cout << "(II) Changement du comportement (1) : " << isWebCam << endl;
    isWebCam = ! isWebCam;
    if( isWebCam )
        pause       = new QPushButton( "Switch to file", this );
    else
        pause       = new QPushButton( "Switch to camera", this );
    cout << "(II) Changement du comportement (2) : " << isWebCam << endl;
}


//
// METHODE INVOQUEE LORSQUE L'UTILISATEUR DEMANDE L'AVANCEMENT MANUEL D'UNE IMAGE
//
void PlayerInterface::stepOneFrame(){
    cout << "(II) PlayerInterface::stepOneFrame()" << endl;
    if(_isPlaying == true){
        return;
    }
    _isPlaying = true;
    drawNextFrame();
    _isPlaying = false;
    cout << "(II) FIN PlayerInterface::stepOneFrame()" << endl;
}

void PlayerInterface::resetFilters(){
    _listeFiltres->setCurrentIndex(0);
}


#include "MyScene.h"

using namespace std;
MyScene::MyScene(QObject* parent) : QGraphicsScene(parent) {

    this->background.load("images/fond.jpg");//Chargement du fond et etaille de scène
    this->setSceneRect(0, 0, 5000,2000);

    timer = new QTimer(this);
    temps= new QTime(0,0,0);//timer de ma vue en haut à droite

    ifstream file("scores/score.txt");  //Lecture du score
    if (file.is_open()){
    string line;
    getline(file, line);
    boulette = line.c_str();
    bestscore=QString(boulette);
    getline(file, line);
    maxtemps=stoi(line);
    file.close();
    }

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(30); //toutes les 30 millisecondes

///////////////////////Initialisation///////////////////////////////////
    hitbox = new QGraphicsRectItem(10, 1, 55, 100);//mise en place d'une hitbox car mon image c'est pas pratique
    hitbox->setPos(100,1700);
    hitbox->hide();


    sons=new QMediaPlayer;
    sons->setMedia(QUrl::fromLocalFile("sons/ambiance.mp3"));
    sons->play();

    mort=new QMediaPlayer;
    mort->setMedia(QUrl::fromLocalFile("sons/mortv2.mp3"));
    mort->setVolume(40);

    fin_music=new QMediaPlayer;
    fin_music->setMedia(QUrl::fromLocalFile("sons/fin.mp3"));
    fin_music->setVolume(40);

    piece_music=new QMediaPlayer;
    piece_music->setMedia(QUrl::fromLocalFile("sons/piece.mp3"));
    piece_music->setVolume(40);


///////////////////////Creation de liste ///////////////////////////////////
     for(int i=0;i<3;i++){
         plateforme.append(new QGraphicsRectItem(10, 1, 400, 30));
         plateforme[i]->setBrush(Qt::gray);
         this->addItem(plateforme[i]);
     }
     for(int i=3;i<7;i++){
         plateforme.append(new QGraphicsRectItem(10, 1, 1000, 30));
         plateforme[i]->setBrush(Qt::gray);
         this->addItem(plateforme[i]);
     }
     for(int i=7;i<13;i++){
         plateforme.append(new QGraphicsRectItem(10, 1, 50, 30));
         plateforme[i]->setBrush(Qt::gray);
         this->addItem(plateforme[i]);
     }
        plateforme.append(new QGraphicsRectItem(10, 1, 50, 200));
        plateforme[13]->setBrush(Qt::gray);
        this->addItem(plateforme[13]);

        plateforme.append(new QGraphicsRectItem(10, 1, 50, 30));
        plateforme[14]->setBrush(Qt::gray);
        this->addItem(plateforme[14]);


     for(int i=0;i<5;i++){
         danger.append(new QGraphicsRectItem(10, 1, 200, 30));
         danger[i]->setBrush(Qt::red);
         this->addItem(danger[i]);
     }
     for(int i=5;i<9;i++){
         danger.append(new QGraphicsRectItem(10, 1, 20, 150));
         danger[i]->setBrush(Qt::red);
         this->addItem(danger[i]);
     }
     for(int i=9;i<12;i++){
         danger.append(new QGraphicsRectItem(10, 1, 50, 30));
         danger[i]->setBrush(Qt::red);
         this->addItem(danger[i]);
     }

     for(int i=0;i<4;i++){
         checkpoint.append(new QGraphicsRectItem(10, 1, 100, 100));
         checkpoint[i]->setBrush(Qt::cyan);
         checkpoint[i]->setOpacity(0.5);
         this->addItem(checkpoint[i]);
     }

     for(int i=0;i<6;i++){
         message.append(new QGraphicsTextItem);
         this->addItem(message[i]);
     }

     for(int i=0;i<10;i++){
     piecepos=new Pieces;
     pieces.append(piecepos);
     this->addItem(pieces[i]->piece);
     }

/////////////////////////Mise en place////////////////////////////
     plateforme[0]->setPos(1000,1481);//moyenne
     plateforme[1]->setPos(250,1665);
     plateforme[2]->setPos(3186,930);

     plateforme[3]->setPos(3050,1520);//grande
     plateforme[4]->setPos(0,1800);
     plateforme[5]->setPos(1377,1800);
     plateforme[6]->setPos(2377,1800);

     plateforme[14]->setPos(2937,1690);//petite mouvy

     plateforme[7]->setPos(3982,1403);//petit
     plateforme[8]->setPos(3762,1253);
     plateforme[9]->setPos(3994,1200);
     plateforme[10]->setPos(3780,1050);
     plateforme[11]->setPos(2700,1550);
     plateforme[12]->setPos(2902,1450);

     plateforme[13]->setPos(818,1600);//mur

     danger[0]->setPos(1374,1519);//moyenne rouge
     danger[1]->setPos(1679,1519);
     danger[2]->setPos(2467,1630);
     danger[3]->setPos(2667,1630);
     danger[4]->setPos(3768,850);

     danger[5]->setPos(1981,1680);//mur rouge
     danger[6]->setPos(2113,1680);
     danger[7]->setPos(2200,1680);
     danger[8]->setPos(2974,1620);

     danger[9]->setPos(2477,1770);//petite mouvy
     danger[10]->setPos(2607,1770);
     danger[11]->setPos(2737,1770);

     checkpoint[0]->setPos(1572,1700);
     checkpoint[1]->setPos(2292,1700);
     checkpoint[2]->setPos(2852,1700);
     checkpoint[3]->setPos(3772,1420);

    pieces[0]->piece->setPos(814,1440);
    pieces[1]->piece->setPos(1210,1220);
    pieces[2]->piece->setPos(1390,1680);
    pieces[3]->piece->setPos(2550,1320);
    pieces[4]->piece->setPos(3250,1260);
    pieces[5]->piece->setPos(3400,1260);
    pieces[6]->piece->setPos(3550,1260);
    pieces[7]->piece->setPos(4150,980);
    pieces[8]->piece->setPos(3660,660);
    pieces[9]->piece->setPos(58,1420);

     message[0]->setPos(300,1510);
     message[0]->setPlainText("Bienvenue sur mon magnifique jeu !");
     message[0]->setScale(1.5);
     message[0]->setDefaultTextColor(Qt::red);

     message[1]->setPos(1506,1260);
     message[1]->setPlainText("Attention aux plateformes rouges !!!!!");
     message[1]->setScale(1.5);
     message[1]->setDefaultTextColor(Qt::red);

     message[2]->setPos(1596,1610);
     message[2]->setPlainText("Checkpoint !!!");
     message[2]->setScale(1.5);
     message[2]->setDefaultTextColor(Qt::cyan);

     message[3]->setPos(80,1570);
     message[3]->setPlainText("Utilise ZQSD pour te déplacer et ESPACE pour sauter ainsi que P pour mettre en pause");
     message[3]->setScale(1.5);
     message[3]->setDefaultTextColor(Qt::yellow);

     message[4]->setPos(20,1400);
     message[4]->setPlainText("Ceci est une piece !");
     message[4]->setScale(1.5);
     message[4]->setDefaultTextColor(Qt::cyan);

     message[5]->setPos(50,1545);
     message[5]->setPlainText("Utilise le menu déroulant en haut à gauche pour recommencer ou quitter ainsi que le meilleur score");
     message[5]->setScale(1.5);
     message[5]->setDefaultTextColor(Qt::yellow);

///////////////////////////////Initialision pour premier plan/////////////////////////////////////
     perso = new QGraphicsPixmapItem(QPixmap("images/perso1.png"));
     perso->setPos(hitbox->pos().rx()+10,hitbox->pos().ry());
     perso->setScale(0.1);

     imgpieceaffichage = new QGraphicsPixmapItem(QPixmap("images/piece.png"));
     imgpieceaffichage->setScale(0.1);
     this->addItem(imgpieceaffichage);

     finish = new QGraphicsPixmapItem(QPixmap("images/flag.png"));
     finish->setPos(3194,820);
     finish->setScale(0.1);
     this->addItem(finish);
     this->addItem(perso);
     this->addItem(hitbox);

     chrono = new QGraphicsTextItem("00:00");
     chrono->setScale(2);
     chrono->setDefaultTextColor(Qt::red);
     this->addItem((chrono));

     cptpiece = new QGraphicsTextItem("0");
     cptpiece->setScale(2);
     cptpiece->setDefaultTextColor(Qt::red);
     this->addItem((cptpiece));

     pauseimg = new QGraphicsPixmapItem(QPixmap("images/pause.jpg"));
     this->addItem(pauseimg);
     pauseimg->setScale(2);
     pauseimg->hide();

}
/////////////////////////////////////////////////////////////////////////////////////////////////
void MyScene::drawBackground(QPainter *painter, const QRectF &rect) {
    Q_UNUSED(rect);
    painter->drawPixmap(sceneRect(), background, background.rect());
}
/////////////////////////////////////////////////////////////////////////////////////////////////
MyScene::~MyScene() {

}
void MyScene::mouvement_x(QGraphicsRectItem * plateforme,QPointF pos,int vitesse) {
    QPointF pos2 = plateforme->pos();//recuperation de la position de la plateforme

    if(mvt<60){
        if(mvt<30){//aller
            plateforme->setPos(pos2.rx()+vitesse, pos2.ry());
    }
        if(mvt>=30){//retour
            plateforme->setPos(pos2.rx()-vitesse, pos2.ry());
        }
        mvt++;
    }
    else{
        mvt=0;
    }
    if (hitbox->collidesWithItem(plateforme)) {//Mise en inertie du personnage en fonction de la plateforme
        is_jump=0;
        if(mvt<=30){
            hitbox->setPos(pos.rx()+vitesse+vx, pos.ry()+vy);
    }
        if(mvt>30){
            hitbox->setPos(pos.rx()-vitesse+vx, pos.ry()+vy);
        }
    }

}
/////////////////////////////////////////////////////////////////////////////////////////////////
 void MyScene::mouvement_y(QGraphicsRectItem * plateforme,int vitesse) {
QPointF pos2 = plateforme->pos();
if(mvt2<90){
    if(mvt2<45){//descendre
        plateforme->setPos(pos2.rx(), pos2.ry()+vitesse);
}
    if(mvt2>=45){//monter
        plateforme->setPos(pos2.rx(), pos2.ry()-vitesse);
    }
    mvt2+=1;
}
else{
    mvt2=0;
}
}
 /////////////////////////////////////////////////////////////////////////////////////////////////
 void MyScene::check(QGraphicsRectItem *plateforme){
     if (hitbox->collidesWithItem(plateforme)) {
         checkpoint_pos=new QPointF(hitbox->pos());//actualisation de la position
     }
 }
 /////////////////////////////////////////////////////////////////////////////////////////////////
void MyScene::mechant(QGraphicsRectItem * plateforme){

    if (hitbox->collidesWithItem(plateforme)) {//relancement du son de mort ainsi que reposition
        mort->stop();
        hitbox->setPos(checkpoint_pos->rx(),checkpoint_pos->ry());
        mort->play();
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void MyScene::recuppiece(Pieces * piecefct){

    if (hitbox->collidesWithItem(piecefct->piece)) {//utilisation de la classe piece
        if(piecefct->is_eaten==0){
            piece_music->stop();
            piecefct->is_eaten=1;
            this->removeItem(piecefct->piece);
            piecefct->piece->hide();
            compteurpiece+=1;
            piece_music->play();
        }
    }

    }
/////////////////////////////////////////////////////////////////////////////////////////////////
void MyScene::deplacement(QPointF pos) {
    if (noclip==false){
        hitbox->setPos(pos.rx()+vx, pos.ry()+vy+10);//actualisation de la position
        if(vy<0){
            vy+=vg;
        }
        else{
            vy=0;
        }
    }
    else{
        hitbox->setPos(pos.rx()+vx, pos.ry()+vy);
    }


}
/////////////////////////////////////////////////////////////////////////////////////////////////
void MyScene::slot_restart() {//recommencer au début du jeu
    vx=0;
    vy=0;
    hitbox->setPos(100,1690);
    checkpoint_pos=new QPointF(100,1700);
    temps=new QTime(0,0,0);
    tempsint=0;

}
/////////////////////////////////////////////////////////////////////////////////////////////////
void MyScene::fin() {
    QString tempssauv=temps->toString("mm:ss");
    if(tempsint<maxtemps){//comparaison entre le meilleur temps et le temps parcouru
        bestscore=tempssauv;
        maxtemps=tempsint;
    }
    sons->stop();
    fin_music->play();
/////////////////////////////////Lecture du fichier(aide de chat GPT)/////////////
    FILE* fic_score = fopen("scores/score.txt", "w");
    QString texte=QString("%1\n%2 ").arg(bestscore).arg(maxtemps);
    fputs(texte.toUtf8(), fic_score);
    fclose(fic_score);
    bool verif=clafin.exec();
////////////////////////////////////////////////////////////////////////////////////
    antirepetition=0;//empeche de repeter la pop up

    if (verif==true ){//explation de la réponse du Qdialog
        slot_restart();
    }
    else{
        emit mysignal();
        this->clear();
    }

}
/////////////////////////////////////////////////////////////////////////////////////////////////
void MyScene::collision_map(QPointF pos){
    /////////////////////Bord de map ///////////////////////
        if (hitbox->pos().rx()<0) {
        hitbox->setPos(pos.rx()-vx, pos.ry()+vy);
        }
        if (hitbox->pos().rx()>5000) {
        hitbox->setPos(pos.rx()-vx, pos.ry()+vy);
        }
        if (hitbox->pos().ry()<0) {
        hitbox->setPos(pos.rx()+vx, pos.ry()-vy);
        }
        if (hitbox->pos().ry()>2000) {
        hitbox->setPos(checkpoint_pos->rx(),checkpoint_pos->ry());
        mort->play();
        }
    ///////////////////////////////////////////////////////
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void MyScene::collisions(QPointF pos,QGraphicsRectItem * plateforme) {
///////////////////SOL////////////////////
    QRectF rect=plateforme->rect();//dimmention plateforme
    float width = rect.width();
    float height = rect.height();
    if (hitbox->collidesWithItem(finish)) {//verification de la collision avec l'arriver
        if(antirepetition==0){
            antirepetition++;
           fin();
         }
     }
    if (hitbox->collidesWithItem(plateforme)) {
        if (width>height){//ce if sert pour savoir si c'est un mur
            if(hitbox->pos().ry()>=plateforme->pos().ry()-height&&hitbox->pos().rx()>=plateforme->pos().rx()-width/4&&hitbox->pos().rx()<=plateforme->pos().rx()+width){
                vy=0;
                hitbox->setPos(pos.rx(), pos.ry()+10);
            }
        }
////////////////////////////////////////////Collision global///////////////////////////////////////////////////////////:::
        if(hitbox->pos().rx()<=plateforme->pos().rx()&&hitbox->pos().ry()>=plateforme->pos().ry()-80&&is_jump==0){
            hitbox->setPos(pos.rx(), pos.ry()+vy);
        }
        else if(hitbox->pos().rx()<=plateforme->pos().rx()&&hitbox->pos().ry()>=plateforme->pos().ry()-80){
            hitbox->setPos(pos.rx(), pos.ry()+vy+10);
        }
        else if(hitbox->pos().rx()>=plateforme->pos().rx()&&hitbox->pos().ry()>=plateforme->pos().ry()-80&&is_jump==0){
            hitbox->setPos(pos.rx(), pos.ry()+vy);
        }
        else if(hitbox->pos().rx()>=plateforme->pos().rx()&&hitbox->pos().ry()>=plateforme->pos().ry()-80){
            hitbox->setPos(pos.rx(), pos.ry()+vy+10);
        }
        else{
            hitbox->setPos(pos.rx()+vx,plateforme->pos().ry()-100);
            vy=0;
            is_jump=0;
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void MyScene::update() {
is_jump=1;//empechement de sauter

QList<QGraphicsView*> mesVues=this->views();//mise de la vue
mesVues[0]->centerOn(hitbox);

//actualisation du chronometre
tempsint++;
*temps=temps->addMSecs(30);
chrono->setPlainText(temps->toString("mm:ss"));


QPointF pos = hitbox->pos(); //récupération de la position
//qDebug()<<hitbox->pos().rx()<<" : "<<hitbox->pos().ry(); //permet de verifier la position du personnage
////////////////////Mise en place dynamique de la scene//////////////////
perso->setPos(pos.rx()+10,pos.ry());
chrono->setPos(pos.rx()+450,pos.ry()-250);
imgpieceaffichage->setPos(pos.rx()+300,pos.ry()-250);
cptpiece->setPlainText(QString("%1").arg(compteurpiece));
cptpiece->setPos(pos.rx()+350,pos.ry()-250);
/////////////////////////////////////////////////////////////
deplacement(pos);//Fonction de saut

///////////////////Appel des collisions//////////////////////
mouvement_x(plateforme[0],pos,4);
for(int i=9;i<=11;i++){
    mouvement_y(danger[i],7);
}
if (noclip==false){
for(int i = 0; i < plateforme.size(); i++) {
    collisions(pos,plateforme[i]);
    }
for(int i=0;i<danger.size();i++){
    mechant(danger[i]);
    }
for(int i=0;i<checkpoint.size();i++){
    check(checkpoint[i]);
    }
for(int i=0;i<pieces.size();i++){
    recuppiece(pieces[i]);
    }
}
collision_map(pos);
///////////////////////Animation du personnage/////////////////////////////////////
if (ralentissement>20){//boucle d'animation du personnage avec un ralentisseur d'animation
QImage image(QString("images/perso%1.png").arg(compteurimage));
    perso->setPixmap(QPixmap::fromImage(image));
    compteurimage++;
    if (compteurimage > 2) {
        compteurimage = 1;
    }
    ralentissement=0;
}
ralentissement++;

}
/////////////////////////////////////////////////////////////////////////////////////////////////
void MyScene::keyPressEvent(QKeyEvent* event){

if (pause==false){
if(event->key() == Qt::Key_Space) {//Saut avec espace
    if(is_jump==0){
        vy=-25;
        is_jump=1;
    }
   }
if(event->key() == Qt::Key_Q) { // appui sur la touche Q du clavier
    vx-=vitesse;
}
if(event->key() == Qt::Key_D) { // appui sur la touche D du clavier
    vx+=vitesse;
}
if (noclip==true){
    if(event->key() == Qt::Key_Z) { // appui sur la touche Z du clavier
        vy-=vitesse;
    }
    if(event->key() == Qt::Key_S) { // appui sur la touche S du clavier
        vy+=vitesse;
    }
}
if(event->key() == Qt::Key_G) { // appui sur la touche G du clavier TOUCHE EXPERIMENTAL DE TEST

if (noclip==false){
    vx=0;
    vy=0;
    vitesse=20;

    noclip=true;

}
else if (noclip==true){
    noclip=false;
    vitesse=6;
    vx=0;
    vy=0;

}
}
}


if(event->key() == Qt::Key_P) { // appui sur la touche P du clavier et mise en pause du jeu
    if (pause==false){
timer->stop();
pauseimg->setPos(perso->pos().rx()-800,perso->pos().ry()-400);
pauseimg->show();
pause=true;
    }
    else if (pause==true){
timer->start(30);
pause=false;
pauseimg->hide();
vx=0;
    }
}
}

void MyScene::keyReleaseEvent(QKeyEvent* event){
if(event->key() == Qt::Key_Q) { // relachement sur la touche Q du clavier
    vx+=vitesse;
}
if(event->key() == Qt::Key_D) { // relachement sur la touche D du clavier
    vx-=vitesse;
}
if (pause==false){
    if (noclip==true){
        if(event->key() == Qt::Key_Z) { // relachement sur la touche Z du clavier
            vy+=vitesse;
        }
        if(event->key() == Qt::Key_S) { // relachement sur la touche S du clavier
            vy-=vitesse;
        }
    }
}
}

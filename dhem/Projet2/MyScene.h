#ifndef CPP_QT_TPMINIPROJET_MYSCENE_H
#define CPP_QT_TPMINIPROJET_MYSCENE_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QTime>
#include <QKeyEvent>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsView>
#include <QLabel>
#include <QPropertyAnimation>
#include <QDialog>
#include <QMediaPlayer>
#include <QDebug>
#include <QList>
#include <fstream>
#include <iostream>
#include "diagfin.h"
#include "pieces.h"

class MyScene : public QGraphicsScene {
    Q_OBJECT

public:
    MyScene(QObject* parent = nullptr);
    virtual ~MyScene();

    QTimer* timer;//timer pour update
    QTime* temps;//temps pour l'afficher dans le jeu
    QGraphicsRectItem* hitbox;//hitbox de mon personnage
    QGraphicsTextItem* chrono;//il recupere temps
    QGraphicsPixmapItem* perso;
    QGraphicsPixmapItem* finish;
    QGraphicsPixmapItem* pauseimg;
    QGraphicsPixmapItem* imgpieceaffichage;//une piece en tant que compteur en haut à droite
    QGraphicsTextItem* cptpiece;//affichage du nombre de piece recuperer
//////////////sons//////////////
    QMediaPlayer* sons;
    QMediaPlayer* mort;
    QMediaPlayer* fin_music;
    QMediaPlayer* piece_music;
///////////////////////////////
    QList<QGraphicsRectItem*> plateforme;
    QList<QGraphicsRectItem*> danger;
    QList<QGraphicsRectItem*> checkpoint;
    QList<QGraphicsTextItem*> message;
    QList<Pieces*> pieces;//liste de piece
    Pieces *piecepos;//class pour faire des pieces
    Diagfin clafin;//QDialog de fin
    QString bestscore;//le meilleur score
    QPixmap background;//le fond
    QPointF * checkpoint_pos=new QPointF(100,1700);//position de respawn


    const char* boulette;//recup de la premiere ligne du fichier score
    int compteurpiece=0;//compteur des pieces
    int compteurimage=1;//compteur pour animation perso
    int tempsint=0;//compteur pour le meilleurs temps en entier de 30 millisecondes
    int maxtemps=100000000;//constante de temps
    int ralentissement=0;//ralentisseur
    int mvt=0;//constante pour mouvement x
    int mvt2=0;//constante pour mouvement y
    int antirepetition=0;//empeche la pop up de fin de ce repeter
    double vx = 0;//coordonnee en x
    double vy = 0;//coordonnee en y
    double vg = 0.8;//gravite
    int is_jump;//savoir si il saute
    int vitesse = 6;//vitesse du personnage
    bool noclip=false;//utilisation du god mod
    bool pause=false;//mise en pause

public slots:
    void update();//dynamisme de la scene
    void keyPressEvent(QKeyEvent* event);//appuie de touches
    void keyReleaseEvent(QKeyEvent *event);//relachement de touche
    void drawBackground(QPainter* painter, const QRectF& rect);//mise en place du background
    void deplacement(QPointF pos);
    void collisions(QPointF pos,QGraphicsRectItem * plateforme);
    void collision_map(QPointF pos);//bordure de map
    void slot_restart();
    void mouvement_x(QGraphicsRectItem * plateforme,QPointF pos,int vitesse);
    void mouvement_y(QGraphicsRectItem * plateforme,int vitesse);
    void mechant(QGraphicsRectItem * plateforme);
    void check(QGraphicsRectItem * plateforme);
    void fin();
    void recuppiece(Pieces * piecefct);
signals:
    void mysignal();
};


#endif //CPP_QT_TPMINIPROJET_MYSCENE_H

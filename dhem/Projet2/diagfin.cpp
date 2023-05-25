#include "diagfin.h"

Diagfin::Diagfin()
{
    this->setWindowTitle("Vous avez trouvé le Nyan Cat perdu !");
    this->setMinimumWidth(500);
    this->bouton1 = new QPushButton("Restart");
    connect(bouton1, SIGNAL(clicked()), this, SLOT(accept()));
    this->bouton2 = new QPushButton("Quit");
    connect(bouton2, SIGNAL(clicked()), this, SLOT(reject()));
    //char * test="test";
    this->label1 = new QLabel("Bravo vous avez fini !!!!!");
    label1->setAlignment(Qt::AlignCenter);
    QVBoxLayout* layoutprincipale = new QVBoxLayout;
    QHBoxLayout* layoutsecondaire = new QHBoxLayout;
    layoutprincipale->addWidget(label1);
    layoutsecondaire->addWidget(bouton1);
    layoutsecondaire->addWidget(bouton2);
    layoutprincipale->addLayout(layoutsecondaire);
    this->setLayout(layoutprincipale);
}



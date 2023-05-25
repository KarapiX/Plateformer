#include "score.h"
using namespace std;
Score::Score()
{
    this->setWindowTitle("Ma fenetre graphique");
    this->setMinimumWidth(500);
    this->bouton1 = new QPushButton("Ok");
    connect(bouton1, SIGNAL(clicked()), this, SLOT(accept()));
    this->bouton2 = new QPushButton("Cancel");
    connect(bouton2, SIGNAL(clicked()), this, SLOT(reject()));

//////////////////////Ouverture du fichier(trouver avec chat GPT)///////////////
    ifstream file("scores/score.txt");
    string line;
    if (file.is_open()){
    getline(file, line);
    const char* value = line.c_str();
    QString texte=QString(value);
    QString autretexte=QString("Meilleur score : %1").arg(texte);
    this->label1 = new QLabel(autretexte);
    file.close();
}
/////////////////////////Mise en place de la pop up/////////////////////////////////
    QVBoxLayout* layoutprincipale = new QVBoxLayout;
    QHBoxLayout* layoutsecondaire = new QHBoxLayout;
    label1->setAlignment(Qt::AlignCenter);
    layoutprincipale->addWidget(label1);
    layoutsecondaire->addWidget(bouton1);
    layoutsecondaire->addWidget(bouton2);
    layoutprincipale->addLayout(layoutsecondaire);
    this->setLayout(layoutprincipale);
}


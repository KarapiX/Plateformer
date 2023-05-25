#ifndef DIAGFIN_H
#define DIAGFIN_H

#include<QDialog>
#include<QLabel>
#include<QLayout>
#include<QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>

class Diagfin : public QDialog
{
    Q_OBJECT
public:

    Diagfin();

private:
    QPushButton *bouton1;
    QPushButton *bouton2;
    QLabel *label1;

};

#endif // DIAGFIN_H

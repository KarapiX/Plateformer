#ifndef SCORE_H
#define SCORE_H
#include<QDialog>
#include<QLabel>
#include <QMainWindow>
#include<QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QFile>
#include <QString>
#include <QList>
#include <fstream>
#include <iostream>
class Score : public QDialog
{
    Q_OBJECT
public:
    Score();

private:
    QPushButton *bouton1;
    QPushButton *bouton2;
    QLabel *label1;
};

#endif // SCORE_H

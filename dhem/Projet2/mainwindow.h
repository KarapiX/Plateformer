#ifndef CPP_QT_TPMINIPROJET_MAINWINDOW_H
#define CPP_QT_TPMINIPROJET_MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QMessageBox>


#include "MyScene.h"
#include "score.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

private :
    MyScene* mainScene;
    QGraphicsView* mainView;
    QMenu* helpMenu;
    QGraphicsView* vue1;
    Score score;

public:
    MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

public slots:
    void slot_quitter();
    void slot_restart();
    void slot_score();
};


#endif //CPP_QT_TPMINIPROJET_MAINWINDOW_H

#include "MainWindow.h"
#include "MyScene.h"
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    this->mainScene = new MyScene;
    vue1 = new QGraphicsView;
    this->mainView = new QGraphicsView;
    this->vue1->setScene(mainScene);
    this->setCentralWidget(vue1);
    this->setWindowTitle("Pedro the Bear");
    this->resize(1300,750);

/////////////////////////////Menu deroulant//////////////////////////////////
    helpMenu = menuBar()->addMenu(tr("&Menu"));
    QAction* actionrestart = new QAction(tr("&Restart"), this);
    QAction* actionquit = new QAction(tr("&Quit"), this);
    QAction* scr = new QAction(tr("&Meilleurs Scores"), this);
    connect(actionrestart, SIGNAL(triggered()), this, SLOT(slot_restart()));
    connect(actionquit, SIGNAL(triggered()), this, SLOT(slot_quitter()));
    connect(scr, SIGNAL(triggered()), this, SLOT(slot_score()));
    helpMenu->addAction(actionrestart);
    helpMenu->addAction(actionquit);
    helpMenu->addAction(scr);

 connect(this->mainScene, &MyScene::mysignal,this,&MainWindow::slot_quitter);

}


MainWindow::~MainWindow(){

}

void MainWindow::slot_quitter(){
    this->close();
}

void MainWindow::slot_restart(){
    mainScene->slot_restart();
}

void MainWindow::slot_score(){
    score.exec();
}

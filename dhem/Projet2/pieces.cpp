#include "pieces.h"

Pieces::Pieces(QObject *parent)
    : QObject{parent}
{
piece=new QGraphicsPixmapItem(QPixmap("images/piece.png"));
piece->setScale(0.15);
}

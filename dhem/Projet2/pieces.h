#ifndef PIECES_H
#define PIECES_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class Pieces : public QObject
{
    Q_OBJECT
public:
    explicit Pieces(QObject *parent = nullptr);
    QGraphicsPixmapItem * piece;
    int is_eaten=0;

};

#endif // PIECES_H

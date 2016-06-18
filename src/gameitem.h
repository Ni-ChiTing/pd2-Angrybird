#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <Box2D/Box2D.h>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QTransform>
#include <QtMath>

class GameItem : public QObject
{
    Q_OBJECT
public:
    GameItem(b2World *world);
    virtual~GameItem();
    static void setGlobalSize(QSizeF worldsize, QSizeF windowsize);
    void setgravity();
    float getvx();
    float getvy();
    virtual void hit();
    float getX();
    float getY();
    void setnogravity();
public slots:
    void paint();
    // TODO virtual void collide();

protected:
    b2Body *g_body;
    QGraphicsPixmapItem g_pixmap;
    QSizeF g_size;
    b2World *g_world;
    static QSizeF g_worldsize, g_windowsize;
};

#endif // GAMEITEM_H

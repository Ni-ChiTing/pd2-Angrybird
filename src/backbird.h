#ifndef BACKBIRD_H
#define BACKBIRD_H
#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <bird.h>
#define BIRD_DENSITY 10.0f
#define BIRD_FRICTION 0.5f
#define BIRD_RESTITUTION 0.2f
#include <QMediaPlayer>

class backbird: public Bird
{
public:
    backbird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void fuction();
};

#endif // BACKBIRD_H

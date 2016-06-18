#ifndef YELLOWBIRD_H
#define YELLOWBIRD_H
#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <bird.h>
#define BIRD_DENSITY 10.0f
#define BIRD_FRICTION 0.5f
#define BIRD_RESTITUTION 0.2f

class yellowbird:public Bird
{
public:
    yellowbird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void fuction();

};

#endif // YELLOWBIRD_H

#ifndef BIRD_H
#define BIRD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BIRD_DENSITY 10.0f
#define BIRD_FRICTION 0.5f
#define BIRD_RESTITUTION 0.2f

class Bird : public GameItem
{
public:
    Bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void setLinearVelocity(b2Vec2 velocity);
    void minusHP();
    int getHP();
    bool unfly;
    bool ifdelete;
        bool ifkey;
    void hit();
    virtual void fuction();
    void setdead();
 protected:
    int HP;
};

#endif // BIRD_H

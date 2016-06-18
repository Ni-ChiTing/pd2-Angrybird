#include "yellowbird.h"
#include "bird.h"
yellowbird::yellowbird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap, world, scene)
{

}

void yellowbird::fuction()
{
this->setLinearVelocity(b2Vec2(this->getvx()*3,this->getvy()));
    this->ifkey=true;
    this->g_pixmap.setPixmap(QPixmap(":/image/yellowbirdpress.png").scaled(40,40));
}



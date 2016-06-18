#include "backbird.h"

backbird::backbird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap, world, scene)
{

}

void backbird::fuction()
{
    float a;
    if(this->getvy()>0)
        a=-this->getvy();
    else
        a=this->getvy();
    this->setLinearVelocity(b2Vec2((-this->getvx()*2),a*8));
        this->g_pixmap.setPixmap(QPixmap(":/image/backbirdpress.png").scaled(40,40));
        this->ifkey=true;
}

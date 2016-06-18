#include "twohitbird.h"


twohitbird::twohitbird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap, world, scene)
{

}

void twohitbird::fuction()
{
    this->ifkey=true;
    this->setLinearVelocity(b2Vec2(0,0));
    this->unfly=true;
    this->setnogravity();
        this->g_pixmap.setPixmap(QPixmap(":/image/twohitbirdpress.png").scaled(40,40));
}

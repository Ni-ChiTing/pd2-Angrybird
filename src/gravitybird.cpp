#include "gravitybird.h"

gravitybird::gravitybird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap, world, scene)
{

}

void gravitybird::fuction()
{
    float a;
    if(this->getvy()>0)
        a=-this->getvy();
    else
        a=this->getvy();
    if (a<1&&a>0)
        a=3;
    if(a<0)
        a=-3;

    this->setLinearVelocity(b2Vec2(0,(a*9)));
        this->ifkey=true;
     this->g_pixmap.setPixmap(QPixmap(":/image/gravitybirdpress.png").scaled(40,40));
}

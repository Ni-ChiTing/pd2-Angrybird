#include "enermy.h"

enermy::enermy(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene,int hp1,int type1):GameItem(world),ifdelete(false),HP(hp1),Type(type1),r(radius)
{
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(radius*2,radius*2);
    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    bodydef.userData = this;
    g_body = world->CreateBody(&bodydef);
    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = ENERMY_DENSITY;
    fixturedef.friction = ENERMY_FRICTION;
    fixturedef.restitution = ENERMY_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
    scene->addItem(&g_pixmap);

}

int enermy::getHP()
{
    return HP;
}

void enermy::minusHP()
{
    HP=HP-1;

}

void enermy::setpic()
{
    if(Type==1)
    {
    if(HP<=1)
        g_pixmap.setPixmap(QPixmap(":/image/pig1.png").scaled(r*40*2,r*40*2));
    }
    if(Type==2)
    {
        if(HP<=4)
            g_pixmap.setPixmap(QPixmap(":/image/pigbn1.png").scaled(r*40*2,r*40*2));
        if(HP<=3)
            g_pixmap.setPixmap(QPixmap(":/image/pigbn2.png").scaled(r*40*2,r*40*2));
        if(HP<=2)
            g_pixmap.setPixmap(QPixmap(":/image/pigbn3.png").scaled(r*40*2,r*40*2));
        if(HP<=1)
            g_pixmap.setPixmap(QPixmap(":/image/pigbn4.png").scaled(r*40*2,r*40*2));

    }
    if(Type==3)
    {
        if(HP<=7)
            g_pixmap.setPixmap(QPixmap(":/image/pigbo1.png").scaled(r*40*2,r*40*2));
        if(HP<=5)
            g_pixmap.setPixmap(QPixmap(":/image/pigbo2.png").scaled(r*40*2,r*40*2));
        if(HP<=3)
            g_pixmap.setPixmap(QPixmap(":/image/pigbo3.png").scaled(r*40*2,r*40*2));
        if(HP<=1)
            g_pixmap.setPixmap(QPixmap(":/image/pigbo4.png").scaled(r*40*2,r*40*2));

    }
    if(Type==4)
    {
        if(HP<=7)
            g_pixmap.setPixmap(QPixmap(":/image/pigbk1.png").scaled(r*40*2,r*40*2));
        if(HP<=5)
            g_pixmap.setPixmap(QPixmap(":/image/pigbk2.png").scaled(r*40*2,r*40*2));
        if(HP<=3)
            g_pixmap.setPixmap(QPixmap(":/image/pigbk3.png").scaled(r*40*2,r*40*2));
        if(HP<=1)
            g_pixmap.setPixmap(QPixmap(":/image/pigbk4.png").scaled(r*40*2,r*40*2));

    }
    if(Type==5)
    {
        if(HP<=12)
            g_pixmap.setPixmap(QPixmap(":/image/pigbm1.png").scaled(r*40*2,r*40*2));
        if(HP<=9)
            g_pixmap.setPixmap(QPixmap(":/image/pigbm2.png").scaled(r*40*2,r*40*2));
        if(HP<=6)
            g_pixmap.setPixmap(QPixmap(":/image/pigbm3.png").scaled(r*40*2,r*40*2));
        if(HP<=3)
            g_pixmap.setPixmap(QPixmap(":/image/pigbm4.png").scaled(r*40*2,r*40*2));

    }
}

void enermy::hit()
{
    minusHP();
    setpic();
    if(HP<=0)
    {
    ifdelete=true;
    g_pixmap.setPixmap(QPixmap(":/image/delete.png").scaled(40*2,40*2));
    }
}

int enermy::gettype()
{
    return Type;
}

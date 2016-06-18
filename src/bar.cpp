#include "bar.h"
#include <qdebug.h>
bar::bar(float x, float y, float length, float hight, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene,int hp1,int type1):GameItem(world),ifdelete(false)
,HP(hp1),Type(type1),w(length),h(hight){
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
   // qDebug()<<g_pixmap.boundingRect().width()<<g_pixmap.boundingRect().height();
    g_size=QSize(length,hight);
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    bodydef.userData = this;
    g_body = world->CreateBody(&bodydef);
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox((length/2),(hight/2));
    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyBox;
    fixturedef.density = BAR_DENSITY;
    fixturedef.friction = BAR_FRICTION;
    fixturedef.restitution = BAR_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);
    // Bound timer
     connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
     scene->addItem(&g_pixmap);
    music =new QMediaPlayer();
    if(Type==1||Type==2)
    {
    music->setMedia(QUrl("qrc:/image/wood_break.mp3"));
   }
    if(Type==4||Type==3)
    {
    music->setMedia(QUrl("qrc:/image/stone_break.mp3"));
   }
    if(Type==5||Type==6)
    {
    music->setMedia(QUrl("qrc:/image/glass_break.mp3"));
   }
}

void bar::hithp()
{
    HP=HP-1;
}

int bar::getHP()
{
    return HP;
}

void bar::minusHP()
{
    HP=HP-1;

}

void bar::setpic()
{
    if(Type==1)//wood
    {
        if(HP<=8)
        {g_pixmap.setPixmap(QPixmap(":/image/wood5.png").scaled(w*40,h*40));
        }
        if(HP<=3)
            g_pixmap.setPixmap(QPixmap(":/image/wood10.png").scaled(w*40,h*40));
    }
    if(Type==2)//wood
    {
        if(HP<=8)
        {g_pixmap.setPixmap(QPixmap(":/image/woodt5.png").scaled(w*40,h*40));
        }
        if(HP<=3)
            g_pixmap.setPixmap(QPixmap(":/image/woodt10.png").scaled(w*40,h*40));
    }
    if(Type==3)//rock
    {
        if(HP<=20)
       {g_pixmap.setPixmap(QPixmap(":/image/rock1.png").scaled(w*40,h*40));

        if(HP<=12)
            g_pixmap.setPixmap(QPixmap(":/image/rock2.png").scaled(w*40,h*40));
        if(HP<=5)

            g_pixmap.setPixmap(QPixmap(":/image/rock3.png").scaled(w*40,h*40));

    }

     }
    if(Type==4)//rock
    {
        if(HP<=20)
       {g_pixmap.setPixmap(QPixmap(":/image/rockt1.png").scaled(w*40,h*40));

        if(HP<=12)
            g_pixmap.setPixmap(QPixmap(":/image/rockt2.png").scaled(w*40,h*40));
        if(HP<=5)

            g_pixmap.setPixmap(QPixmap(":/image/rockt3.png").scaled(w*40,h*40));

    }

     }
    if(Type==5)//ice
    {
        if(HP<=6)
       {g_pixmap.setPixmap(QPixmap(":/image/ice1.png").scaled(w*40,h*40));

        if(HP<=4)
            g_pixmap.setPixmap(QPixmap(":/image/ice2.png").scaled(w*40,h*40));
        if(HP<=2)

            g_pixmap.setPixmap(QPixmap(":/image/ice3.png").scaled(w*40,h*40));

    }

     }
    if(Type==6)//ice
    {
        if(HP<=6)
       {g_pixmap.setPixmap(QPixmap(":/image/icet1.png").scaled(w*40,h*40));

        if(HP<=4)
            g_pixmap.setPixmap(QPixmap(":/image/icet2.png").scaled(w*40,h*40));
        if(HP<=2)

            g_pixmap.setPixmap(QPixmap(":/image/icet3.png").scaled(w*40,h*40));


    }

    }
}

void bar::hit()
{
    minusHP();
    setpic();
    if(HP<=0)
        {
        ifdelete=true;
        music->play();
        g_pixmap.setPixmap(QPixmap(":/image/delete.png").scaled(40*2,40*2));
    }
}

int bar::returntype()
{
    return Type;
}




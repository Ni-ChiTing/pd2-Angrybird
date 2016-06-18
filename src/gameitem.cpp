#include "gameitem.h"

#include <iostream>
#include<QDebug>
GameItem::GameItem(b2World *world):
    g_body(NULL),g_world(world)
{
}

GameItem::~GameItem()
{

    g_world->DestroyBody(g_body);
}

QSizeF GameItem::g_windowsize = QSizeF();
QSizeF GameItem::g_worldsize = QSizeF();

void GameItem::setGlobalSize(QSizeF worldsize, QSizeF windowsize)
{
    g_worldsize = worldsize;
    g_windowsize = windowsize;
}

void GameItem::paint()
{
    b2Vec2 pos = g_body->GetPosition();
    //std::cout << g_body->GetAngle() << std::endl;
    QPointF mappedPoint;
    //qDebug()<<"body"<<pos.x<<pos.y;
    mappedPoint.setX(((pos.x-g_size.width()/2) * g_windowsize.width())/g_worldsize.width());
    mappedPoint.setY((1.0f - ((pos.y+g_size.height()/2)/g_worldsize.height())) * g_windowsize.height());
    g_pixmap.setPos(mappedPoint);
    //qDebug()<<mappedPoint;
     //qDebug()<<"body"<<g_pixmap.x()<<g_pixmap.y();
    g_pixmap.resetTransform();
    g_pixmap.setRotation(-(g_body->GetAngle()*180/3.14159));
}
void GameItem::setgravity()
{
    g_body->SetGravityScale(1);
}
float GameItem::getvy()
{
    return g_body->GetLinearVelocity().y;
}

void GameItem::hit()
{

}

float GameItem::getX()
{
    return g_body->GetPosition().x ;
}

float GameItem::getY()
{
    return g_body->GetPosition().y;
}

void GameItem::setnogravity()
{
     g_body->SetGravityScale(0);
}

float GameItem::getvx()
{
    return g_body->GetLinearVelocity().x;
}

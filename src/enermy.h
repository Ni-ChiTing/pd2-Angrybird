#ifndef ENERMY_H
#define ENERMY_H
#include "gameitem.h"
#include <QTimer>
#include <QPixmap>
#include <QGraphicsScene>
#define ENERMY_DENSITY 10.0f
#define ENERMY_FRICTION 0.5f
#define ENERMY_RESTITUTION 0.2f
class enermy:public GameItem
{
public:
    enermy(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene,int hp1,int type1);
    bool ifdelete;
    int getHP();
    void minusHP();
    void setpic();
    virtual void hit();
    int gettype();
 private:
    int HP;
    int Type;
    float r;
};

#endif // ENERMY_H

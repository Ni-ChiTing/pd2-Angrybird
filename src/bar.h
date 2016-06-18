#ifndef BAR_H
#define BAR_H
#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QMediaPlayer>
#define BAR_DENSITY 20.0f
#define BAR_FRICTION 0.5f
#define BAR_RESTITUTION 0.5f
class bar: public GameItem
{
public:
    bar(float x, float y, float length,float hight, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene,int hp1,int type1);
    void hithp();
    int getHP();
    void minusHP();
    bool ifdelete;
     void setpic();
      virtual void hit();
     int returntype();
     QMediaPlayer* music;

 protected:
    int HP;
    int Type;

    float w;
    float h;
};

#endif // BAR_H

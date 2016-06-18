#ifndef COLLISION_H
#define COLLISION_H
#include <Box2D/Box2D.h>

class collision: public b2ContactListener//繼承碰撞監聽
{
public:
    collision();
    void BeginContact(b2Contact* contact);
   void EndContact(b2Contact* contact);
};

#endif // COLLISION_H

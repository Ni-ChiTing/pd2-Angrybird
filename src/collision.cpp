#include "collision.h"
#include "bird.h"
#include "bar.h"
#include <qdebug.h>
#include "enermy.h"
#include "gameitem.h"
collision::collision()
{

}

void collision::BeginContact(b2Contact *contact)
{

}

void collision::EndContact(b2Contact *contact)
{

    if(contact->GetFixtureA()->GetBody()->GetType() == b2_dynamicBody)
     {

        void* temp=contact->GetFixtureA()->GetBody()->GetUserData();
            static_cast<GameItem*>(temp)->hit();
            //if( static_cast<GameItem*>(temp)->getHP()<=0)
            //{
              //  static_cast<GameItem*>(temp)->ifdelete=true;
            //

    }
    if(contact->GetFixtureB()->GetBody()->GetType() == b2_dynamicBody)
     {
        void* temp=contact->GetFixtureB()->GetBody()->GetUserData();

            static_cast<GameItem*>(temp)->hit();
    }
}

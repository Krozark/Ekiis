#ifndef NOTDRAWABLEBODY_HPP
#define NOTDRAWABLEBODY_HPP

#include <Box2D/Box2D.h>
#include "convert.h"


class NotDrawableBody{

     public:
        NotDrawableBody(float posx,float posy,b2BodyType type = b2_dynamicBody);
        virtual ~NotDrawableBody();

        virtual void SetPosition(float X,float Y){bodyDef.position.Set(toMet(X),-toMet(Y));}
        virtual void SetRotation(float angle){body->SetTransform(body->GetPosition(),toRad(angle));}

        inline void SetDensity(float d=1){body->DestroyFixture(fixture);fixtureDef.density=d;fixture=body->CreateFixture(&fixtureDef);};
        inline void SetFriction(float v=0.3){body->DestroyFixture(fixture);fixtureDef.friction=v;fixture=body->CreateFixture(&fixtureDef);};
        inline void SetElasticity(float e=0.5){body->DestroyFixture(fixture);fixtureDef.restitution=e;fixture=body->CreateFixture(&fixtureDef);};


        void DistanceJoinWith(NotDrawableBody& other,float hz=0);


    //protected :
        static b2BodyDef bodyDef;
        b2Body* body;
        b2Shape* b2shape;
        static b2FixtureDef fixtureDef;
        b2Fixture* fixture;
};
extern b2World world;

#endif

#ifndef BODY_HPP
#define BODY_HPP

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "convert.h"


class Body
{
    public:
        Body (float posx,float posy,b2BodyType type = b2_dynamicBody);

        virtual ~Body();

        virtual void Next();
        inline void Draw(sf::RenderTarget& window){window.Draw(*shape);};
        inline void SetPosition(float X,float Y){bodyDef.position.Set(toMet(X),-toMet(Y)); shape->SetPosition(sf::Vector2f(X,Y));}
        inline void SetDensity(float d=1){body->DestroyFixture(fixture);fixtureDef.density=d;fixture=body->CreateFixture(&fixtureDef);};
        inline void SetFriction(float v=0.3){body->DestroyFixture(fixture);fixtureDef.friction=v;fixture=body->CreateFixture(&fixtureDef);};
        inline void SetElasticity(float e=0.5){body->DestroyFixture(fixture);fixtureDef.restitution=e;fixture=body->CreateFixture(&fixtureDef);};
        inline void SetRotation(float angle){body->SetTransform(body->GetPosition(),toRad(angle));shape->SetRotation(angle);}
        void DistanceJoinWith(Body& other,float Ax,float Ay,float Bx,float By,float hz=0);

        void SetColor(sf::Color couleur);


    //protected:
        static b2BodyDef bodyDef;
        b2Body* body;
        b2Shape* b2shape;
        static b2FixtureDef fixtureDef;
        b2Fixture* fixture;
        sf::Shape* shape;

};

extern b2World world;

#endif

#include "SoftCircle.hpp"
#include "Circle.hpp"
#include  "math.h"

using namespace sf;

SoftCircle::SoftCircle(float posx,float posy,float rayon): Body(posx,posy), nb_circles(20)
{
  // Determine part radius
    const float angleStep = (pi * 2.0f) / nb_circles;
    const float sinHalfAngle = sinf(angleStep * 0.5f);
    const float subCircleRadius = sinHalfAngle * rayon / (1.0f + sinHalfAngle);
    float radius = (rayon - subCircleRadius * 2.0f) * (1.0f -0.5);

    /// create the centre circle
    shape = new CircleShape(radius);
    b2shape = new b2CircleShape;
    static_cast<b2CircleShape*>(b2shape)->m_p.Set(0,0); //position, relative to body position
    static_cast<b2CircleShape*>(b2shape)->m_radius = toMet(radius); //radius

    fixtureDef.shape = b2shape;
    fixture=body->CreateFixture(&fixtureDef);

    shape->SetOrigin(radius,radius);
    SetPosition(posx,posy);
    SetColor(Color::Red);

    /// create the other
    bodys = new Body*[nb_circles];

    float angle = 0;
     for (unsigned int i=0;i<nb_circles;++i)
    {
        bodys[i] = new CircleBody(cos(angle)*rayon+posx,sin(angle)*rayon+posy,subCircleRadius);
        bodys[i]->SetColor(Color(cos(angle)*255,255-sin(angle)*255,tan(angle)*255));

        angle += angleStep;
    }

    // join together
    b2DistanceJointDef jointDef;
    for (unsigned int i=0;i<nb_circles;++i)
    {
        const int neighborIndex = (i + 1)< nb_circles?i+1:0;
        bodys[i]->DistanceJoinWith(*this,0,0,0,0,4);
        bodys[i]->DistanceJoinWith(*bodys[neighborIndex],0,0,0,0,0);
    }
};

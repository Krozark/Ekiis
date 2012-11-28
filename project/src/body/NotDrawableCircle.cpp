#include "body/NotDrawableCircle.hpp"


NotDrawableCircleBody::NotDrawableCircleBody (float posx,float posy,float rayon,b2BodyType type) : NotDrawableBody(posx,posy,type)
{
    b2shape = new b2CircleShape;
    static_cast<b2CircleShape*>(b2shape)->m_p.Set(0,0); //position, relative to body position
    static_cast<b2CircleShape*>(b2shape)->m_radius = toMet(rayon); //radius

    fixtureDef.shape = b2shape;
    fixture=body->CreateFixture(&fixtureDef);
}

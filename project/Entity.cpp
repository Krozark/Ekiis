#include "Entity.hpp"

using namespace sf;

Entity::Entity (float posx,float posy) : Body(posx,posy,b2_dynamicBody)
{
    shape = new RectangleShape(Vector2f(50,50));
    b2shape = new b2PolygonShape;
   static_cast<b2PolygonShape*>(b2shape)->SetAsBox(toMet(50/2),toMet(50/2));

    fixtureDef.shape = b2shape;
    fixture=body->CreateFixture(&fixtureDef);

    shape->setOrigin(50/2,50/2);
    SetPosition(posx,posy);

    shape->setFillColor(Color::Green);
};

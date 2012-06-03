#include "Rect.hpp"

using namespace sf;

RectBody::RectBody(float posx,float posy,float sizex,float sizey,b2BodyType type) : Body(posx,posy,type)
{
    shape = new RectangleShape(Vector2f(sizex,sizey));
    b2shape = new b2PolygonShape;
   static_cast<b2PolygonShape*>(b2shape)->SetAsBox(toMet(sizex/2),toMet(sizey/2));

    fixtureDef.shape = b2shape;
    fixture=body->CreateFixture(&fixtureDef);

    shape->setOrigin(sizex/2,sizey/2);
    //shape->SetPosition(Vector2f(posx,posy));
    SetPosition(posx,posy);


    shape->setFillColor(Color::Blue);

};

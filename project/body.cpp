#include "body.hpp"

using namespace sf;



Body::Body (float posx,float posy,b2BodyType type) : NotDrawableBody(posx,posy,type)
{
    body->SetUserData( this );
};

Body::~Body()
{
    delete b2shape;
}

void Body::Draw(sf::RenderTarget& window)
{
    Next();
    window.draw(*shape);
}

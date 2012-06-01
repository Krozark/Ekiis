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

void Body::Next()
{
     b2Vec2 origine = body->GetPosition();
     shape->SetPosition(toPix(origine.x),-toPix(origine.y));
     shape->SetRotation(-toDeg(body->GetAngle())); // inutile ici...
};


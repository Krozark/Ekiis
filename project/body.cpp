#include "body.hpp"

using namespace sf;

b2BodyDef Body::bodyDef;
b2FixtureDef Body::fixtureDef;

Body::Body (float posx,float posy,b2BodyType type)
{
    bodyDef.type = type;
    bodyDef.position.Set(toMet(posx),-toMet(posy));
    body = world.CreateBody(&bodyDef);
    body->SetUserData( this );

    fixtureDef.density = 1.0f;      // densité de 1
    fixtureDef.friction = 0.4f;     // friction de 1
    fixtureDef.restitution= 0.5;

};

Body::~Body()
{
    // world.DestroyJoint(joints);
    world.DestroyBody(body);
    delete b2shape;
}

void Body::Next()
{
     b2Vec2 origine = body->GetPosition();
     shape->SetPosition(toPix(origine.x),-toPix(origine.y));
     shape->SetRotation(-toDeg(body->GetAngle())); // inutile ici...
};

void Body::SetColor(sf::Color couleur)
{
    shape->SetFillColor(couleur);
}


void Body::DistanceJoinWith(Body& other,float hz)
{
    b2DistanceJointDef jd;
    //b2Vec2 d;

    jd.Initialize(
      body, other.body,
      body->GetWorldCenter(), other.body->GetWorldCenter()
    );
    jd.collideConnected = true;
    jd.frequencyHz = hz;

    world.CreateJoint(&jd);
}

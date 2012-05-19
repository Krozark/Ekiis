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
    fixtureDef.friction = 0.3f;     // friction de 1
    fixtureDef.restitution=1.1;


};

Body::~Body()
{
    // world.DestroyJoint(joints);
    world.DestroyBody(body);
    delete b2shape;
}

void Body::Next()
{
     shape->SetPosition(toPix(body->GetPosition().x),-toPix(body->GetPosition().y));
     shape->SetRotation(-toDeg(body->GetAngle())); // inutile ici...
};

void Body::SetColor(sf::Color couleur)
{
    shape->SetFillColor(couleur);
}


void Body::DistanceJoinWith(Body& other,float Ax,float Ay,float Bx,float By)
{
    b2DistanceJointDef jd;
    b2Vec2 d;

    jd.bodyA = (body); //b2body*
    jd.bodyB = (other.body);//idem

    jd.localAnchorA.Set(toMet(Ax),-toMet(Ay));
    jd.localAnchorB.Set(toMet(Bx),-toMet(By));

    d = other.body->GetWorldPoint(jd.localAnchorB) - body->GetWorldPoint(jd.localAnchorA);

    jd.length = d.Length();
    world.CreateJoint(&jd);
}

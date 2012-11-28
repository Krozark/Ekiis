#include "body/NotDrawableBody.hpp"

b2BodyDef NotDrawableBody::bodyDef;
b2FixtureDef NotDrawableBody::fixtureDef;

NotDrawableBody::NotDrawableBody(float posx,float posy,b2BodyType type)
{
    bodyDef.type = type;
    bodyDef.position.Set(toMet(posx),-toMet(posy));
    body = world.CreateBody(&bodyDef);

    fixtureDef.density = 1.0f;      // densité de 1
    fixtureDef.friction = 0.4f;     // friction de 1
    fixtureDef.restitution= 0.5;
};

NotDrawableBody::~NotDrawableBody()
{
    world.DestroyBody(body);
    delete b2shape;
    delete fixture;
};

void NotDrawableBody::DistanceJoinWith(NotDrawableBody& other,float hz)
{
    b2DistanceJointDef jd;

    jd.Initialize(
      body, other.body,
      body->GetWorldCenter(), other.body->GetWorldCenter()
    );
    jd.collideConnected = true;
    jd.frequencyHz = hz;

    world.CreateJoint(&jd);
}

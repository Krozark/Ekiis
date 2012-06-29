#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "body.hpp"

class Entity : public Body
{
    public:
        Entity (float posx,float posy);

        //virtual void Draw(sf::RenderTarget& window);
        //void SetPosition(float X,float Y){bodyDef.position.Set(toMet(X),-toMet(Y)); shape->setPosition(X,Y);}
        inline void AddForce(const float X,const float Y) {body->ApplyForceToCenter(b2Vec2(X,Y));}



};

#endif

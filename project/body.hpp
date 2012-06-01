#ifndef BODY_HPP
#define BODY_HPP

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "NotDrawableBody.hpp"


class Body : public NotDrawableBody
{
    public:
        Body (float posx,float posy,b2BodyType type = b2_dynamicBody);
        ~Body();

        //redefinition
        void SetPosition(float X,float Y){bodyDef.position.Set(toMet(X),-toMet(Y)); shape->SetPosition(sf::Vector2f(X,Y));}
        void SetRotation(float angle){body->SetTransform(body->GetPosition(),toRad(angle));shape->SetRotation(angle);}

        ///new
        virtual void Draw(sf::RenderTarget& window);

        inline void SetColor(sf::Color couleur){shape->SetFillColor(couleur);};
        inline void Next();

    protected:
        sf::Shape* shape;
};

void Body::Next()
{
     b2Vec2 origine = body->GetPosition();
     shape->SetPosition(toPix(origine.x),-toPix(origine.y));
     shape->SetRotation(-toDeg(body->GetAngle()));
};

#endif

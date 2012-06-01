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
        inline void SetColor(sf::Color couleur){shape->SetFillColor(couleur);};
        virtual void Draw(sf::RenderTarget& window){window.Draw(*shape);};

        void Next();

    protected:
        sf::Shape* shape;
};



#endif

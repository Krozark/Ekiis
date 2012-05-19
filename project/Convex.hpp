#ifndef CONVEX_HPP
#define CONVEX_HPP

#include "body.hpp"

class ConvexBody : public Body
{
    public:
        ConvexBody (float posx,float posy,const sf::Vector2f *vertices,int vertexCount,b2BodyType type = b2_dynamicBody);
};

#endif

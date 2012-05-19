#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "body.hpp"

class CircleBody : public Body
{
    public:
        CircleBody (float posx,float posy,float rayon,b2BodyType type = b2_dynamicBody);
};

#endif

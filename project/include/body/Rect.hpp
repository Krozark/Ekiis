#ifndef RECT_HPP
#define RECT_HPP

#include "body.hpp"

class RectBody : public Body
{
    public:
        RectBody (float posx,float posy,float sizex,float sizey,b2BodyType type = b2_dynamicBody);
};

#endif

#ifndef NOTDRAWABLECIRCLE_HPP
#define NOTDRAWABLECIRCLE_HPP

#include "NotDrawableBody.hpp"

class NotDrawableCircleBody : public NotDrawableBody
{
    public:
        NotDrawableCircleBody (float posx,float posy,float rayon,b2BodyType type = b2_dynamicBody);
};


#endif

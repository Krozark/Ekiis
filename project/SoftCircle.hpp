#ifndef SOFTCIRCLE_HPP
#define SOFTCIRCLE_HPP

#include "body.hpp"

class SoftCircle : public Body
{

    public :
        SoftCircle(float posx,float posy,float rayon);

    private:
        const unsigned int nb_circles;
        Body** bodys;


};

#endif



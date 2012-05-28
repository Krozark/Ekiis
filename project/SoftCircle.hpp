#ifndef SOFTCIRCLE_HPP
#define SOFTCIRCLE_HPP

#include "body.hpp"

class SoftCircle : public Body // , Sprite
{

    public :
        SoftCircle(float posx,float posy,float rayon);
        void Draw(sf::RenderTarget& window);
        ~SoftCircle();

    private:
        const unsigned int nb_circles;
        Body** bodys;

        struct fpoint{
            float x,y;
        };
        fpoint* textcoord;


};

#endif



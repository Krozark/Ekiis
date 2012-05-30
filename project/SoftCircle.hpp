#ifndef SOFTCIRCLE_HPP
#define SOFTCIRCLE_HPP

#include "body.hpp"

class SoftCircle : public Body // , Sprite
{

    public :
        SoftCircle(float posx,float posy,float rayon,float duretee=0.5f,const unsigned int quality=24);
        void Draw(sf::RenderTarget& window);
        inline void SetTexture(GLuint t){texture =t;}
        ~SoftCircle();

    private:
        const unsigned int nb_circles;
        Body** bodys;

        struct fpoint{
            float x,y;
        };
        fpoint* textcoord;
        GLuint texture;


};

#endif



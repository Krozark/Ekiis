#ifndef SOFTCIRCLE_HPP
#define SOFTCIRCLE_HPP

#include "body.hpp"
#include "NotDrawableCircle.hpp"

/***************************************
*   Attention avec l'utilisation de
    cette classe.
    Le moteur physique n'est pas fait
    pour gérer les corps mous.
    Par concéquent, cela coute beaucoup en
    ressources.
    Elle est totalement inutile si la
    duretée est mise à 1
    Utiliser CircleBody à la place quand
    cela est possible.
******************************************/

class SoftCircle : public Body // , Sprite
{

    public :
        SoftCircle(float posx,float posy,float rayon,float duretee=0.5f,const unsigned int quality=24);
        void Draw(sf::RenderTarget& window);
        inline void SetTexture(GLuint t){texture =t;}
        ~SoftCircle();

    private:
        const unsigned int nb_circles;
        NotDrawableCircleBody** bodys;

        struct fpoint{
            float x,y;
        };
        fpoint* textcoord;
        GLuint texture;


};

#endif


